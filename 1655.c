/*자료구조 힙이란?
힙이란 자료구조는 "완전 이진 트리"와 같습니다. 대신 노드로 갈 수록 우선순위가 높게끔 저장이 되는 자료구조입니다. 다음 그림처럼 노드로 올라갈수록 데이터의 값이 높은 힙을 "최대 힙"이라 합니다. 반대로 올라갈수록 값이 낮은 힙을 "최소 힙"이라 한다.*/
#include <stdio.h>
int max_idx = 0;
int min_idx = 0;
void max_push(int *heap, int input)
{	
	int i = ++(max_idx);
	while((i != 1) && input > heap[i/2])
	{
		heap[i] = heap[i/2];
		i /= 2;
	}	
	heap[i] = input;
}
void min_push(int *heap, int input)
{	
	int i = ++(min_idx);
	while((i != 1) && input < heap[i/2])
	{
		heap[i] = heap[i/2];
		i /= 2;
	}	
	heap[i] = input;
}
void max_pop(int *heap)
{
	int parent = 1, child = 2;
	int temp = heap[max_idx--];
	
	while(child <= max_idx){
		if((child < max_idx) && (heap[child] < heap[child+1]))
		   child++;
		if(temp >= heap[child])
		   break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
		   
	heap[parent] = temp;
}
void min_pop(int *heap)
{
	int parent = 1, child = 2;
	int temp = heap[min_idx--];
	
	while(child <= min_idx){
		if((child < min_idx) && (heap[child] > heap[child+1]))
		   child++;
		if(temp <= heap[child])
		   break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
		   
	heap[parent] = temp;
}
int main()
{
	int N = 0, input = 0;
	int max_heap[50002] = {0, };
	int min_heap[50002] = {0, };
	scanf("%d", &N);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d", &input);
		
		if(max_idx > min_idx)
			min_push(min_heap, input);
		else
			max_push(max_heap, input);
		
		if(max_idx != 0 && min_idx != 0 && max_heap[1] > min_heap[1]){
			int max_top = max_heap[1], min_top = min_heap[1];
			max_pop(max_heap);
			min_pop(min_heap);
			
			max_push(max_heap, min_top);
			min_push(min_heap, max_top);
		}
		
		printf("%d\n", max_heap[1]);
	}
}