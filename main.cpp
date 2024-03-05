/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "./header/heap.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

int main(int argc, char* argv[])
{
    // Create an instance of the Allocator class
    Allocator allocator;

    // Allocate memory
    char* ptr = (char*)allocator.malloc(1);
    Log("Allocated 1 byte of memory at: " << (void*)ptr);

    // Write to memory
    *ptr = 'A';
    Log("Value at " << (void*)ptr << ": " << *ptr);

    // Free memory
    allocator.free(ptr);

    // Allocate array of integers
    int* arr = (int*)allocator.malloc(10 * sizeof(int));
    Log("Allocated 10 integers at: " << (void*)arr);

    // Write to array
    for(int i = 0; i < 10; ++i) { arr[i] = i; }

    // Print array
    for(int i = 0; i < 10; ++i) { Log("Value at " << (void*)&arr[i] << ": " << arr[i]); }

    allocator.free(arr);

    // End program
    return 0;
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
