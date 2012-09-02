#include <cstdio>

int cmmd ( int a , int b )
{
	int r ;
	while ( b ) 
	{
		r = a % b;
		a = b ;
		b = r;
	}
	return a ;
}

int main ()
{
	freopen ( "vraji.in","r",stdin ) ;
	freopen ( "vraji.out","w", stdout) ;
	
	int n , x , y , S = 0 , cmmdc , i ;
	
	scanf ( "%d", & n ) ;
	
	scanf ( "%d%d", & x, & y ) ;
	S = x*y ;
	cmmdc = x*y ;
	
	for ( i = 2 ; i <= n ; ++ i )
	{
		scanf ( "%d%d", &x,&y ) ;
		if ( x*y > S )
			S=x*y;
		cmmdc = cmmd ( cmmdc , x*y ) ;
	}
	printf ( "%d\n%d", S , cmmdc ) ;
	return 0 ;
}