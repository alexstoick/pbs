#include<cstdio>

int final [ 65000 ] , initial[50];

int inline putere ( int a , int x )
{
	int b = 1 ;
	for ( int i =1 ; i <= x ; ++ i )
		b=b*a;
	return b ;
}

int main ( )
{
	
	freopen ( "partitie.in" , "r", stdin ) ;
	freopen ( "partitie.out", "w", stdout ) ;
	
	int p , n , i , j , contor , limita ;
	
	scanf ( "%d%d", & p , & n ) ;
	
	for ( i = 1 ; i <= p ; ++ i )
		final[i]=initial[i]=i;
	
	limita = putere ( p , n-1 ) ;
	
	for ( contor = 1 , i = p+1 ; contor < limita ; ++contor ) 
	{
		for ( j = 1 ; j <= p ; ++ j , ++ i )
		{
			final[i]=(initial[j]+contor)%p;
			if ( final[i] == 0 )
				final[i]=p;
		}
	}
	
	limita*=p;
	
	for ( i = 1 ; i <= limita ; ++ i )
		printf ( "%d ", final[i] ) ;
	
	return 0 ;
}