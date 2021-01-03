/*
문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.
*/
#include <stdio.h>
#define MIN(a, b) a>b ? b:a
int main()
{
	int N = 0, cnt_two = 0, cnt_five = 0;
	scanf("%d", &N);
	
	for(int i = 2; i<=N; i*=2){ //2의 배수 개수
		cnt_two += N/i;
	}
	
	for(int i = 5; i<=N; i*=5){ //5의 배수 개수
		cnt_five += N/i;
	}
	
	printf("%d", MIN(cnt_two, cnt_five));
}