#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

long long countCompleteDayPairs(int* hours, int hoursSize) {
	int index[24] = {0};
	long long cnt = 0;
	
	/* 排序，为后续记录index做准备 */
	qsort(hours, hoursSize, sizeof(int), cmp);
	
	for(int i = 0; i < hoursSize - 1; i++){
		int j = hoursSize - 1;
		while(i < j){
			if((hours[i] + hours[j]) % 24 == 0){
				cnt++;
				j--;
			}
			else if((hours[i] + hours[j]) / 24 == 0){
				i++;
			}
			else{
				j--;
			}
		}
	}
	
	return cnt;
}