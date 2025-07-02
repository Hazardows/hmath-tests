#include "platform.h"

// Windows platform layer
#if HPLATFORM_WINDOWS

#include <stdio.h>

#include <windows.h>
#include <windowsx.h> // param input extraction

// For surface creation

typedef struct platform_state {
    HINSTANCE hInstance;
    HWND hWnd;
    //VkSurfaceKHR surface;
} platform_state;

// Clock
static f64 clock_frequency;
static LARGE_INTEGER start_time;

static platform_state* state_ptr;

LRESULT CALLBACK win32_process_message(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void clock_setup() {
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    clock_frequency = 1.0 / (f64)frequency.QuadPart;
    QueryPerformanceCounter(&start_time);
}

// Removed plat_start/shutdown

void* platform_allocate(u64 size, b8 aligned) {
    return malloc(size);
}

void platform_free(void* block, b8 aligned) {
    free(block);
}

void* platform_zero_memory(void* block, u64 size) {
    return memset(block, 0, size);
}

void* platform_copy_memory(void* dest, const void* source, u64 size) {
    return memcpy(dest, source, size);
}

void* platform_set_memory(void* dest, i32 value, u64 size) {
    return memset(dest, value, size);
}

f64 platform_get_absolute_time() {
    if (!clock_frequency) {
        clock_setup();
    }

    LARGE_INTEGER now_time;
    QueryPerformanceCounter(&now_time);
    return (f64)now_time.QuadPart * clock_frequency;
}

void platform_sleep(u64 ms) {
    Sleep(ms);
}

i32 platform_get_processor_count() {
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    //HINFO("%i processor cores detected.", sysinfo.dwNumberOfProcessors);
    printf("%i processor cores detected.", sysinfo.dwNumberOfProcessors);
    return sysinfo.dwNumberOfProcessors;
}

#endif
