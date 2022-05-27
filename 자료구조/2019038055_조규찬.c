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

    FILE *fp = fopen("input.txt", "r");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    buffer = malloc(size + 1);    
    memset(buffer, 0, size + 1);  

    fseek(fp, 0, SEEK_SET);                
    fread(buffer, size, 1, fp);

    char *ptr = strtok(buffer, ",");
    while (ptr != NULL)
    {
        int num;
        num = atoi(ptr);
        push(num);
        ptr = strtok(NULL, ",");
        count++;

    }

    printf("pop : ");
    //최대 힙에서 차례대로 pop()한 결과.
    for(int i = 0 ; i<count - 1 ; i++){
        printf("%d ", pop());
    }
    printf("\n");
    
                    
    fclose(fp);

    free(buffer);

    return 0;
}