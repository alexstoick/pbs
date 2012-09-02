#include<cstdio>
#include<algorithm>

using namespace std ;

int x [ 1000001 ] ;
int A [ 1000001 ] ;

int n , r , c ;

bool dezechilibru ( int D ) 
{
	int i ;
	if ( D > x[n]-x[1] ) 
		return true ;
	for ( i = 1 ; i <= n ; ++ i )
		A[i] = 0 ;
	for ( i = c ; i <= n ; ++ i )
		if ( x[i] - x[i-c+1] <= D )
			A[i] = max ( A[i-1], A[i-c] + 1 ) ;
		else
			A[i] = A[i-1] ;
	return ( A[n] >= r ) ;
}

void caut_bin ( ) 
{
	
	int pas , i ;
	pas = 1 << 16 ;
	for ( i = 0 ; pas ; pas >>= 1 ) 
		if ( ! dezechilibru ( i + pas ) )
			i += pas ;
	printf ( "%d", i+1 ) ;
}

int main () 
{

	freopen ( "easychoice.in", "r" , stdin ) ;
	freopen ( "easychoice.out", "w", stdout ) ;
	
	int i ;
	
	scanf ( "%d%d%d" , & n , &r , & c ) ;
	
	if ( c== 1 )
	{
		printf ( "0" ) ;
		return 0 ;
	}
	
	for ( i = 1 ; i <= n ; ++ i )
		scanf ( "%d", & x[i] ) ;
	
	sort ( x+1 , x+n+1 ) ;
	caut_bin ( );
	return 0 ;
}
