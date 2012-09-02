#include<cstdio>

const int NMAX = 1<<9;

int c [NMAX] , v[NMAX];

int main ( )
{
	
	freopen ( "bursa.in", "r", stdin ) ;
	freopen ( "bursa.out","w",stdout ) ;
	
	int max = 1 , maxi = -1 , maxj = -1  , n , b , i , j;
	int cat , crt ;
	scanf ( "%d%d", & n , & b ) ;
	max=b;
	for ( i = 1 ; i <= n ; ++ i )
		scanf ( "%d", & c[i] ) ;
	for ( i = 1 ; i <= n ; ++ i )
		scanf ( "%d", & v[i] ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		for ( j = i+1 ; j <= n ; ++ j )
		{
			cat=b/c[i];
			crt=b-cat*c[i]+cat*v[j];
			if ( crt > max )
			{
				max=crt;
				maxi=i;
				maxj=j;
			}
		}
	
	printf ( "%d\n%d %d", max , maxi , maxj ) ;
	
	
	return 0 ;
}