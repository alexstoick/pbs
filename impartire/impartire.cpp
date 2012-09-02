#include<cstdio>

const int NMAX = 100005 ;

unsigned char rest [ NMAX ] ;
unsigned char cif [ NMAX ] ;


int main ( )
{
	
	freopen ( "impartire.in" , "r", stdin ) ;
	freopen ( "impartire.out" , "w" , stdout ) ;
	
	int N , M , nr_zero , u ;
	bool ok ;
	int i ;
	
	scanf ( "%d%d", & N , & M ) ;
	
	//adaugam zerouri pana se ajunge la un numar mai mare decat M
	
	nr_zero = 0 ;
	
	while ( N < M )
	{
		N*= 10;
		++ nr_zero ;
	}
	
	printf ( "0." ) ;
	for ( i = 1 ; i < nr_zero ; ++ i )
		printf ( "0" ) ;
	
	ok = true ;
	u = 0 ;
	bool perioada = false ; 
	int stop ;
	
	while ( ok )
	{
		++u ;
		cif [ u ] = N / M ;
		N%=M;
		if ( !N )
		{
			ok = false ;
			stop=u+1;
		}
		if ( rest[N] && ok )
		{
			perioada = true ;
			stop = rest[N] ;
			ok=false;
		}
		rest[N] = u + 1;
		N*=10;
	}
	if ( cif[1] == cif[u] )
	{
		printf ( "(" ) ;
		for ( i = 1 ; i < u ; ++ i )
			printf ( "%d" , cif[i] ) ;
		printf ( ")\n" ) ;
		return 0 ;
	}
	for ( i = 1 ; i < stop ; ++ i )
		printf ( "%d", cif [i] ) ;
	if ( perioada )
	{
		printf ( "(" ) ;
		for ( ; i <= u ; ++ i )
			printf ( "%d", cif[i] ) ;
		printf ( ")\n" ) ;
	}

	return 0 ;
}
