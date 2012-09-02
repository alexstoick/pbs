#include<cstdio>

int main ( )
{
	
	freopen ( "cadouri.in" , "r", stdin ) ;
	freopen ( "cadouri.out" , "w",stdout ) ;
	
	int F , B , N , i , x ;
	
	scanf ( "%d%d%d" , &F,&B,&N ) ;
	
	for ( i = 1 ; i <= N ; ++ i )
	{
		scanf ( "%d",&x ) ;
		if ( x % 2 ) 
			--B;
		else
			--F;
	}
	if ( F < 0 ) F = 0 ;
	if ( B < 0 ) B = 0 ;
	printf ( "%d\n%d" , F , B ) ;
	
	return 0 ;
}