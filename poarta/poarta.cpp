#include<cstdio>

const int P = 997 ;

struct PUNCT { int x , y ; } ;

int inline abs ( int x )
{
	if ( x > 0 )
		return x;
	return -x ;
}

int mat [ 101 ] [ 101 ] ;

int calc ( PUNCT start , PUNCT fin )
{
	
	int n ;
	n = abs ( start.y - fin.y ) +1;
	int m ; 
	m = abs ( start.x - fin.x ) +1;
	int i , j ;
	
	for (  j = 1 ; j <= m ; ++ j )
		mat[1][j] = 1 ;
	for ( i = 2 ; i <= n ; ++ i )
	{
		mat[i][1] = 1 ;
		for ( j = 2 ; j <= m ; ++ j ) 
			mat[i][j] = ( ( mat[i-1][j]%P ) + ( mat[i][j-1]%P ) ) % P ;
	}
	
	return mat [n][m] ;
}


int main ( )
{
	
	freopen ( "poarta.in", "r", stdin  );
	freopen ( "poarta.out", "w", stdout ) ;
	
	int N , M , k ;
	PUNCT start , fin , poarta ;
	int numar1 , numar2 , min1 , min2 , NUMAR , numar , dist , dist1 ;
	int i ;
	scanf ( "%d%d%d", & N , & M , & k );
	
	scanf ( "%d%d%d%d" , &start.x , & start.y , &fin.x , & fin.y ) ;
	
	min1 = min2 = 1000005 ;
	
	for ( i = 1 ; i <= k ; ++ i )
	{
		scanf ( "%d%d", &poarta.x , & poarta.y ) ;
		dist = abs ( start.x - poarta. x ) + abs ( start.y - poarta.y ) ;
		if ( dist < min1 )
		{
			min1 = dist ;
			numar1 = calc ( start , poarta ) ;
			numar1 %= P ;
		}
		else 
			if ( dist == min1 )
			{
				numar1 += calc ( start , poarta ) ;
				numar1 %= P ;
			}
		dist = abs ( fin.x - poarta.x ) + abs ( fin.y - poarta.y ) ;
		if ( dist < min2 )
		{
			min2 = dist ;
			numar2 = calc ( fin , poarta ) ;
			numar2 %= P ;
		}
		else
			if ( dist == min2 )
			{
				numar2 += calc ( fin , poarta ) ;
				numar2 %= P ;
			}
	}
	
	dist = abs ( start.x - fin.x ) + abs ( start.y - fin.y ) ;
	dist1 = min1 + min2 + 1 ;
	numar = calc ( start , fin ) ;
	NUMAR = ((numar1)*(numar2)) %P ;
	
	if ( dist < dist1 )
	{
		printf ( "%d\n%d", dist , numar ) ;
	}
	else
		if ( dist == dist1 )
		{
			printf ( "%d\n%d" , dist1 , (NUMAR + numar) % P ) ;
		}
		else
			printf ( "%d\n%d" , dist1 , NUMAR ) ;
			
	
	return 0 ;
}
