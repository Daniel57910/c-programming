/* Dynamic solution to primitive calculator problem */

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

void makeArr (int len, int *arr);
/*function for making array */

void printArr (int len, int *arr);

void getDistance (int len, int *numbers, int *distance);
/*function for checking edit distance */

int getRoute (int len, int *distance, int *route);
/*function for identifying fastest edit route using edit distance */

void printRoute (int len, int *route);
/*function for printing number route */

int checkMin (int min1, int min2);
/*function for checking whether distance [i - 1] < distance 1 + [i / 3 || i < 2] */

int main (void) {

	int num, routeLen;
	int *numArray, *distance, *route;
	/*arrays for substate 0 - number, edit distance, and route */
	//printf("Enter a number\n");
	scanf("%d", &num);
	num++;

	numArray = (int*) calloc(num, sizeof(int));
	distance = (int*) calloc(num, sizeof(int));
	route = (int*) calloc(num, sizeof(int));

	//printf("Number array\n");
	makeArr(num, numArray);
	makeArr(num, distance);

	//printArr(num, numArray);

	getDistance(num, numArray, distance);
	routeLen = getRoute(num, distance, route);

	printf("%d\n", routeLen - 1);
	/*1st integer 1 not considered in range */

	printRoute(routeLen, route);

	free(numArray);
	free(distance);
	free(route);
}

void getDistance (int len, int *numbers, int *distance) {

	int options[MAX] = {1, 2, 3};
	int i, j, current, min1, min2, trueMin;

	for (i = 0; i < MAX; i++) {
		current = options[i];
		//printf("Current is %d\n", current);
		for (j = 1; j < len; j++) {
			//printf("j is %d\n", j);

			if (current == numbers[j]) {
				distance[j] = 1;
			}

			else if (current < numbers[j]) {

				if (numbers[j] % 3 == 0) {
					min1 = distance[j];
					min2 = 1 + distance[j / 3];
					trueMin = checkMin(min1, min2);
					distance[j] = trueMin;
				}

				else if (numbers[j] % 2 == 0) {
					min1 = distance[j];
					min2 = 1 + distance[j / 2];
					trueMin = checkMin(min1, min2);
					distance[j] = trueMin;
				}
			}
		}

	//printf("Edit table: \n");
	//printArr(len, distance);
	} 

}

int getRoute (int len, int *distance, int *route) {

	int runLen, i, min1, min2;
	int options[MAX] = {1, 2, 3};
	runLen = len - 1;
	i = 0;
	//printf("\nLen is %d\n", runLen);

	while (runLen > 0) {
		route[i] = runLen;
		//printf("RunLen is %d\n", route[i]);

		/*edit table lookup whether distance - 1 or distance / 3 or distance / 2 produces fastest route */
		if (runLen % 3 == 0) {
			min1 = distance[runLen - 1];
			min2 = distance[runLen / 3];
			
			if (min1 < min2) {
				runLen--;
			}
			else {
				runLen/=3;;
			}

		}

		else if (runLen % 2 == 0) {
			min1 = distance[runLen - 1];
			min2 = distance[runLen / 2];
			
			if (min1 < min2) {
				runLen--;
			}
			else {
				runLen/=2;;
			}

		}

		else if (runLen - 1 >= 0) {
			runLen--;
			
		}
		i++;
	}

	//printArr(i, route);

	return i;

}

int checkMin (int min1, int min2) {

	if (min1<= min2) {
		return min1;
	}

	else {
		return min2;
	}
}

void makeArr (int len, int *arr) {

	int i;

	for (i = 0; i < len; i++) {
		arr[i] = i;
	}
}

void printArr (int len, int *arr) {

	int i;

	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

void printRoute (int len, int *arr) {

	//printf("Route is %d\n", len);
	int i;  

	for (i = len - 1; i >=0; i--) {
		printf("%d ", arr[i]);
	}
}