#include<cstdio>
#include<cstring>

char sir [ 21 ] [ 7000 ] ;

int main ( )
{
	freopen ( "sirul.in", "r", stdin ) ;
	freopen ( "sirul.out", "w" , stdout ) ;
	
	int n , i ;
	
	scanf ( "%d" , & n ) ;
	
	sir[1][0]='a';
	sir[2][0]='b';
	
	for ( i = 3; i <= n; ++ i )
	{
		strcat ( sir[i], sir[i-1] ) ;
		strcat ( sir[i] , sir[i-2] ) ;
	}
	printf ( "%s", sir[n] ) ;
	
	return 0 ; 
}