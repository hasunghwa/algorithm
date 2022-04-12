#include <stdio.h>
int eco(int a, int r){
	if( a%r == 0 ){
		return r;
	}else{
		eco(r, a%r);
	}
}
int main(){
	int a,r,result;
	scanf("%d %d", &a, &r);
	result = eco(a, r);
	printf("max:%d min:%d", result, (a*r)/result);
}
