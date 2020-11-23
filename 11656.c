#include <stdio.h>
#include <string.h>
int main()
{
    char c;
    char arr[1001][1001];
    char cup[1001];
    int i = 0;
    int k = 0;
    while(1){
        scanf("%c", &c);
        if(c=='\n') { break; }
        k = 0;
        for(int j=i; j>=0; j--){
            arr[k++][j] = c;
        }
        i++;
    }

    for(int j=0; j<i; j++){
        for(int k=j; k<i; k++){
            if(strcmp(arr[j], arr[k]) > 0){
                strcpy(cup, arr[k]);
                strcpy(arr[k], arr[j]);
                strcpy(arr[j], cup);
            }
        }
    }

    for(int j=0; j<i; j++){
        printf("%s\n", arr[j]);        
    }
    return 0;
}