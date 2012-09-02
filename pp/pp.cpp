#include<cstdio>
#include<cmath>

inline int p10 ( int put )
{
	if ( put == 0 )
		return 1 ;
	return 10*p10(put-1);
}

int reverse ( int n )
{
	
	int nr = 0 ;
	
	while ( n )
	{
		nr = nr*10 + n%10;
		n/=10;
	}
	return nr ;
}

int prim ( int n )
{
	int i ;
	int lim = (int)sqrt ( n ) ;
	for ( i = 2 ; i <= lim ; ++ i ) 
		if ( n % i == 0 )
			return 0 ;
	return 1 ;
}

int nrci ( int n )
{
	int p = 1 , nrc = 0 ;
	
	while ( p <= n )
	{
		p*=10;
		++nrc;
	}
	return nrc;
}

int main ( )
{
	
	freopen ( "pp.in4" , "r" , stdin ) ;
	freopen ( "pp.out" , "w" , stdout ) ;
	
	int nrnr=0,NR , a , p , pi , pf , exp = 0 , nr , i , nrcif  ;
	
	scanf ( "%d", & a ) ;
	
	p = 1 ;
	
	while ( p < a )
	{
		p*=10;
		++exp;
	}
	
	nrcif = (exp+1)/2;
	

	if ( a <= 10 )
	{
		if ( a >= 7 )
		{
			printf ( "4" ) ;
			return 0 ;
		}
		if ( a >= 5 )
		{
			printf ( "3" ) ;
			return 0 ;
		}
		if ( a >= 3 )
		{
			printf ( "2" ) ;
			return 0 ;
		}
		if ( a >= 2 )
		{
			printf ( "1" ) ;
			return 0;
		}
		return 0 ;
	}
	nrnr=4;
	
	for ( NR = 2 ; NR <= exp ; ++ NR )
	{
		
		nrcif = (NR+1)/2;
		pi = p10 ( nrcif - 1  ) ;
		pf = p10 ( nrcif ) - 1 ;
		for ( i = pi ; i <= pf ; ++ i )
		{
			nr = i * 10*pi ;
			if ( NR % 2 )
			{	
				nr/=10;
				nr+= (reverse(i)%pi);
			}
			else
				nr+=reverse(i);
			if ( nr > a )
			{
				printf ( "%d\n" , nrnr ) ;
				return 0 ;
			}
			if ( prim ( nr ) )
				++nrnr;
		}
		
	}
	
	printf ( "%d\n" , nrnr ) ;
	
	return 0 ;
}
