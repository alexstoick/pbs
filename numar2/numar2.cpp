#include<cstdio>

bool pali ( int n )
{
	
	int nn = n , nr = 0 ;
	while ( n ) 
	{
		nr = nr*10 + n%10;
		n/=10;
	}
	return nr == nn ;
}

int main ( ) 
{
	
	freopen ( "numar2.in" , "r" , stdin ) ;
	freopen ( "numar2.out", "w",stdout ) ;
	
	int n , i , max =0;
	
	scanf ( "%d", & n ) ;
	
	for ( i = 1 ; i * i * i  <= n ; ++ i )
		if ( pali (i*i*i) )
			max=i;
		
	printf ( "%d", max*max*max ) ;
	
	
	return 0 ;
}