#include<stdio.h>


int main()
{
    FILE* fp;
    int i = 1234;
    fp = fopen("in.txt", "wb");
    fwrite( &i, sizeof( int ), 1, fp );
    fclose( fp );
    i = -1;
    fp = fopen( "in.txt", "rb" );
    fread( &i, sizeof( int ), 1, fp );
    printf( "%d", i );
    fclose( fp );
    return 0;
}
