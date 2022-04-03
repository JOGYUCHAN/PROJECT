#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define MAZE_SIZE 12

typedef struct {
    short row;
    short col;
}offset;

typedef struct stack {
    offset data[MAX_SIZE];
    int top;
}Stack;

char maze[MAZE_SIZE][MAZE_SIZE] ={


};

void init(Stack *p){
    p -> top = -1;    
}

int full(Stack *p){
    return ( p -> top == MAX_SIZE - 1);
}

int empty (Stack *p){
    return (p -> top == -1);
}

void push(Stack *p, offset data){
    if(full(p)){
        printf("스택이 꽉 찼습니다.\n"); return;
    }
    else{
        p -> top++;
        p -> data[p -> top].row=data.row; p -> data[p -> top].col=data.col;
    }
}

offset pop(Stack *p){
    if(empty(p)){
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    return p -> data[(p -> top)--];
}

void Movable(Stack *s, int row, int col) {
    if(row < 0 || col < 0 || row > MAZE_SIZE || col > MAZE_SIZE) return;
    if(maze[row][col] != '1' && maze[row][col] != '.'){
        offset next;
        next.row = row;
        next.col = col;
        push(s, next);
    }
}

int main(){
    Stack s;
    offset here;
    int i, j, row, col;
    FILE *fp = fopen("result.txt", "w");
    init(&s);
    print("탐색시작\n");
    for(i = 0; i < 11; i++){
        for(j = 0; j < 11; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
    for(i = 0; i < MAZE_SIZE < i++){
        for(j = 0; j < MAZE_SIZE; j++){
            if(maze[i][j])
        }

    }

}




