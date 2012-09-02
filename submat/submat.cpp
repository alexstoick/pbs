#include<cstdio>
#include<algorithm>
using namespace std;

int x [ 1005 ] ;

int main ( )
{
	
	freopen ( "submat.in", "r", stdin ) ;
	freopen ( "submat.out", "w", stdout ) ;
	
	int n , m , val , i , j ;
	
	scanf ( "%d%d", & n , & m ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		for ( j = 1 ; j <= m ; ++ j )
		{
			scanf ( "%d", & val ) ;
			if ( ! val )
				++x[i] ;
		}

	sort ( x + 1 , x + n + 1 ) ;
	
	int max = -1  ;
	
	for ( i = 1 ; i <= n ; ++ i )
		if ( x[i] * (n-i+1) > max )
			max = x[i] * (n-i+1) ;
	
	printf ( "%d", max ) ;
	
	return 0 ;
}
