/**
 * @file platform.h
 * @author Daniel Pozas (daniel.hazker@gmail.com)
 * @brief This file contains the platform layer, or at least the interface to it.
 * Each platform should provide its own implementation of this in a .c file, and
 * should be compiled exclusively of the rest.
 * @version 1.0
 * @date 2025-04-26
 *
 * @copyright Hazker-GDE is Copyright (©) Daniel Pozas 2024-2025
 *
 */

#pragma once

#include "../defines.h"

_extern_c_start

/**
  * @brief Performs platform-specific memory allocation of the given size.
  *
  * @param size The size of the allocation in bytes.
  * @param aligned Indicates if the allocation should be aligned.
  * @return A pointer to a block of allocated memory.
  */
void* platform_allocate(u64 size, b8 aligned);

/**
  * @brief Frees the given block of memory.
  *
  * @param block The block to be freed.
  * @param aligned Indicates if the block of memory is aligned.
  */
void platform_free(void* block, b8 aligned);

/**
  * @brief Performs platform-specific zeroing out of the given block of memory.
  *
  * @param block The block to be zeroed out.
  * @param size The size of data to zero out.
  * @return A pointer to the zeroed out block of memory.
  */
void* platform_zero_memory(void* block, u64 size);

/**
  * @brief Copies the bytes of memory in source to dest, of the given size.
  *
  * @param dest The destination memory block.
  * @param source The source memory block.
  * @param size The size of data to be copied.
  * @return A pointer to the destination block of memory.
  */
void* platform_copy_memory(void* dest, const void* source, u64 size);

/**
  * @brief Sets the bytes of memory to the given value.
  *
  * @param dest The destination block of memory.
  * @param value The value to be set.
  * @param size The size of data to set.
  * @return A pointer to the set block of memory.
  */
void* platform_set_memory(void* dest, i32 value, u64 size);

/**
  * @brief Gets the absolute time since the application started.
  *
  * @return The absolute time since the application started.
  */
f64 platform_get_absolute_time();

/**
  * @brief Sleep on the thread for the provided milliseconds. This blocks the main thread.
  * Should only be used for giving time back to the OS for unused update power.
  * Therefore it is not exported. Times are approximate.
  *
  * @param ms The number of milliseconds to sleep for.
  */
void platform_sleep(u64 ms);

/**
 * @brief Obtains the number of logical processor cores.
 *
 * @return The number of logical processor cores.
 */
i32 platform_get_processor_count();

_extern_c_end
