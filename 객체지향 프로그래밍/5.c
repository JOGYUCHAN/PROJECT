#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("maze.txt","r");
    if( fp == NULL )
    {
        printf("파일이 열리지 않습니다.\n");
        return 1;
    }
    printf("파일이 열렸습니다.\n");
    fclose(fp);

    return 0;
}