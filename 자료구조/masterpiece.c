#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>
#define HEAP_SIZE 256
int heap[HEAP_SIZE];
int heapCount = 0;   

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int a){
    heap[++heapCount] = a;
    
    int child = heapCount;
    int parent = child/2;
    
    while(child>1 && heap[child]>heap[parent]){
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent = child/2;
    }
    
}

int pop(){
    int ret = heap[1];
    
    swap(&heap[1], &heap[heapCount]);
    heapCount = heapCount-1;
    
    int parent = 1;
    int child = parent*2;
    
    if(child+1 <= heapCount){
        child = (heap[child]>heap[child+1]) ? child : child+1;
    }
    
    while(child<=heapCount && heap[child]>heap[parent]){
        swap(&heap[child], &heap[parent]);
        parent = child;
        child = parent*2;
        
        if(child+1 <= heapCount){
            child = (heap[child]>heap[child+1])? child : child+1;
        }
    }
    
    return ret;
}

int main()
{
    char *buffer;
    int size;
    int count;

    FILE *fp = fopen("input.txt", "r");    // input.txt 파일을 읽기 모드(r)로 열기.
                                           // 파일 포인터를 반환

    fseek(fp, 0, SEEK_END);    // 파일 포인터를 파일의 끝으로 이동시킴
    size = ftell(fp);          // 파일 포인터의 현재 위치를 얻음

    buffer = malloc(size + 1);    // 파일 크기 + 1바이트(문자열 마지막의 NULL)만큼 동적 메모리 할당
    //memset(buffer, 0, size + 1);  // 파일 크기 + 1바이트만큼 메모리를 0으로 초기화

    fseek(fp, 0, SEEK_SET);                // 파일 포인터를 파일의 처음으로 이동시킴
    fread(buffer, size, 1, fp);

    //printf("%s size: %d, count: %d\n", buffer, size, count);

    char *ptr = strtok(buffer, ",");
    while (ptr != NULL)              //ptr이 NULL일때까지 (= strtok 함수가 NULL을 반환할때까지)
    {
        //printf("%s\n", ptr);
        int num;
        num = atoi(ptr);
        //printf("%d\n",num);
        push(num);        //자른 문자 출력
        ptr = strtok(NULL, ",");     //자른 문자 다음부터 구분자 또 찾기
        count++;

    }

    printf("pop : ");
    //최대 힙에서 차례대로 pop()한 결과.
    for(int i = 0 ; i<count - 1 ; i++){
        printf("%d ", pop());
    }
    printf("\n");
    
                    
    fclose(fp);     // 파일 포인터 닫기

    free(buffer);   // 동적 메모리 해제

    return 0;
}