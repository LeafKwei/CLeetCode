#include <stdio.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main(void){
	int *size = NULL;
	int retsize = 0;
	
	int **tp = threeSum((int[]){0,0,0,0}, sizeof((int[]){0,0,0,0}) / sizeof(int), &retsize, &size);
	
	for(int i = 0; i < retsize; i++){
		printf("[");
		for(int j = 0; j < size[i]; j++){
			if(j < size[i] - 1) printf("%d ", tp[i][j]);
			else printf("%d", tp[i][j]);
		}
		printf("]\n");
	}
}