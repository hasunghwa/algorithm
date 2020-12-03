/*
문제
2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

입력
첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.
*/
#include <stdio.h>
int main()
{
	int i = 0, j = 0, k = 0, count = 0;
	long long multi = 1, tmp = 0;
	char n[1000001];
	int arr[1000001] = {0, };
	int arr2[333334] = {0, };
	
	scanf("%s", n);
	while(n[i] != '\0')
		arr[i++] = n[i] -'0';
	
	for(int j = i-1; j >= 0; j--)
	{	
		tmp += multi * arr[j];
		multi *= 2;
		count ++;
		
		if(count == 3 || j == 0){
			arr2[k++] = tmp;
			count = 0;
			tmp = 0;
			multi = 1;
		}
	}
	
	for(int j = k-1; j >= 0; j--)
		printf("%d", arr2[j]);
	return 0;
}