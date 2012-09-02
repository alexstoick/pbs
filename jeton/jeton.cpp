#include <cstdio>

const int NMAX = 1<<16;
int f1 [NMAX], f2 [NMAX];

int main ( )
{
	
	freopen ( "jeton.in","r",stdin ) ;
	freopen ( "jeton.out","w",stdout ) ;
	
	int n, m , i , min , max , x ;
	int max2,max1,min1,min2;
	int nr1,nr2;
	
	scanf ("%d%d", &n, &m ) ;
	
	max1=max2=max = -1;
	min1=min2=min = 50005;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d", & x );
		++f1[x];
		if ( x > max1 )
			max1=x;
		if ( x < min1 )
			min1=x;
	}
	
	for ( i = 1 ; i <= m ; ++ i )
	{
		scanf ( "%d" , & x ) ;
		++f2[x] ;
		if ( x > max2 )
			max2=x;
		if ( x < min2 )
			min2=x;
		if ( f1[x] )
		{
			if ( x < min )
				min=x;
			if ( x > max )
					max=x;
		}
	}
	printf ( "%d %d ", min , max ) ;
	
	for ( i = min ; i <= max ; ++ i )
		f1[i]=f2[i]=0;
	
	nr1=nr2=0;
	
	for ( i = min1 ; i <= max1 ; ++ i )
		if ( f1[i] )
			++nr1;
	for ( i = min2; i <= max2 ; ++ i )
		if ( f2[i] )
			++nr2;
	if ( nr1 > nr2 )
		printf ( "1" ) ;
	else
		if ( nr2 > nr1 )
			printf ( "2" ) ;
		else
			printf ( "0" ) ;
	return 0 ;
}
