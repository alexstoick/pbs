#include <cstdio>

int cif ( int x ) 
{
	while ( x > 9 )
		x/=10;
	return x ;
}

int main ( ) 
{
	
	freopen ( "fazanr.in","r", stdin ) ;
	freopen ( "fazanr.out","w", stdout ) ;
	
	int n , x , c , c1 , i , q =0 ;
	
	scanf ( "%d", &n ) ;
	
	scanf ( "%d", & x ) ;
	c = x%10 ;
	
	for ( i = 2 ; i <= n ; ++ i )
	{
		scanf ( "%d", &x ) ;
		c1 = cif ( x ) ;
		if ( c != c1 )
			++q;
		c=x%10;;
	}
	
	printf ( "%d" , q ) ;
	return 0 ;
}
