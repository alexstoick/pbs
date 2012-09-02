#include<cstdio>

int main ( )
{
	
	freopen ( "concurs3.in","r",stdin);
	freopen ( "concurs3.out","w",stdout);
	
	int H , n , ors = 0 , scl = 0 , ok , x , i ;
	
	scanf ( "%d%d", & H , & n ) ;
	
	int sc = ( H / 10 ) % 10 , oras = H / 100 ;
	
	ok=0;
	
	for ( i = 1 ; i <= n ; ++ i ) 
	{
		scanf ( "%d", & x ) ;
		if ( x == H )
			ok=1;
		if ( x / 100 == oras )
		{
			ors ++ ;
			if ( (x/10)%10 == sc )
				++scl ;
		}
	}
	
	if ( ok )
		printf ( "DA\n" ) ;
	else
		printf ( "NU\n" ) ;
	printf ( "%d\n%d", ors , scl ) ;
	
	return 0 ;
}