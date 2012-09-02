#include<cstdio>
#include<cmath>

char cuvant [25] , punct ;

bool prim ( int n ) 
{
	int i ;
	int lim = sqrt ( n ) ;
	for ( i = 2 ; i <= lim ; ++ i )
		if ( !(n%i) )
			return false ;
	return true ;
}

int main ( )
{
	
	freopen ( "qq.in", "r", stdin );
	freopen ( "qq.out", "w", stdout ) ;
	
	int i , numar ;
	
	for ( i = 2 ; i <= 200 ; ++ i )
		if ( prim ( i ) )
			printf ( "%d, " , i ) ;
	
	return 0 ;
	
}
