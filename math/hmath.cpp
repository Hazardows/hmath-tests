#include "hmath.h"
#include "../platform/platform.h"

#include <math.h>
#include <stdlib.h>

/* ****************************************************************** //
// *  Note that this are here in order to prevent having to import  * //
// *  the entire <math.h> / <cmath> everywhere.                     * //
// ****************************************************************** */

static b8 rand_seeded = false;

b8 is_power_of_2(u64 value) {
    return (value != 0) && ((value & (value - 1)) == 0);
}

f32 hsin(f32 x) {
    return sinf(x);
}

f32 hcos(f32 x) {
    return cosf(x);
}

f32 htan(f32 x) {
    return tanf(x);
}

f32 hacos(f32 x) {
    return acosf(x);
}

f32 hsqrt(f32 x) {
    return sqrtf(x);
}

f32 habs(f32 x) {
    return fabsf(x);
}

i32 hrandom() {
    if (!rand_seeded) {
        srand((u32)platform_get_absolute_time());
        rand_seeded = true;
    }
    return rand();
}

i32 hrandom_in_range(i32 min, i32 max) {
    if (!rand_seeded) {
        srand((u32)platform_get_absolute_time());
        rand_seeded = true;
    }
    return (rand() % (max - min + 1)) + min;
}

f32 fhrandom() {
    return (float)hrandom() / (f32)RAND_MAX;
}

f32 fhrandom_in_range(f32 min, f32 max) {
    return min + ((float)hrandom() / ((f32)RAND_MAX / (max - min)));
}
