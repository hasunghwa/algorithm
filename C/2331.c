#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int A = 0, P = 0, len = 0, cnt = 0;
	long long num = 0;
	long long visit[1000001] = {0, };
	int squrd[5][10] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {0, 1, 4, 9, 16, 25, 36, 49, 64, 81}, {0, 1, 8, 27, 64, 125, 216, 343, 512, 729},
						{0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561}, {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049}};
	char conv[20];
	scanf("%d %d", &A, &P);
	len = sprintf(conv, "%d", A);
	
	while(visit[A] == 0){
		for(int i = 0; i < len; i++)
			num += squrd[P-1][conv[i]-'0'];
		
		len = sprintf(conv, "%lld", num);
		visit[A] = num;
		A = num;
		num = 0;
		cnt ++;
	}
	
	long long cur = visit[A];
	while(cur != A){
		cur = visit[cur];
		cnt--;
	}
	printf("%d", cnt-1);
	return 0;	
}