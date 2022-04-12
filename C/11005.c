/*
문제
10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.
10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

입력
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

출력
첫째 줄에 10진법 수 N을 B진법으로 출력한다.
*/
#include <stdio.h>
int arr[31] = {0,};
int i = 0;
int conversion(long long N, int B)
{
	if((long long)N/B < B){
		arr[i] = N%B;
		if((int)N/B != 0) // 마지막 몫이 0 일때 무시
			arr[++i] = (int)N/B;
		return 0; 	
	}else{
		arr[i++] = N%B;
		return conversion((long long)N/B, B);
	}
}
int main()
{
	long long N = 0;
	int B = 0;
	scanf("%lld %d", &N, &B);
	
	conversion(N, B);
	for(int j = i; j>=0; j--){
		if(arr[j] >= 10){
			printf("%c", 'A'+arr[j]-10);
		}else{
			printf("%d", arr[j]);
		}
	}
	return 0;
}