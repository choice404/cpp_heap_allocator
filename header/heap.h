/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#include <iostream>

#pragma once

#define MAX_HEAP_SIZE 1000000
#define HEAP_ALLOC_SIZE 1024
#define HEAP_FREE_SIZE 1024

struct HeapBlock
{
    void* start;
    size_t size;
};

struct Heap
{
    char heap[MAX_HEAP_SIZE] = {0};
    HeapBlock freeBlocks[HEAP_FREE_SIZE];
    HeapBlock allocBlocks[HEAP_ALLOC_SIZE];
    size_t freeBlockCount = 1;
    size_t allocBlockCount = 0;
};

class Allocator
{
public:
    Allocator();
    ~Allocator();
    void* malloc(size_t size);
    void* free(void* ptr);

private:
    Heap* heap;
    void garbageCollect();
};

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * cpp_heap
 * A very simple implementation of heap memory allocation and freeing.
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
