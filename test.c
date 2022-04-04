#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define FIXED_POINT_FRACTIONAL_BITS 5
typedef int16_t fixed_point_t;
fixed_point_t double_to_fixed(double input);
inline fixed_point_t double_to_fixed(double input) {return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));}

fixed_point_t fixed_addition(fixed_point_t input1, fixed_point_t input2);
inline fixed_point_t fixed_addition(fixed_point_t input1, fixed_point_t input2) {
   return (fixed_point_t)(input1 + input2);
}

// int sigmoid(int x) { return 1 / (1 + exp(-x)); }

int main() {
   fixed_point_t e;
   e = double_to_fixed(2.71828);
   fixed_point_t result;
   result = fixed_addition(-e, -e);
   printf("value of e+e is %x\n", result);
   return 0;
}