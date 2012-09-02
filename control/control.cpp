#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int x [ 1 << 7 ] , y [ 1 << 7 ] ;

int prim ( int n )
{
	int lim = (int)sqrt ( (double)n ) ;
	for ( int d = 2 ; d <= lim ; ++ d )
		if ( n % d == 0 ) 
			return 0 ;
	return 1 ;
}

int main ( ) 
{

	freopen ( "control.in" , "r" , stdin ) ;
	freopen ( "control.out" , "w" , stdout ) ;

	int n , i  , u , nr1 , nrz , nr , paritate ;
	nrz = nr1 = nr = 0 ;
	
	scanf ( "%d" , & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		scanf ( "%d", & x[i] ) ;
	
	sort ( x + 1 , x + 1 + n ) ;
	
	u = 0 ;
	for ( i = 1 ; i <= n ; ++ i )
	{
		nr = 1 ;
		while ( x[i+1] == x[i] )
		{
			++i;++nr;
		}
		y[++u]=nr;
	}
	
	for ( i = 1 ; i+2 <= u ; i+=3 )
	{
		
		paritate = y[i]%2 + y[i+1]%2 + y[i+2]%2;
		if ( paritate == 0 || paritate == 3 )
			nr1 ++ ;
		else
			nrz++;
	}
	if ( nr1 != 0 )
	printf ( "%d%d\n", nr1 , nrz ) ;
	else
		printf ( "%d\n" , nrz ) ;
	printf ( "%d", prim ( nr1*10+nrz ) ) ;
	return 0 ;
}
