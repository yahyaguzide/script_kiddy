#include <stdlib.h>
// #include <stdio.h>

/**************************************************
//  NormDenorm_ordinalData
//
// date: 31.10.2019
// name: Yahya Guezide
// Simple algo to Norm and Denomr Ordenal data
//
***************************************************/

int main( int argc, char **argv ){

    return 0;

}

float Norm( int nlow, int nhigh, int index, int length ){
	return (float)(nhigh - nlow)((float)index/length) + nlow;
}

int Denorm( int nlow, int nhigh, float nindex, int length ){
	return (nindex - nlow)*length/(float)(nhigh - nlow)
}
