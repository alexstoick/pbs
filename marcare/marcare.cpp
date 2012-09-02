#include <cstdio>

const int NMAX = 1 << 9 ;

int f [NMAX], x [NMAX] ;
int n , s , k ;
void inline elim ( int i )
{
	int j ;
	for ( j = i+1; j <= n ; ++ j )
		x[j-1]=x[j];
	x[n]=0;
}

int main ( )
{
	
	freopen ( "marcare.in","r",stdin ) ;
	freopen ( "marcare.out","w",stdout ) ;
	
	int i , q ; 
	
	scanf ( "%d%d%d",&n,&s,&k ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		x[i]=i;
	for ( i = s ; ; i+=k )
	{
		if ( i > n )
			i %= n ;
		if ( f[i] )
			break;
		f[i]=1;
		printf ( "%d ", x[i] ) ;
	}
	q=n;
	for ( i = 1 ; i <= n; ++ i )
		if ( f[i] ) 
			--q;
	printf ( "\n%d" , q ) ;
	
	return 0 ;
}
