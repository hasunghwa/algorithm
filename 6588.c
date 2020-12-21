/*
문제
4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
예를 들어 8은 3 + 5로 나타낼 수 있고, 3과 5는 모두 홀수인 소수이다. 또, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 이다.

입력
입력은 하나 또는 그 이상의 테스트 케이스로 이루어져 있다. 테스트 케이스의 개수는 100,000개를 넘지 않는다.
각 테스트 케이스는 짝수 정수 n 하나로 이루어져 있다. (6 ≤ n ≤ 1000000)
입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, n = a + b 형태로 출력한다. 이때, a와 b는 홀수 소수이다. 숫자와 연산자는 공백 하나로 구분되어져 있다. 만약, n을 만들 수 있는 방법이 여러 가지라면, b-a가 가장 큰 것을 출력한다. 또, 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우에는 "Goldbach's conjecture is wrong."을 출력한다.
사용 알고리즘 - 에라토스테네스의 체
*/
#include <stdio.h>
int main()
{
	int N = 1;
	int arr[1000002] = {0, };
	
	arr[1] = 1;
	
	for(int i = 2; i*2 <= N; i++) //2를 제외한 2의배수 제거
		arr[i*2] = 1;
	
	for(int i = 3; i*i <= 1000000; i+=2) //2의배수 제외하고 소수 제거
	{		
		for(int j = 3; j <= i; j++)
		{
			if(i % j == 0){
				if(j == i) //소수이면
					for(int k = 2; k*i<=1000000; k++) // 그 수의 배수 제거
						arr[k*i] = 1;
				break;
			}
		}
	}

	while(N != 0){
		int TF = 0;
		scanf("%d", &N);
		
		for(int i = 1; i < N; i+=2)
		{
			if(arr[N-i] == 0 && arr[i] == 0){ // 두 수가 소수이면
				printf("%d = %d + %d\n", N, i, N-i);
				TF = 1;
				break;
			}
			if(!TF && i == N-4) // 홀수 소수의 합으로 n을 나타낼 수 없는 경우
				printf("Goldbach's conjecture is wrong.");
		}
	}
	return 0;
}