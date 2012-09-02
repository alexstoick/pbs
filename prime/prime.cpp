#include<cstdio>

int NMAX = 65000 ;

int prim [1<<17] , p [1<<12];

void ciur ( )
{
	int i , j;
	for ( i = 2 ; i*i <= NMAX ; ++ i )
		if ( !prim[i] )
			for ( j = i*i ; j <= NMAX ; j += i )
				prim[j]=1;
}

int main ( )
{
	
	freopen ( "prime.in","r", stdin ) ;
	freopen ( "prime.out","w",stdout ) ;
	
	int nr = 0 , i , u = -1 ;
	
	char s [ 1<<12 ];
	
	gets ( s ) ;
	ciur ( ) ;
	for ( i = 2 ; u <= 3005 ; ++ i )
		if ( !prim[i] )
			p [ ++u ] = i ;
	
	for ( i = 0 ; s[i] ; ++ i )
		if ( s[i] == '1' )
			nr += p[i] ;
	
	printf ( "%d\n", nr ) ;
		
	return 0 ;
}
