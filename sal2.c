#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 3 // number <= 10^3
#define DIV2 10
#define MAXNO 1001
#define DIV3 MAXNO - 1 * 10

void fillArray (int *makeArr, int arrLen);
/* function for getting array */

void intToArray (int *makeArr, int arrLen);
/* function for converting integer to array */

int appendNos (int *arr, int pos, int pos2);
/* function for evaluating corner case modulus == modulus a[pos] != a[pos2] */

void printArr (int *makeArr, int arrLen);
/* function for printing array */

int main (void) {

	int userNum, *arr;

	scanf("%d", &userNum);
	arr = (int*) calloc(userNum, sizeof(int));

	fillArray(arr, userNum);
	printArr(arr, userNum);
	intToArray(arr, userNum);
	printArr(arr, userNum);

	free(arr);

	return 0;

}

void fillArray (int *makeArr, int arrLen) {

	int i, scan;

	for (i = 0; i < arrLen; i++) {
		scan = rand () % 100;
		makeArr[i] = scan;
	}

}

void intToArray (int *makeArr, int arrLen) {

	int i, j, temp, append, prepend;
	append = 0;
	prepend = 0;

	for (i = 0; i < arrLen; i++) {
		for (j = arrLen - 1; j > i; j--) {
			append = appendNos(makeArr, i, j);
			prepend = appendNos(makeArr, j, i);
			if (prepend > append) {
				temp = makeArr[i];
				makeArr[i] = makeArr[j];
				makeArr[j] = temp;
			}
		}
	}

}

void printArr (int *makeArr, int arrLen) {

	int i;

	for (i = 0; i < arrLen; i++) {
		printf(" %d ", makeArr[i]);
	}

	printf("\n");

}

int appendNos (int *arr, int pos, int pos2) {

	int pow;
	pow = 10;

	/*
	pos1 = 65
	pos2 = 389
	while pos2 > 10, 10^number of exponents.
	pos * 10^number of exponents + pos2 
	65 * 10^3 + 389 = 65389
	389 * 10^2 + 65 = 38965
	*/

	while (arr[pos2] >= pow) {
		pow*=10;
	} 

	return pow * arr[pos] + arr[pos2];
}


