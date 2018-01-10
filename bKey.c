#include <stdio.h>
#include <stdlib.h>

#define INDEX 0
#define NOTFOUND -1

void makeArr (int *arr, int len);
void printArr (int *arr, int len);

int isFound (int i, int target, int start, int end, int *arr, int *key);
/* function for executing binary search binary search if target found */

int main (void) {

	int *arr, *key, i, target, start, end, len, keyLen;
	start = INDEX;

	scanf("%d", &len);
	arr = (int*) calloc(len, sizeof(int));
	end = len - 1;
	makeArr(arr, len);

	scanf("%d", &keyLen);
	key = (int*) calloc(keyLen, sizeof(int));

	// printf("\nSelect target integer\n");

	for (i = 0; i < keyLen; i++) {
		scanf("%d", &target);
		isFound(i, target, start, end, arr, key);
	}

	printArr(key, keyLen);

	free(arr);
	free(key); 

	return 0;

}


void makeArr (int *arr, int len) {

	int i, scan;

	for (i = 0; i < len; ++i) {
		scanf("%d", &scan);
		arr[i] = scan;
	}

}

void printArr (int *arr, int len) {

	int i;

	for (i = 0; i < len; ++i) {
		printf(" %d ", arr[i]);;
	}

}

int isFound (int i, int target, int start, int end, int *arr, int *key) {

	int current;
	current = (start + end) / 2;
	/*b search always begins in centre of array */

	if (start > end) {
		//base case for exiting array if element not found. narrowed & start = end on next call
		key[i] = NOTFOUND;
		return 0;
	}

	if (target == arr[current]) {
		key[i] = current;
		return 1;
	}

	if (target < arr[current]) {
		// printf("\nGo lower. Start = %d, End = %d\n", start, end);
		isFound (i, target, start, current - 1, arr, key);
		/*begins search from 0 - prev number - 1 */
	}

	if (target > arr[current]) {
		// printf("\nGo higher. Start = %d, End = %d\n", start, end);
		isFound (i, target, current+1, end, arr, key);
		/* begins search from prev number + 1 - end */
	}

	return 0;

}
