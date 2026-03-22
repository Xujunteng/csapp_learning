#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define q1 1

#define x1 1.40129846e-45f
#define y1 8.40779079e-45f

#define x2 0x1.0p+4f
#define y2 0x1.000002p+4f

static int32_t float_to_ordered_int(float f)
{
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));

    if (bits & 0x80000000u) {
        return (int32_t)(0x80000000u - bits);
    }
    return (int32_t)(bits + 0x80000000u);
}

bool AlmostEqualULP(float x, float y)
{
    if (isnan(x) || isnan(y)) {
        return false;
    }
    if (isinf(x) || isinf(y)) {
        return x == y;
    }

    int64_t ix = (int64_t)float_to_ordered_int(x);
    int64_t iy = (int64_t)float_to_ordered_int(y);
    int64_t diff = ix - iy;
    if (diff < 0) {
        diff = -diff;
    }

    return diff <= 4;
}