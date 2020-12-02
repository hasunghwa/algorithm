#include <stdio.h>
int arr[31] = {0,};
int i = 0;
int conversion(long long N, int B)
{
	if((long long)N/B < B){
		arr[i++] = N%B;
		arr[i] = (int)N/B;
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
			if(arr[j] == 0 && j == i)	continue;
			printf("%d", arr[j]);
		}
	}
	return 0;
}