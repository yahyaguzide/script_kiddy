#include <math.h>
#include <stdlib.h>

long long getHash( char *s ){
    const int p = 53;
    const int m = pow(1, 9) + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for(; *s ; s++ ){
        if( *s < 'A' )
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        else
            hash_value = (hash_value + (c - 'A' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
