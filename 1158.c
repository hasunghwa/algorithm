#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int N = 0, K = 0;
    int cnt = 0, j = 1;
    int pArr[5001] = {0, };

    scanf("%d %d", &N, &K);
    printf("<");
    for (int i = 0; i < N; i++)
    {
        cnt = 0;
        while(1)
        {   
            if(pArr[j] == 0)
                cnt ++;
            if(cnt == K)
            {
                pArr[j] = -1;
                if(i != N-1)
                    printf("%d, ", j);
                else
                    printf("%d>", j);
                break;
            }
            j++;
            if(j > N)
                j = 1;
        }
    }
    return 0;
}


