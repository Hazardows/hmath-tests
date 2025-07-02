#include "hmemory.h"

void* Hallocate(u64 size, memory_tag tag) {
    return platform_allocate(size, false);
}

void Hfree(void* block, u64 size, memory_tag tag) {
    platform_free(block, false);
}

void* Hzero_memory(void* block, u64 size) {
    return platform_zero_memory(block, size);
}

void* Hcopy_memory(void* dest, const void* source, u64 size) {
    return platform_copy_memory(dest, source, size);
}

void* Hset_memory(void* dest, i32 value, u64 size) {
    return platform_set_memory(dest, value, size);
}
