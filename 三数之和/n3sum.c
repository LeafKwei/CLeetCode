#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void* b){
	return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	
	int rindex = 0;
	int **result = (int**) malloc(numsSize * numsSize * sizeof(int*));
	int *closize = (int*) malloc(numsSize * numsSize * sizeof(int));
	
	for(int ni = 0; ni < numsSize - 2; ni++){
		if(ni > 0 && (nums[ni] == nums[ni - 1])){  //去重，排除已经在元组内的相同数字
			continue;
		}
		
		/* 从当前位置开始，使用双指针依次遍历 */
		int head = ni + 1, tail = numsSize - 1;
		while(head < tail){
			int sum = nums[ni] + nums[head] + nums[tail];
			if(sum > 0){        //当sum大于0时，我们需要减小和的大小，由于nums已排序，因此将tail左移即可实现减小和
				tail--;
			}
			else if(sum < 0){
				head++;         //同理，head右移实现增大和
			}
			else{
				result[rindex] = (int*) malloc(3 * sizeof(int));
				result[rindex][0] = nums[ni];
				result[rindex][1] = nums[head];
				result[rindex][2] = nums[tail];
				closize[rindex] = 3;
				rindex++;
				head++;
				
				while(head < tail && (nums[head] == nums[head - 1])){
					head++;
				}
			}
		}
	}
	
	*returnSize = rindex;
	*returnColumnSizes = closize;
	
	return result;
}

/*
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int **tp = (int**) malloc(30000 * sizeof(int*));
	int (*size) = (int*) malloc(30000 * sizeof(int));
	int tpidx = 0;
	
	for(int i = 0; i < numsSize; i++){
		for(int j = i + 1; j < numsSize; j++){
			for(int k = j + 1; k < numsSize; k++){
				if(i == j || i == k || j == k){
					continue;
				}
				
				if((nums[i] + nums[j] + nums[k]) == 0){
					tp[tpidx] = (int*) malloc(3 * sizeof(int));
					tp[tpidx][0] = nums[i];
					tp[tpidx][1] = nums[j];
					tp[tpidx][2] = nums[k];
					size[tpidx] = 3;
					tpidx++;
				}
			}
		}
	}
	
	*returnSize = tpidx;
	*returnColumnSizes = size;
	
	return tp;
}
*/