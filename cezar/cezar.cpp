#include<cstdio>
#include<cstring>

char s [ 270 ] ;
int cheie [ 15 ] ;

int main ( )
{
	
	freopen ( "cezar.in", "r" , stdin ) ;
	freopen ( "cezar.out", "w", stdout ) ;
	
	int i , spatiu = 0 ;
	char nou ;
	int diferenta;
	
	gets ( s ) ;
	
	for ( i = 0 ; i <= 9 ; ++ i )
		scanf ( "%d" , & cheie [i] ) ;
	
	for ( i = 0 ; s[i]; ++ i )
		if ( s[i] == ' ' )
		{
			++spatiu;
		}
		else
		{
			nou = s[i] - cheie [ (i-spatiu)%10 ] ;
			if ( nou < 'A' )
			{
				diferenta = 'A' - nou;
				nou = 'Z' - diferenta+1 ;
			}
			s[i] = nou ;
		}
	printf ( "%s" , s ) ;
	
	
	
	return 0 ;
}