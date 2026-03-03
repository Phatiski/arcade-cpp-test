
#include "pxt.h"

namespace cpp_test {
/*
    int imul(int x, int b) {
        return x * b;
    };
*/
    //%
    long imul(long a, long b) {
        return a * b;
    };
    
    //%
    float q_rsqrt( float number ) {
    	long i;
    	float x2, y;
    	const float threehalfs = 1.5F;
    
    	x2 = number * 0.5F;
    	y  = number;
    	i  = * ( long * ) &y;                       // evil floating point bit level hacking
    	i  = 0x5f3759df - ( i >> 1 );               // magic number?
    	y  = * ( float * ) &i;
    	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    
    	return y;
    }

    //%
    float q_rcp(float x) {
        // reinterpret float as int
        long i = *(long*)&x;
    
        // magic constant for reciprocal (approx)
        i = 0x7EF311C3 - i;
    
        // reinterpret back to float
        float y = *(float*)&i;
    
        // Newton-Raphson refinement 1 time
        y = y * (2.0f - x * y);
    
        return y;
    }
}
