#include <stdio.h>
#include <stdlib.h>

#define INDEX 0
#define MAJ 1
#define NOMAJ 0

void makeArr (int *nums, int end);

void printArray (int *nums, int end);

int mergeArray (int start, int end, int *nums);
/* main function for merging array. recursively called n / 2 */

void mergeSort (int start, int mid, int end, int *nums);
/*used to recursively divide main array /2 */

void divArray (int start, int end, int *nums, int *arrHalf);
/*function for copying lSide -> lArray & rSide -> rArray */

void reMerge (int *i, int *j, int *k, int lMax, int rMax, int *lSide, int *rSide, int *nums);

int findTurning (int *arrHalf, int target, int startPoint, int midPoint, int *turnPoint);

int main (void) {

	int *nums;
	int start, end, mid, target, turnPoint, majCheck;

	start = INDEX;
	scanf("%d", &end);
	mid = end / 2;

	nums = (int*) calloc(end, sizeof(int));
	
	makeArr(nums, end);
	// printArray(nums, end);
	mergeArray(start, end - 1, nums);
	// printArray(nums, end);
	target = nums[mid];

	findTurning(nums, target, start, mid, &turnPoint);

	majCheck = turnPoint + mid;
	// printf("Turn point is %d", turnPoint);

	if (nums[turnPoint] == nums[majCheck]) {
		printf("%d", MAJ);
	}

	else {
		printf("%d", NOMAJ);
	}

	free(nums);

	return 0;

}

void makeArr (int *nums, int end) {

	int scan, i;
	
	for (i = INDEX; i < end; i++) {
		scanf("%d", &scan);
		nums[i] = scan;
	}

}

int mergeArray (int start, int end, int *nums) {

	int mid;

	if (start < end) {
		
		mid = (start + end) / 2;
		mergeArray(start, mid, nums);
		mergeArray(mid + 1, end, nums);
		mergeSort(start, mid, end, nums);
	}

	return 0;

}

void mergeSort (int start, int mid,  int end, int *nums) {

	
	int ltEnd, rtEnd, i, j, k;

	i = INDEX;
	j = INDEX;
	k = start;
	ltEnd = mid - start + 1;
	rtEnd = end - mid;

	int lSide[ltEnd], rSide[rtEnd];

	divArray(start, ltEnd, nums, lSide);
	divArray(mid + 1, rtEnd, nums, rSide);
	reMerge(&i, &j, &k, ltEnd, rtEnd, lSide, rSide, nums);

}

void divArray (int start, int end,  int *nums, int *arrHalf) {

	int i;

	for (i = INDEX; i < end; i++) {
		arrHalf[i] = nums[i + start];
	}

}


void reMerge (int *i, int *j, int *k, int lMax, int rMax, int *lSide, int *rSide, int *nums) {

	while (*i < lMax && *j < rMax) {

		if (lSide[*i] <= rSide[*j]) {
			nums[*k] = lSide[*i];
			*i = *i + 1;
		}
		else {
			nums[*k] = rSide[*j];
			*j = *j + 1;
		}
		*k = *k + 1;
		/*k index of main array */
	}

	while (*i < lMax) {
		nums[*k] = lSide[*i];
		*i = *i + 1;
		*k = *k + 1;
	}

	while (*j< rMax) {
		nums[*k] = rSide[*j];
		*j = *j + 1;
		*k = *k + 1;
	}
	
}


void printArray (int *nums, int end) {

	int i;

	for (i = INDEX; i < end; i++) {
		printf(" %d ", nums[i]);
	}

}

int findTurning (int *arrHalf, int target, int startPoint, int midPoint, int *turnPoint) {

	int half;

	if (arrHalf[midPoint] == target && arrHalf[midPoint - 1] < target) {
		// printf("Inflection point found at co-ord %d", midPoint);
		*turnPoint = midPoint;
		return 1;
	}

	if (startPoint < midPoint) {

		if (arrHalf[midPoint] < target && arrHalf[midPoint + 1] < target) {
			findTurning(arrHalf, target, startPoint + 1, midPoint, turnPoint);
		}

		if (arrHalf[midPoint] == target && arrHalf[midPoint - 1] == target) {
			findTurning(arrHalf, target, startPoint, midPoint - 1, turnPoint);
		}

	}

	return 0;

}


