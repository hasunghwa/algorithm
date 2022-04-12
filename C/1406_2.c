#include <stdio.h>
#include <string.h> 
int main()
{
    char Left_stack[600001], Right_stack[600001];
    int Left_top = -1, Right_top = -1, N, length;
    scanf("%s", Left_stack);
    getchar();
    Left_top=length=strlen(Left_stack);
    
	Left_top--;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
        char direction[4] = {0, };
        scanf("%[^\n]", direction);
        getchar();

        if(direction[0] == 'L'){ // 커서를 왼쪽으로 한 칸 옮김
            if(Left_top == -1) continue; // 커서가 문장의 맨 앞이면 무시됨
            Right_stack[++Right_top] = Left_stack[Left_top];
            Left_stack[Left_top--] = '\0';
        }
        else if(direction[0] == 'D'){ // 커서를 오른쪽으로 한 칸 옮김
            if(Right_top == -1) continue; // 커서가 문장의 맨 뒤이면 무시됨
            Left_stack[++Left_top] = Right_stack[Right_top--];
        }
        else if(direction[0] == 'B'){ // 커서 왼쪽에 있는 문자를 삭제함
            if(Left_top == -1) continue; // 커서가 문장의 맨 앞이면 무시됨
            Left_stack[Left_top--] = '\0';
        }
        else{ // $라는 문자를 커서 왼쪽에 추가함
            Left_stack[++Left_top] = direction[2];
        }    

        //printf("L: %s\n", Left_stack);
        //printf("R: %s\n", Right_stack);
    }

    for(int i = 0; i <= Left_top; i++){
        printf("%c", Left_stack[i]);
    }
    for(int i = Right_top; i >= 0; i--){
        printf("%c", Right_stack[i]);
    }
    printf("\n");
    return 0;
}