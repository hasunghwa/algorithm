#include <stdio.h>
#define SWAP(a, b) { int cup; cup = b; b = a; a = cup; }
int main()
{
	int T = 0;
	int A = 0, B = 0 , ans = 0;
	int original_a = 0, original_b = 0;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++)
	{
		scanf("%d %d", &A, &B);
		original_a = A; 
		original_b = B;
		getchar();
		if(A<B) SWAP(A, B);
		while(1){
			if(A % B == 0){
				ans = B;
				break;
			}else{
				ans = A%B;
				A = B;
				B = ans;				
			}		
		}
		printf("%d\n", (original_a*original_b/ans));
	}
	return 0;
}