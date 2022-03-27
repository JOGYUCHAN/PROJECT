        #include <stdio.h>
        #include <stdlib.h>



        #define ROW 13
        #define COL 24
        #define STACK_SIZE ROW * COL  
        #define TRUE 1  
        #define FALSE 0  



        typedef struct{

        short int row;

        short int col;

        short int dir;

        }element;



        typedef struct{

        short int vert;

        short int horiz;

        }offsets;

        offsets move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};


        element stack[ STACK_SIZE];

        int maze[ROW][COL]; 

        int mark[ROW][COL];

        int direction[ROW][COL];

        int i,j, row, col, next_row, next_col, dir, found=FALSE;

        int top;



        void push(int *top, element position) 

        {

        (*top)++;

        stack[*top].row = position.row;

        stack[*top].col = position.col;

        stack[*top].dir = position.dir;

        }





        element pop(int* top)
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

        element peek(int* top) 

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
        fp = fopen("maze.txt", "r");
        for(i=0; i<13; i++){				// 미로의 둘레를 1로 둘러 싼다
		for(j=0; j<24; j++){
			maze[i][j] = 1;
                }
         } ;
        for(i=1; i< ROW -1; i++){
                for(j=1; j< COL -1; j++){
                        fscanf(fp,"%d",&maze[i][j]);
                        printf("%d", maze[i][j]);
        }
        printf("\n");
    }
	fclose(fp);


        printf("\t\t\t-maze-\n");

        printf("    ");

        printf("\n\n");

        for (i=1; i<  ROW-1; i++)

        {                

        for (j=1 ; j< COL-1; j++)

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

        position = pop(&top);                       

        row = position.row;

        col = position.col;

        dir = position.dir;

        while(dir < 8 && !found)   

        {

        next_row = row + move[dir].vert;

        next_col = col + move[dir].horiz;

        if(next_row == ROW-1 && next_col == COL-1) 

        {

        found=TRUE;

        }

        else if(!maze[next_row][next_col] && !mark[next_row][next_col])

        {

        mark[next_row][next_col] = TRUE  ;

        direction[row][col]=dir;

        position.row = row;

        position.col = col;

        position.dir = dir++;



        push(&top, position);   

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

        

        if(found)

        {

        for(i=0; i< ROW; i++)
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

        mark[stack[i].row][stack[i].col] = 1; 

        }





        printf("%2d%5d\n", row, col);

        printf("\n이동경로를 출력합니다.\n");

        printf("\n");

        for(row=1; row<ROW - 1 ; row++)

        {

        for(col=1; col<COL - 1 ; col++)

        {

        if((row==1)&&(col==1))

        {

        printf("%2c",'0');

        }

        else if((row==ROW-2) && (col==COL-2))

        {

        printf("%2c",'0');

        }

        else

        {

        if((mark[row][col] == FALSE))

        {

        if(maze[row][col]==1)

        {

        printf("%2c",'1');

        }

        else

        {

        printf("%2c",'1');

        }

        }

        else

        {

        printf("%2c",'0');

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