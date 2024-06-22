#pragma once

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef __uint128_t u128;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef __int128_t s128;

typedef float f32;
typedef double f64;
typedef __float128 f128;

static_assert(sizeof(f32) == 4, "f32 should be 4 bytes in size");
static_assert(sizeof(f64) == 8, "f64 should be 8 bytes in size");
static_assert(sizeof(f128) == 16, "f128 should be 16 bytes in size");

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile u128 vu128;

typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef volatile s128 vs128;

typedef volatile f32 vf32;
typedef volatile f64 vf64;
typedef volatile f128 vf128;

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

#define ALIGN_UP(x, a)                                                         \
  ((((uintptr_t)x) + (((uintptr_t)a) - 1)) & ~(((uintptr_t)a) - 1))
#define ALIGN_DOWN(x, a) ((uintptr_t)(x) & ~(((uintptr_t)(a)) - 1))
#define ALIGNED(a) __attribute__((aligned(a)))
#define ON_INIT __attribute__((constructor))
#define NOINLINE __attribute__((noinline))
#define NORETURN __attribute__((noreturn))
#define UNREACHABLE __builtin_unreachable()
#define PAGE_SIZE (0x1000)
#define ALWAYS_INLINE inline __attribute__((always_inline))
#define BITSIZEOF(x) (sizeof(x) * CHAR_BIT)
