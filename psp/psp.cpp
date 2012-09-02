#include<cstdio>

int main ( ) 
{
	
	freopen ( "psp.in", "r", stdin ) ;
	freopen ( "psp.out", "w", stdout ) ;
	
	int n , S , nr = 0 , i , x;
	
	scanf ( "%d%d", & n, & S ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d", & x ) ;
		if ( x <= S )
		{
			S-=x;
			++nr;
		}
	}
	
	printf ( "%d %d", nr , S ) ;
	
	
	return 0 ;
}