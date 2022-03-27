        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>



        /*상수정의*/

        #define ROW 13
        #define COL 24
        #define STACK_SIZE ROW * COL  /*스택의 최대 크기*/
        #define TRUE 1                /*TRUE*/
        #define FALSE 0                /*FALSE*/



        typedef struct{                /*element*/

        short int row;

        short int col;

        short int dir;

        }element;



        typedef struct{

        short int vert;

        short int horiz;

        }offsets;



        /*전역변수*/

        offsets move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};/*방향 표시*/



        element stack[ STACK_SIZE];

        int maze[ROW][COL] = {0,0};                /*미로 변수*/

        int mark[ROW][COL];                /*지나간 길 표시할 변수*/

        int direction[ROW][COL];          /*이동 방향 저장*/

        int i,j, row, col, next_row, next_col, dir, found=FALSE;

        int top;



        void push(int *top, element position)            /*스택에 푸쉬*/

        {

        (*top)++;

        stack[*top].row = position.row;

        stack[*top].col = position.col;

        stack[*top].dir = position.dir;

        }





        element pop(int* top)                    /* 스택에서 팝*/

        {

        element result;

        if(*top<0){

        printf("Stack is Empty.\n");

        }

        else{

        result = stack[*top];

        (*top)--;

        }

        return result;

        }

        element peek(int* top)                   /* 스택에서 팝*/

        {

        element result;

        if(*top<0){

        printf("Stack is Empty.\n");

        }

        else{

        result = stack[*top];

        }

        return result;

        }







        void initialize()

        {
        int i,j;

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
            }
        }
	    fclose(fp);
        for (i=0; i<  ROW; i++)

        {                    /*ROW 를 출력*/

        for (j=0 ; j< COL; j++)

        {

        printf(" %d ",maze[i][j]);

        }

        printf("\n");

        }



        for(i=0; i< ROW; i++)

        {

        for(j=0; j<= COL; j++)

        {

        mark[i][j] = 0;

        }

        }

        printf("\t\t\t -maze-\n");



        }



        void find_path()

        {

        /*미로의 길을 찾아서 있으면 스택에 저장*/

        element position;

        mark[1][1]=1;

        top=0;

        stack[0].row=1;

        stack[0].col=1;

        stack[0].dir=1;



        while(top>-1 && !found)

        {

        position = pop(&top);                        /*스택의 top을 꺼냄*/

        row = position.row;

        col = position.col;

        dir = position.dir;

        while(dir < 8 && !found)                /*dir방향으로 이동후 길이 있으면 이동 없으면 다시 돌아옴*/

        {

        next_row = row + move[dir].vert;

        next_col = col + move[dir].horiz;

        if(next_row == ROW-1 && next_col == COL-1)  /*출구를 찾으면 길을 찾았다고 표시해줌*/

        {

        found=TRUE;

        }

        else if(!maze[next_row][next_col] && !mark[next_row][next_col])

        {

        mark[next_row][next_col] = TRUE  ;

        direction[row][col]=dir;

        position.row = row;

        position.col = col;

        position.dir = dir++;/*방향 저장*/



        push(&top, position);                /*스택에 삽입*/

        row = next_row;

        col = next_col;

        dir = 0;

        }

        else ++dir;

        }

        }

        }



        void print_path()

        {

        /*길을 찾으면 출력*/

        if(found)

        {

        for(i=0; i< ROW; i++)                 /*stack을 이용하기위해서 초기화*/

        {

        for(j=0; j<= COL; j++)

        {

        mark[i][j] = 0;

        }

        }

        printf("The path is : \n");

        printf("row col\n");

        for(i=0; i<=top; i++)

        {

        printf("%2d%5d\n", stack[i].row, stack[i].col);

        mark[stack[i].row][stack[i].col] = 1;           /*stack에 저장되있는 부분만 길로 취급!*/

        }





        printf("%2d%5d\n", row, col);

        printf("\n이동경로를 출력합니다.\n");

        printf("\n");

        for(row=0; row<ROW ; row++)

        {

        for(col=0; col<COL ; col++)

        {

        if((row==1)&&(col==1))

        {

        printf(" S");

        }

        else if((row==ROW-2) && (col==COL-2))

        {

        printf(" E");

        }

        else

        {

        if((mark[row][col] == FALSE)) /*mark 길이 아니면 X혹은 공백으로채움*/

        {

        if(maze[row][col]==1)  /* 벽인경우에 X*/

        {

        printf("%2c",'X');

        }

        else               /*벽이 아닌경우에는 공백으로 출력*/

        {

        printf("%2c",' ');

        }

        }

        else

        {

        switch(direction[row][col])  /*방향에따라 표시*/

        {

        case 0:

        printf("↑");

        break;

        case 1:

        printf("↗");

        break;

        case 2:

        printf("→");

        break;

        case 3:

        printf("↘");

        break;

        case 4:

        printf("↓");

        break;

        case 5:

        printf("↙");

        break;

        case 6:

        printf("←");

        break;

        case 7:

        printf("↖");

        break;

        }

        }

        }

        }

        printf("\n");

        }

        }

        else printf("----have no path---\n");

        }



        int main(void)

        {

        initialize();

        find_path();

        print_path();



        return 0;

        }