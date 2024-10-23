#include <stdio.h>

long long countCompleteDayPairs(int* hours, int hoursSize);

int main(void){
	int hours[] = {12,12,30,24,24};
	long long cnt = countCompleteDayPairs(hours, sizeof(hours) / sizeof(int));
	printf("cnt = %ld\n", cnt);
}