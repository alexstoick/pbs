#include<cstdio>

int x[2001], b[2001],c[2001] ;
int fin [ 2001 ] ;
char rez [ 5001 ] ;
int main ( )
{
	
	freopen ( "bile3.in", "r", stdin ) ;
	freopen ( "bile3.out", "w", stdout ) ;
	
	int n , i , ub = 0 , uc = 0 , currentX , currentF ;
	int U = -1 ;
	
	scanf ( "%d" , & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		scanf ( "%d" , & x[i] ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		scanf ( "%d", & fin[i] ) ;
	
	currentX = 1 ;
	currentF = 1 ;
	
	while ( currentX <= n )
	{
		while ( b[ub] == fin[currentF] && ub>0 && currentF <= n )
		{
			//printf ( "O" ) ;
			rez[++U]='O';
			c[++uc]=b[ub];
			--ub;
			++currentF;
		}
		
		if ( x[currentX] == fin[currentF] )
		{
			rez[++U]='I';
			rez[++U]='O';
			//printf ( "IO" ) ;
			c[++uc]=x[currentX];
			++currentX;
			++currentF;
		}
		else
		{
			//printf ( "I" ) ;
			rez[++U]='I';
			//adaugam in B
			b[++ub]=x[currentX];
			++currentX;
		}
	}
	while ( b[ub] == fin[currentF] && ub>0 && currentF <= n )
	{
		//printf ( "O" ) ;
		rez[++U]='O';
		c[++uc]=b[ub];
		--ub;
		++currentF;
	}
	
	if ( currentF == n+1 )
		printf ( "%s" , rez ) ;
	else
		printf ( "imposibil\n", rez ) ;
	
	return 0 ;
}
