#include<cstdio>
#include<cmath>

int a , b , k ;

int rq ( int n ) 
{
	if ( (int)sqrt(n)*(int)sqrt(n) == n )
		return (int)sqrt(n);
	return (int)sqrt(n)+1;
}

int nrdiv ( int n )
{
	int i ;
	int nr = 0 ;
	int lim = (int)sqrt ( n ) ;
	for ( i = 1 ; i <= lim ; ++ i )
		if ( n % i == 0 ) 
			nr ++ ;
	if ( lim == rq (n) )
		++nr;
	return nr;
}

int main ()
{
	
	freopen ( "div.in" , "r" , stdin ) ;
	freopen ( "div.out" , "w" , stdout ) ;
	
	scanf ( "%d%d%d", & a , & b , & k ) ;
	
	int limm = rq ( a ) , limM = rq(b) , nr , i;
	if ( limM*limM > b ) limM -- ;
	nr=0;
	for ( i = limm ; i <= limM ; ++ i )
		if ( nrdiv ( i ) == k+1 )
			++nr;
	printf ( "%d\n" , nr ) ;
	
	return 0 ;
}
