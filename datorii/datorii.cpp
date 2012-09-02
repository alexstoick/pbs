#include<cstdio>

const int NMAX = 1 << 16 ;
int partial [NMAX];

int main ( )
{
	
	freopen ( "datorii.in", "r", stdin ) ;
	freopen ( "datorii.out", "w", stdout ) ;
	
	int n , m , i , j , x;
	int cod , a , b ;
	
	scanf ( "%d%d", & n , & m ) ;
	
	for ( i =1 ; i <= n ; ++ i )
	{
		scanf ( "%d", &x ) ;
		partial[i]= partial[i-1]+x;
	}
	
	
	for ( i = 1 ; i <= m ; ++ i )
	{
		scanf ( "%d%d%d" , &cod , &a , &b ) ;
		if ( cod == 0 )
		{
			for ( j = a ; j <= n ; ++ j )
				partial[j]-=b;
		}
		else
			printf ( "%d\n", partial[b]-partial[a-1] ) ;
	}
	
	
	return 0 ;
}