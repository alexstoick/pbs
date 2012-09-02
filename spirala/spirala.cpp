#include<cstdio>

const int NMAX = 105 ;

int x [NMAX][NMAX] ;

int inline min ( int x , int y )
{
	if ( x > y )
		return y;
	return x ;
}

int main ( )
{
	
	freopen ( "spirala.in", "r" , stdin ) ;
	freopen ( "spirala.out", "w", stdout ) ;
	
	int n , m ;
	int i , j , ant , dif ;
	int patrat ;
	
	scanf ( "%d%d", & n , & m ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		for ( j = 1 ; j <= m ; ++ j )
			scanf ( "%d" , & x[i][j] ) ;
		
	int maxP = (min ( n ,m )+1) /2;
	int total = n*m , nrelem ;
	dif = x[1][2] - x[1][1] ;
	nrelem = 0 ;
	for ( patrat = 0 ; patrat < maxP ; ++ patrat )
	{
		i = patrat + 1 ;
		j = patrat + 1 ;
		ant = x[i][j] - dif ;
		for ( ; j <= m - patrat ; ++ j )
			if ( x[i][j] - ant == dif )
			{
				ant = x[i][j] ;
				++nrelem;
			}
			else
			{
				printf ( "NU\n%d %d" , ant , x[i][j] ) ;
				return 0 ;
			}
		if ( nrelem == total )
		{
			printf ( "DA\n%d" , ant ) ;
			return 0 ;
		}
		i = patrat + 2 ;
		-- j ;
		for ( ; i <= n - patrat ; ++ i )
			if ( x[i][j] - ant == dif )
			{
				ant = x[i][j] ;
				++nrelem;
			}
			else
			{
				printf ( "NU\n%d %d" , ant , x[i][j] ) ;
				return 0 ;
			}
		if ( nrelem == total )
		{
			printf ( "DA\n%d" , ant ) ;
			return 0 ;
		}
		-- i ;
		j = m - patrat -1 ;
		for ( ; j >= patrat +1 ; -- j )
			if ( x[i][j] - ant == dif )
			{
				ant = x[i][j] ;
				++nrelem;
			}
			else
			{
				printf ( "NU\n%d %d" , ant , x[i][j] ) ;
				return 0 ;
			}
		if ( nrelem == total )
		{
			printf ( "DA\n%d" , ant ) ;
			return 0 ;
		}
		++ j; 
		i = n - patrat - 1 ;
		for ( ; i > patrat+1 ; -- i )
			if ( x[i][j] - ant == dif )
			{
				ant = x[i][j] ;
				nrelem++;
			}
			else
			{
				printf ( "NU\n%d %d" , ant , x[i][j] ) ;
				return 0 ;
			}
	}
	printf ( "DA\n%d" , ant ) ;
	
	return 0 ;
}
