#include<cstdio>

int main ( ) 
{
	freopen ( "h.in", "r", stdin ) ;
	freopen ( "h.out", "w", stdout ) ;
	
	int n , i , j , q ;
	
	scanf ( "%d" , & n ) ;
	
	int sumt = n*(4*n+1);
	
	for ( i = 1 ; i <= 2*n ; ++ i )
		printf ( "%d ", n + i ) ;
	
	return 0 ;
}