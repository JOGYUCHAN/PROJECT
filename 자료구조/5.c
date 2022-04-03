#include<stdio.h>
#define ROW 13
#define COL 24
int maze[ROW][COL];

 void print_maze(){

        int i,j;
        {
        FILE *f;
        f = fopen("maze.txt", "r+");
        for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			maze[i][j] = 1;
                 }
        }
        for(i = 1; i<ROW -1;i++){
                for(j = 1; j < COL -1; j++){
                        fscanf(f,"%d",maze[i][j]);
                }
        }
        fclose(f);
        }
 }