/**
 * @file defines.h
 * @author Daniel Pozas (daniel.hazker@gmail.com)
 * @brief This file contains global type definitions which are used
 * @note Numeric types are asserted statically to gurantee expected size.
 * @version 1.0
 * @date 2025-04-27
 *
 * @copyright Hazker-GDE is Copyright (©) Daniel Pozas 2024-2025
 *
 */

#pragma once

/* Unsigned int types */
/** @brief Unsigned 8-bit integer */
typedef unsigned char u8;
/** @brief Unsigned 16-bit integer */
typedef unsigned short u16;
/** @brief Unsigned 32-bit integer */
typedef unsigned int u32;
/** @brief Unsigned 64-bit integer */
typedef unsigned long long u64;

/* Signed int types */
/** @brief Signed 8-bit integer */
typedef signed char i8;
/** @brief Signed 16-bit integer */
typedef signed short i16;
/** @brief Signed 32-bit integer */
typedef signed int i32;
/** @brief Signed 64-bit integer */
typedef signed long long i64;

/* Floating point types */
/** @brief 32-bit floating point number */
typedef float f32;
/** @brief 64-bit floating point number */
typedef double f64;

/* Boolean Types */
/** @brief 32-bit boolean type, used for APIs which require it */
typedef int b32;
#ifndef __cplusplus
/** @brief 8-bit boolean type */
typedef _Bool b8;
#else
/** @brief 8-bit boolean type */
typedef bool b8;
#endif

/** @brief A range, typically of memory */
typedef struct range {
    /** @brief The offset in bytes. */
    u64 offset;
    /** @brief The size in bytes. */
    u64 size;
} range;

/* Properly define static assertions */
#if defined(__clang__) || defined(__gcc__)
/** @brief Static assertion */
#define STATIC_ASSERT _Static_assert
#else
/** @brief Static assertion */
#define STATIC_ASSERT _static_assert
#endif

/* NOTE: Removed assertions */

#ifndef __cplusplus
/* Defined only for .c files
 This macros will be ignored for .cpp files */

/** @brief True.*/
#define true 1
/** @brief False. */
#define false 0

#define _extern_c_start
#define _extern_c_end

#define _cpp_code 0
#else
#define _extern_c_start  extern "C" {
#define _extern_c_end    }

#define _cpp_code 1
#endif

#ifndef null
/** @brief null pointer. */
#define null 0
#endif

/**
 * @brief Any id set to this should be considered invalid,
 * and not actually pointing to a real object.
 */
#define INVALID_ID_U64 18446744073709551615UL
#define INVALID_ID 4294967295U
#define INVALID_ID_U16 65535U
#define INVALID_ID_U8 255U

/* Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define HPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
//Linux OS
#define HPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define HPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
//Catch anything not caught by the above
#define HPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
//Posix
#define HPLATFORM_POSIX 1
#elif __APPLE__
//Apple platforms
#define HPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
//IOS Simulator
#define HPLATFORM_IOS 1
//iOS Device
#elif TARGET_OS_MAC
//Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform"
#endif*/

/* Default platform */
#define HPLATFORM_WINDOWS 1

#ifdef HEXPORT
/* Exports */
#ifdef _MSC_VER
/** @brief Import/export qualifier */
#define HAPI __declspec(dllexport)
#else
/** @brief Import/export qualifier */
#define HAPI __attribute__((visibility("default")))
#endif
#else
/* Imports */
#ifdef _MSC_VER
/** @brief Import/export qualifier */
#define HAPI __declspec(dllimport)
#else
/** @brief Import/export qualifier */
#define HAPI
#endif
#endif

/* Inlining */
#ifdef _MSC_VER
/** @brief Inline qualifier */
#define HINLINE __forceinline

/** @brief No-inline qualifier */
#define HNOINLINE __declspec(noinline)
#else
/** @brief Inline qualifier */
#define HINLINE /* static inline */

/** @brief No-inline qualifier */
#define HNOINLINE
#endif

/**
 * @brief Clamps value to a range of min and max (inclusive).
 * @param value The value to be clamped.
 * @param _min The minimum value of the range.
 * @param _max The maximum value of the range.
 * @returns The clamped value.
 */
#define HCLAMP(value, _min, _max) ((value <= _min) ? _min : (value >= _max) ? _max : value);

/** @brief Gets the number of bytes from amount of gibibytes (GiB) (1024*1024*1024) */
#define GIBIBYTES(amount) (amount * 1024 * 1024 * 1024)
/** @brief Gets the number of bytes from amount of mebibytes (MiB) (1024*1024) */
#define MEBIBYTES(amount) (amount * 1024 * 1024)
/** @brief Gets the number of bytes from amount of kibibytes (KiB) (1024) */
#define KIBIBYTES(amount) (amount * 1024)

/** @brief Gets the number of bytes from amount of gigabytes (GB) (1000*1000*1000) */
#define GIGABYTES(amount) (amount * 1000 * 1000 * 1000)
/** @brief Gets the number of bytes from amount of megabytes (MB) (1000*1000) */
#define MEGABYTES(amount) (amount * 1000 * 1000)
/** @brief Gets the number of bytes from amount of kilobytes (KB) (1000) */
#define KILOBYTES(amount) (amount * 1000)

/*HINLINE u64 get_aligned(u64 operand, u64 granularity) {
    return ((operand + (granularity - 1)) & ~(granularity - 1));
}

HINLINE range get_aligned_range(u64 offset, u64 size, u64 granularity) {
    return (range){get_aligned(offset, granularity), get_aligned(size, granularity)};
}*/
