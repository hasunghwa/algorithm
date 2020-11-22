#include <stdio.h>
int main()
{
	int a=0, b=0, sub=0;
	int arr[3]={0,};
	
	scanf("%d", &a);
	getchar();
	scanf("%d", &b);
	
	arr[2]=a*(b/100);
	sub+=(a*(b/100))*100;
	b-=(b/100)*100;
	
	arr[1]=a*(b/10);
	sub+=(a*(b/10))*10;
	b-=(b/10)*10;

	arr[0]=a*(b/1);
	sub+=(a*(b/1))*1;
	for(int i=0; i<3; i++) { printf("%d\n", arr[i]); }
	printf("%d\n", sub);
}
