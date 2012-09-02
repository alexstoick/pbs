#include<cstdio>
#include<algorithm>

using namespace std ;

int fx [ 50001 ] ;
int fy [ 50001 ] ; 

int inline min ( int x , int y )
{
	if ( x < y )
		return x; 
	return y ;
}

int x [ 101 ] , y [ 101 ] ;

int main ( )
{
	
	freopen ( "echilibru.in", "r", stdin ) ;
	freopen ( "echilibru.out", "w", stdout ) ;
	
	int n , m , i , j , maxx = 0 , maxy = 0 , max  ;
	
	scanf ( "%d%d" , & n , & m ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d", & x[i] ) ;
		maxx += x[i] ;
	}
	
	for ( i = 1 ; i <= m ; ++ i )
	{
		scanf ( "%d", & y[i] ) ;
		maxy += y[i] ;
	}

	max = min ( maxy, maxx ) ;
	
	sort ( x + 1 , x + 1 + n ) ;
	sort ( y + 1 , y + 1 + m ) ;
	
	for ( i = 1 ; i <= n ; ++ i ) 
	{
		for ( j = max-x[i] ; j > 0 ; -- j )
			if ( fx[j] )
				fx[j+x[i]]=true;
		fx[x[i]]=true;
	}
	for ( i = 1 ; i <= m ; ++ i )
	{
		for ( j = max - y[i]; j > 0 ; -- j )
			if ( fy[j] )
				fy[j+y[i]]=true;
		fy[y[i]]=true;
	}
	
	int contor = 0 ;
	
	for ( i = max ; i > 0 ; -- i )
		if ( fx[i] && fy[i] )
			++contor;
	printf ( "%d\n" , contor ) ;
	return 0 ;
}
