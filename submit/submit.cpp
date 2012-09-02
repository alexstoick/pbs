#include<cstdio>

const int NMAX = 1<<7;
int p[NMAX];

int main ( )
{
	
	freopen ( "submit.in", "r",stdin  ) ;
	freopen ( "submit.out" , "w",stdout ) ;
	
	int n , i , bonus , T , teste , ok , S  , x , max = 0 ;
	
	scanf ( "%d", & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		scanf ( "%d", & p[i] ) ;
	
	scanf ( "%d", & bonus ) ;
	
	scanf ( "%d" , & T ) ;
	
	for ( teste = 1 ; teste <= T ; ++ teste )
	{
		S = 0 ;
		ok=1;
		for ( i = 1 ; i <= n ; ++ i )
		{
			scanf ( "%d", & x ) ;
			if ( !x )
				ok = 0;
			S += x*p[i];
		}
		if ( ok )
			S+=bonus;
		S-= (teste-1)*2;
		if ( S > max )
			max=S;
	}
	
	printf ( "%d", max ) ;
	
	return 0 ;
}
