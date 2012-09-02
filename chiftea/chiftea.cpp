#include<cstdio>
#include<cmath>

int main ( ) 
{

	freopen ( "chiftea.in", "r", stdin ) ;
	freopen ( "chiftea.out" , "w", stdout ) ;
	
	int test ;
	int n ;
	
	scanf ( "%d" , & test ) ;
	
	for ( ; test ; -- test )
	{
		
		scanf ( "%d", & n  ) ;
		int rad = sqrt ( n ) ;
		
		if ( rad * rad == n )
			printf ( "%d\n" , rad*4 ) ;
		else
		{
			n -= rad*rad ;
			if ( n <= rad )
				printf ( "%d\n" , rad*4 + 2 ) ;
			else
				printf ( "%d\n" , rad*4 + 4 ) ;
		}
		
	}
	
	
	return 0 ;
}
