#include<cstdio>

int a [ 100 ] [ 100 ] ;

int main ( )
{
	
	freopen ( "zero.in", "r", stdin ) ;
	freopen ( "zero.out", "w", stdout ) ;
	
	int l , baza , p , q , i , j ,S ;
	
	scanf ( "%d%d%d%d" , & l , & baza , & p , & q ) ;
	
	a[1][0] = baza -1  ;
	
	for ( i = 1 ; i <= l ; ++ i )
	{
		S = a[i][0] ;
		for ( j = 1 ; j <= l ; ++ j )
		{
			a[i][j] = a[i-1][j-1] ;
			S += (a[i][j]*(baza-1)) ; 
		}
		a[i+1][0] = S ;
		
	}
	int s1 = 0 , s2 = 0 ;
	for ( i = 0 ; i <= p ; ++ i )
		s1 += a[l][i] ; 
	printf ( "%d\n%d" , s1 , S - s1 ) ;
	
	return 0 ;
}