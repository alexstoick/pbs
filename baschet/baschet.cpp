#include<cstdio>

const int NMAX = 1 << 7 ;
int x [ NMAX];

int main ( ) 
{
	
	freopen ( "baschet.in" , "r" , stdin ) ;
	freopen ( "baschet.out" , "w" , stdout ) ;
	
	int n , i , l , lmax , suma = 0 , start ;
	
	scanf ( "%d" , & n ) ;
	
	for ( i =1 ; i <= n ; ++ i )
		scanf ( "%d", & x[i] ) ;
	
	l = 0 ;
	lmax = 0 ;
	start = 1 ;
	
	for ( i = 2 ; i <= n ; ++ i )
		if ( x[i-1] == x[i] )
			++l;
		else
			if ( l > lmax )
			{
				lmax=l;
				suma = (l+1)*x[i-1];
				printf ( "%d %d", lmax+1 , suma ) ;
				return 0 ;
			}
	if ( l > lmax )
	{
		lmax=l;
		suma=(l+1)*x[i-1];
	}
	if ( suma == 0 )
		suma = x[1];
	printf ( "%d %d" , lmax+1 , suma ) ;
	
	
	return 0 ;
}