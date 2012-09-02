#include<cstdio>

int fa [ 1 << 4 ] , fb [ 1 << 4 ] , f [ 1 << 4 ] ;

int main ( )
{
	
	freopen ( "cifre3.in","r",stdin ) ;
	freopen ( "cifre3.out","w",stdout ) ;
	
	int a , b , i , j ;
	
	scanf ( "%d%d", & a , & b ) ;
	
	while ( a )
	{
		++fa[a%10];
		++f[a%10];
		a/=10;
	}
	while ( b ) 
	{
		++fb[b%10];
		++f[b%10];
		b/=10;
	}
	
	for ( i = 0 ; i < 10 ; ++ i )
		if ( fa[i] && fb[i] )
			printf ( "%d ", i ) ;
	printf ( "\n" ) ;
	
	for ( i = 9 ; i >= 0 ; -- i )
	{
		for ( j = 1 ; j <= f[i] ; ++ j )
			printf ( "%d" , i ) ;
	}
	
	return 0 ;
}