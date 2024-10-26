#include <stdio.h>
#include <stdlib.h>

long long countCompleteDayPairs(int* hours, int hoursSize) {
	long long total[24] = {0};
	long long cnt = 0;

	//统计每个元素的数量
	for(int i = 0; i < hoursSize; i++){
		total[hours[i] % 24] += 1;
	}
	
	for(int i = 0; i < 13; i++){
		if(i == 0 || i == 12){
			cnt += (total[i] * (total[i] - 1)) / 2;  //sn = n(a1 + an)/2
		}
		else{
			int peer = 24 - i;
			cnt += total[i] * total[peer];
		}
	}
	
	return cnt;
}

/*
int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

long long getZeroPair(int n){
	if(n == 0) return 0;
	return (n - 1) + getZeroPair(n - 1);
}

long long countCompleteDayPairs(int* hours, int hoursSize) {
	long long cnt = 0;
	int zindex = 0;
	
	//预处理
	for(int i = 0; i < hoursSize; i++){
		hours[i] = hours[i] % 24;         //收缩所有元素到0~23
	}
	
	//排序，为后续记录index做准备
	qsort(hours, hoursSize, sizeof(int), cmp);
	
	//计算最后一个0的位置
	zindex = hoursSize - 1;     //如果所有元素都为0时
	for(int i = 0; i < hoursSize; i++){
		if(hours[i] != 0){
			zindex = i - 1;
			break;
		}
	}
	
	if(zindex != -1){
		cnt += getZeroPair(zindex + 1);
	}
	
	for(int i = zindex + 1; i < hoursSize - 1; i++){
		int j = hoursSize - 1;
		
		while(i < j){
			if((hours[i] + hours[j]) % 24 == 0){
				cnt++;
				j--;
			}
			else if((hours[i] + hours[j]) > 24){
				j--;
			}
			else{
				break;
			}
		}
	}
	
	return cnt;
}
*/