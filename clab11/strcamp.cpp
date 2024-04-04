#include <stdio.h>
 #include <string.h>
int main(int argc, char *argv[])
{
	char name[20];
	 printf( "Enter your name: " );
    scanf( "%s", name );
    if( strcmp( name, "Mary" ) == 0 )
      printf( "Hello, Dr. Mary!\n" );

	return 0;
}