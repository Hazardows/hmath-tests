#include <iostream>

#include "platform/platform.h"

//#define HUSE_SIMD

#define HMATH_IMPLEMENTATION
#include "math/hmath.h"

using namespace std;

typedef struct hclock {
    f64 start_time;
    f64 elapsed;

    void start() {
        start_time = platform_get_absolute_time();
        elapsed = 0;
    }

    void update() {
        if (start_time != 0) {
            elapsed = platform_get_absolute_time() - start_time;
        }
    }

    void stop() {
        start_time = 0;
    }
} hclock;

int main() {
    cout << "testin' program for hmath\n";

    // Simd status
    string simd_status = "DISABLED";
#ifdef HUSE_SIMD
    simd_status = "ENABLED";
#endif
    cout << "\n\n\tSIMD IS CURRENTLY " << simd_status << "\n\n\n";

    // Program clock
    hclock program_clock;
    program_clock.start();
    // Start Program
    cout << "Program started...\n\n";

    // Operations Clock
    hclock test_clock;

    // vec4 creation
    test_clock.start();
    vec4 test = vec4_create(fhrandom(), fhrandom(), fhrandom(), fhrandom());
    test_clock.update();
    cout << "generated random vec4 test(" << test.x << ", " << test.y << ", " << test.z << ", " << test.w << ")\n";
    cout << "operation create on vec4 test used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // vec4 lenght
    test_clock.start();
    f32 vec4_test_lenght = vec4_length(test);
    test_clock.update();
    cout << "vec4_length(test) -> " << vec4_test_lenght << "\n";
    cout << "operation lenght on vec4 test used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // second vec4 creation
    test_clock.start();
    vec4 test_2 = vec4_create(fhrandom(), fhrandom(), fhrandom(), fhrandom());
    test_clock.update();
    cout << "generated random vec4 test_2(" << test_2.x << ", " << test_2.y << ", " << test_2.z << ", " << test_2.w << ")\n";
    cout << "operation create on vec4 test_2 used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // second vec4 lenght
    test_clock.start();
    f32 vec4_test_2_lenght = vec4_length(test_2);
    test_clock.update();
    cout << "vec4_length(test_2) -> " << vec4_test_2_lenght << "\n";
    cout << "operation lenght on vec4 test_2 used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // vec4 sum
    test_clock.start();
    vec4 addition = vec4_add(test, test_2);
    test_clock.update();
    cout << "vec4_add(test, test_2) -> vec4(" << addition.x << ", " << addition.y << ", " << addition.z << ", " << addition.w << ")\n";
    cout << "operation addition used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // vec4 sub
    test_clock.start();
    vec4 substraction = vec4_sub(test, test_2);
    test_clock.update();
    cout << "vec4_sub(test, test_2) -> vec4(" << substraction.x << ", " << substraction.y << ", " << substraction.z << ", " << substraction.w << ")\n";
    cout << "operation substraction used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // vec4 mul
    test_clock.start();
    vec4 multiplication = vec4_mul(test, test_2);
    test_clock.update();
    cout << "vec4_mul(test, test_2) -> vec4(" << multiplication.x << ", " << multiplication.y << ", " << multiplication.z << ", " << multiplication.w << ")\n";
    cout << "operation multiplication used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // vec4 div
    test_clock.start();
    vec4 divition = vec4_div(test, test_2);
    test_clock.update();
    cout << "vec4_div(test, test_2) -> vec4(" << divition.x << ", " << divition.y << ", " << divition.z << ", " << divition.w << ")\n";
    cout << "operation divition used " << test_clock.elapsed << "s\n\n";
    test_clock.stop();

    // End program
    program_clock.update();
    cout << "Program completed on " << program_clock.elapsed << "s";
}
