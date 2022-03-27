
#include <stdio.h>

#define MAX_STACK_SIZE 500				// stack 크기를 행*열의 크기로 정한다
#define FALSE 0
#define TRUE  1

typedef struct{					
	short int vert;
	short int horiz;
} offsets;
offsets move[8];


typedef struct{
	short int row;
	short int col;
	short int dir;
} element;			
element stack[MAX_STACK_SIZE];

void path(void);					// 경로 path 함수
void push(int *top, element position);
element pop(int *top);
int output();

int mark[13][24];				// mark 배열 초기화 한다
int mark2[13][24];				// 자취를 남기기 위한 mark2 배열 설정 
int maze[13][24];					// maze 행령의 크기를 설정한다

int top;
int EXIT_ROW = 1;					// 미로의 탈출구
int EXIT_COL = 1;
int n;
int m;
int i, j;

int main(void)
{			
	move[0].vert = -1;	move[0].horiz = 0;
	move[1].vert = -1;	move[1].horiz = 1;
	move[2].vert = 0;	move[2].horiz = 1;
	move[3].vert = 1;	move[3].horiz = 1;
	move[4].vert = 1;	move[4].horiz = 0;
	move[5].vert = 1;	move[5].horiz = -1;
	move[6].vert = 0;	move[6].horiz =-1;
	move[7].vert = -1;	move[7].horiz = -1;

	output();
	path();
	
	return 0;
}

int output()
{
	printf("\n < THE MAZE >================================================================\n\n");	
	
	FILE *fp;
	fp = fopen("maze.txt", "r") ;
	for(i=0; i<13; i++){				// 미로의 둘레를 1로 둘러 싼다
		for(j=0; j<24; j++){
			maze[i][j] = 1;
        }
    }
    for(i=1; i<12; i++){
        for(j=1; j< 23; j++){
            fscanf(fp,"%d",&maze[i][j]);
            printf("%d", maze[i][j]);
        }
    }
	fclose(fp);
	return 0;
}


void path (void)
{
	int i, row, col, next_row, next_col, next_dir, dir, found=FALSE;
	element position;
	mark[20][25]=1;				// 시작위치를 저장한다
	mark2[EXIT_ROW][EXIT_COL]=1;			// 끝나는 위치를 저장한다	
	top=0;
	stack[top].row=20;				// 시작위치를 저장한다
	stack[top].col=25;
	stack[top].dir=1;
	while(top > -1 && !found)			// top이 비어있거나 길이 없다면
	{
		position = pop(&top);		
		row = position.row;
		col = position.col;
		dir = position.dir;
		
		while(dir < 8 && !found)		// 다음번 이동할 위치를 결정
		{				
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			next_dir = dir;
			if(next_row == EXIT_ROW && next_col == EXIT_COL)
				found = TRUE;	// 출구를 만나면 반복문을 탈출한다
			else if(!maze[next_row][next_col] && !mark[next_row][next_col])
			{			/* 다음 이동할 곳이 막혀있지 않거나 지나간적이 						없는곳이라면 */
				mark[next_row][next_col]=1;			
				position.row = row;
				position.col = col;
				position.dir = dir;
				push(&top, position);
				row = next_row;
				col = next_col;
				dir = 0;
			}			
			else
				++dir;		// 방향을 1씩 증가시킨다
		}
	}
	
	if(found)					// 탈출하면
	{				

		printf("\n < THE PATH >================================================================\n");

		printf("Starting position(ROW, COL) : [%2d, %2d]\n", stack[0].row, stack[0].col);
		printf("Exiting position(ROW, COL)  : [%2d, %2d]\n\n", EXIT_ROW, EXIT_COL);
		printf("Position[ROW,COL,DIR] \n\n");
		for(i=0 ; i<=top ; i++)
		{
			printf("[%2d, %2d, %2d] ==> ", stack[i].row, stack[i].col, stack[i].dir);		

			if(i%5==4)		// 이동경로를 한줄에 5개씩 표시하기 위해
				printf("\n");
		}
		printf("[%2d, %2d, %2d] ==> ", row, col, dir);
		printf("[%2d, %2d]\n", EXIT_ROW, EXIT_COL);
		printf("\n");

		
		printf(" < THE MARKING OF PATH >====================================================\n ");
		for(i=0 ; i<=top ; i++)		// stack에 저장되어있는 값을 mark2행렬에 저장
		{
			mark2[stack[i].row][stack[i].col]=1;		
		}
		mark2[row][col] = 1;		// 마지막 위치는 저장이 안 되므로 따로 저장

		for(i=0; i<13; i++)
		{
			for(j=0; j<24; j++)
			{
				if(mark2[i][j] == 1)// mark2 행렬값이 1이면 별 모양 출력
					printf("*");	
				else
					printf(" ");// 아니면 공백 출력
			}
			printf("\n");
		}
		
	}
	
	else printf("The maze does not have a path\n");
}

void push(int *top, element position)
{
	stack[++(*top)]=position;
}

element pop(int *top)
{

	return stack[(*top)--];
}

