/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

사용 알고리즘 - 에라토스테네스의 체
*/
#include <stdio.h>
int main()
{
	int M = 0, N = 0;
	int arr[1000002] = {0, };
	arr[1] = 1;
	scanf("%d %d", &M, &N);
	for(int i = 2; i*2 <= N; i++) //2를 제외한 2의배수 제거
		arr[i*2] = 1;
	for(int i = 3; i*i <= N; i+=2) //소수의 제곱이 N보다 작을때까지 2의배수 제외하고 반복
	{		
		for(int j = 3; j <= i; j++)
		{
			if(i % j == 0){
				if(j == i) //소수이면
					for(int k = 2; k*i<=N; k++) // 그 수의 배수 제거
						arr[k*i] = 1;
				break;
			}
		}
	}
	for(int i = M; i <= N; i++)
	{	
		if(arr[i] == 0)	
			printf("%d\n", i);
	}
	return 0;
}