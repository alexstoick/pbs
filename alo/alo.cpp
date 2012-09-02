#include<cstdio>

int main ( )
{
	
	freopen ( "alo.in","r",stdin);
	freopen ( "alo.out","w",stdout);
	
	int n , E , eur, N , min , i ;
	
	scanf ( "%d%d", & E , & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d%d", &N , & min ) ;
		if ( N % 10 == 9 )
			eur=1;
		else
		{
			eur=1;
			if ( N / 10000 == 1 )
				eur=-2;
			E+=eur*min;
		}
		
	}
	
	printf ( "%d", E );
	
	return 0 ;
}