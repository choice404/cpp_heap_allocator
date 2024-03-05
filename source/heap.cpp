/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/heap.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

Allocator::Allocator()
{
    heap = new Heap();
    heap->freeBlocks[0].start = (void*)heap->heap;
    heap->freeBlocks[0].size = MAX_HEAP_SIZE;
}

Allocator::~Allocator()
{
    Log("On program exit" << std::endl << "Block count: " << heap->allocBlockCount << std::endl << "Free block count: " << heap->freeBlockCount);
    delete heap;
}

void* Allocator::malloc(size_t size)
{
    for(int i = 0; i < heap->freeBlockCount; ++i)
    {
        if(heap->freeBlocks[i].size >= size)
        {
            char* ptr = (char*)heap->freeBlocks[i].start;
            heap->allocBlocks[heap->allocBlockCount].start = ptr;
            heap->allocBlocks[heap->allocBlockCount].size = size;
            ++heap->allocBlockCount;
            heap->freeBlocks[i].start = (void*)((char*)heap->freeBlocks[i].start + size);
            heap->freeBlocks[i].size -= size;
            return ptr;
        }
    }
    Log("Out of memory");
    return nullptr;
}

void* Allocator::free(void* ptr)
{
    for(int i = 0; i < heap->allocBlockCount; ++i)
    {
        if(heap->allocBlocks[i].start == ptr)
        {
            bool check = false;
            for(int j = 0; j < heap->freeBlockCount; ++j)
            {
                if((char*)heap->freeBlocks[j].start + heap->freeBlocks[j].size == ptr)
                {
                    heap->freeBlocks[j].size += heap->allocBlocks[i].size;
                    check = true;
                }
                if((char*)heap->freeBlocks[j].start == (char*)heap->allocBlocks[i].start + heap->allocBlocks[i].size)
                {
                    heap->freeBlocks[j].start = heap->allocBlocks[i].start;
                    heap->freeBlocks[j].size += heap->allocBlocks[i].size;
                    check = true;
                }
            }
            if(check)
            {
                heap->allocBlocks[i].start = nullptr;
                heap->allocBlocks[i].size = 0;
                --heap->allocBlockCount;
                return ptr;
            }
            heap->freeBlocks[heap->freeBlockCount].start = ptr;
            heap->freeBlocks[heap->freeBlockCount].size = heap->allocBlocks[i].size;
            ++heap->freeBlockCount;
            --heap->allocBlockCount;
            heap->allocBlocks[i].start = nullptr;
            heap->allocBlocks[i].size = 0;
            return ptr;
        }
    }
    Log("Invalid pointer");
    return nullptr;
}

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * cpp_heap
 * A very simple implementation of heap memory allocation and freeing.
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
