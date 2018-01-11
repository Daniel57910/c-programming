#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDistance (char *st1, char *st2, int len1, int len2);

void printTable (int distanceTable[MAX][MAX], int len1, int len2);

void makeTable (int distanceTable[MAX][MAX], int len1, int len2);

int checkMin (int rem, int add, int rep);

int main (void) {

	int distance, len1, len2;
	char st1[MAX], st2[MAX];

	//printf("Enter string one\n");
	scanf("%s", st1);
	//printf("Enter string two\n");
	scanf("%s", st2);

	len1 = strlen(st1);
	len2 = strlen(st2);

	//printf("ST1 len is %d\n", len1);
	//printf("ST2 len is %d\n", len2);

	distance = getDistance(st1, st2, len1, len2);

	printf("%d\n", distance);

	return 0;
}

int getDistance (char *st1, char *st2, int len1, int len2) {

	int i, j, rem, add, rep, match, trueMin, run1, run2, arr1, arr2;
	run1 = len1 + 1;
	run2 = len2 + 1;
	//printf("Len 1 is %d. Len 2 is %d\n", run1, run2);
	int distanceTable[MAX][MAX];

	makeTable(distanceTable, run1, run2);
	/*sets table values for i == 0 & j == 0 to j & i */

	//printTable(distanceTable, run1, run2);

	for (arr1 = 0, i = 1; i < run1 && arr1 < len1; i++, arr1++) {
		for (arr2 = 0, j = 1; j < run2 && arr2 < len2; j++, arr2++) {

				rem = 1 + distanceTable[i -1][j];
				add = 1 + distanceTable[i][j - 1];
				rep = 1 + distanceTable[i - 1][j - 1];
				match = distanceTable[i - 1][j - 1];

			if (st1[arr1] != st2[arr2]) {
				trueMin = checkMin(rem, add, rep);
				//printf("Distance between %c and %c is %d\n", st1[arr1], st2[arr2], trueMin);
				distanceTable[i][j] = trueMin;
			}

			if (st1[arr1] == st2[arr2]) {
				trueMin = checkMin (rem, add, match);
				//printf("Distance between %c == %c is %d\n", st1[arr1], st2[arr2], trueMin); 
				distanceTable[i][j] = trueMin;
			}
		}
	/*
	printf("\n");
	printTable(distanceTable, run1, run2);
	*/

	}

	//printf("I is %d. J is %d. Distance is %d\n", i, j, distanceTable[len1][len2]);

	return distanceTable[i - 1][j - 1];

}

int checkMin (int rem, int add, int rep) {

	if (rem < add && rem < rep) {
		return rem;
	}

	else if (add < rep) {
		return add;
	}

	else {
		return rep;
	}

}

void makeTable (int distanceTable[MAX][MAX], int len1, int len2) {

	int i, j;

	distanceTable[0][0] = 0;

	for (i = 1, j = 0; i < len1; i++) {
		distanceTable[i][j] = i;
	}

	for (i = 0, j = 1; j < len2; j++) {
		distanceTable[i][j] = j;
	}

	/*for (i = 1; i < len1; i++) {
		for (j = 1; j < len2; j++) {
			distanceTable[i][j] = j;
		}
	}*/
}

void printTable (int distanceTable[MAX][MAX], int len1, int len2) {

	int i, j;

	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			printf(" %d ", distanceTable[i][j]);
		}
		printf("\n");
	}

}