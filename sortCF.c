#include <stdio.h>
#include <stdlib.h>

#define INDEX 0
typedef long long int LLI;

void makeArr (LLI *nums, LLI end);

void printArray (LLI *nums, LLI end);

LLI mergeArray (LLI start, LLI end, LLI *nums);
/* main function for merging array. recursively called n / 2 */

LLI mergeSort (LLI start, LLI mid, LLI end, LLI *nums);
/*used to recursively divide main array /2 */

void divArray (LLI start, LLI end, LLI *nums, LLI *arrHalf);
/*function for copying lSide -> lArray & rSide -> rArray */

int main (void) {

	LLI *nums;
	LLI start, end, count;

	start = INDEX;
	scanf("%lld", &end);

	nums = (LLI*) calloc(end, sizeof(LLI));
	
	makeArr(nums, end);
	//printArray(nums, end);
	count = mergeArray(start, end - 1, nums);
	/* to ensure remain in boundaries of array */
	printf("%lld", count);
	//printArray(nums, end);

	free(nums);

	return 0;

}

void makeArr (LLI *nums, LLI end) {

	LLI rnd, i;
	
	for (i = INDEX; i < end; i++) {
		scanf("%lld", &rnd);
		nums[i] = rnd;
	}

}

LLI mergeArray (LLI start, LLI end, LLI *nums) {

	LLI mid, count;
	count = 0;

	if (start < end) {
		
		mid = (start + end) / 2;
		count += mergeArray(start, mid, nums);
		count += mergeArray(mid + 1, end, nums);
		count += mergeSort(start, mid, end, nums);
	}

	//prLLIf("\nCount is %lld\n", count);

	return count;

}

LLI mergeSort (LLI start, LLI mid,  LLI end, LLI *nums) {

	
	LLI ltEnd, rtEnd, i, j, k, invCount;

	i = INDEX;
	j = INDEX;
	k = start;
	ltEnd = mid - start + 1;
	rtEnd = end - mid;
	invCount = 0;

	LLI lSide[ltEnd], rSide[rtEnd];

	divArray(start, ltEnd, nums, lSide);
	divArray(mid + 1, rtEnd, nums, rSide);

	while (i < ltEnd && j < rtEnd) {

		if (lSide[i] <= rSide[j]) {
			nums[k] = lSide[i];
			i++;
			/* lside <= rside nums = lside || nums = rightside
			each array tree sorted using logic  */
		}
		else {
			nums[k] = rSide[j];
			j++;
			invCount+=ltEnd - i; 
			/*invCount returns location of j < i variable and no of merges needed 
			eg 2 9 1 3
			= 1 2 9 3 mid = (4/2) + 1 - i = 2. 2 inversions needed for rSide[1], 1 for rSide[2]
			*/
		}
		k++;
		/*k index of main array */
	}

	while (i < ltEnd) {
		nums[k] = lSide[i];
		i++;
		k++;
	}

	while (j< rtEnd) {
		nums[k] = rSide[j];
		j++;
		k++;
	}

	return invCount;
}

void divArray (LLI start, LLI end,  LLI *nums, LLI *arrHalf) {

	LLI i;

	for (i = INDEX; i < end; i++) {
		arrHalf[i] = nums[i + start];
	}

}


void printArray (LLI *nums, LLI end) {

	LLI i;

	for (i = INDEX; i < end; i++) {
		printf(" %lld ", nums[i]);
	}

}

