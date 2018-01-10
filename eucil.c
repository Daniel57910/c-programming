#include <stdio.h>
#include <math.h>

typedef unsigned long long int NUM;

NUM findHCF (NUM a, NUM b);

int main (void) {

	NUM a, b, HCF, LCF;
	HCF = 0;
	scanf("%llu %llu", &a, &b);

	//printf("%llu %llu\n", a, b);

	HCF = findHCF(a, b);
	printf("%llu\n", HCF);

	return 0;
}

NUM findHCF (NUM a, NUM b) {
 
	// elegant recursion

	if (b == 0) {
		return a;
	}

	return findHCF(b, a % b);

	/*
	first solution
	
	NUM temp;
 
	if (a % b == 0) {
    	return b;
    } 

    temp = a % b;
    a = b;
    b = temp;

    prNUMf("A: %llu B: %llu TMP: %llu\n", a, b, temp);
	return findHCF(a, b);

	*/

}