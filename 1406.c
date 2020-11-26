#include <stdio.h>
#include <string.h> 
int main()
{
    int N = 0;
    int p = -1;
    char arr[600001];

    scanf("%s", arr);
    getchar();
    
    scanf("%d", &N);
    getchar();
    p = strlen(arr)-1;
    for(int i=0; i<N; i++)
    {
        char temp[600001] = {0,};
        char command[4];
        int len = strlen(arr);
        scanf("%[^\n]", command);
        getchar();
       
        if(command[0] == 'L'){ // 커서를 왼쪽으로 한 칸 옮김
            //printf("%d", p);
            if(p == -1) continue; // 커서가 문장의 맨 앞이면 무시됨
            p --;
        }
        else if(command[0] == 'D'){ // 커서를 오른쪽으로 한 칸 옮김
            //printf("%d", p);
            if(p == strlen(arr)-1) continue; // 커서가 문장의 맨 뒤이면 무시됨
            p ++;
        }
        else if(command[0] == 'B'){ // 커서 왼쪽에 있는 문자를 삭제함
            if(p == -1) continue; // 커서가 문장의 맨 앞이면 무시됨
            for(int j=p+1; j<=strlen(arr); j++){
                temp[j-p-1] = arr[j];
            }
            arr[p] = '\0';
            strcat(arr, temp);        // arr 뒤에 temp 붙임
            p --;
        }
        else{ // $라는 문자를 커서 왼쪽에 추가함
            //printf("%d", p);
            for(int j=p+1; j < len; j++){
                temp[j-p-1] = arr[j];
                arr[j] = '\0';
            }
            arr[p+1] = command[2];
            strcat(arr, temp);        // arr 뒤에 temp 붙임
            p ++;
        }    
    }
    printf("%s\n", arr);
    return 0;
}