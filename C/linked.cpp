#include <stdio.h>
int main()
{
	int A=0,B=0,V=0;
	int dal=0, day=1;
	scanf("%d %d %d", &A, &B, &V);
	while(dal>=V){
		if(day%2==0){
			dal+=A;
		} else{
			dal+=B;
		}
		day++;
	}
	printf("%d", day/2);
}
