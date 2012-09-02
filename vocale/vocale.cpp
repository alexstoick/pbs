#include<cstdio>
#include<cstring>

char s[260] , cuv [ 260 ] , CUVANT [255][260] ;
char cuvant [255][255];
int numar [ 255 ] ;

int vocala ( char litera )
{
	return ( litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u' ) ;
}

int main ()
{
	
	freopen ( "vocale.in", "r", stdin ) ;
	freopen ( "vocale.out", "w", stdout ) ;
	
	int n , propozitie , i , max ,uCuv , nrV , U , j;
	bool fine ;
	scanf ( "%d ", & n ) ;
	
	for ( propozitie = 1 ; propozitie <= n ; ++ propozitie )
	{
		gets ( s ) ;
		max = 1500;
		U=0;
		i=0;
		while ( s[i] == ' ' ) 
			++i;
		for ( ; s[i] ; )
		{
			nrV = 0 ;
			uCuv = -1 ;
			while ( 'a' <= s[i] && s[i] <= 'z' )
			{
				cuv[++uCuv]=s[i];
				nrV += vocala ( s[i] ) ;
				++ i;
			}
			cuv[++uCuv]=0;
			if ( nrV == max )
			{
				fine = true ;
				for ( j = 1 ; j <= U && fine ; ++ j )
					if ( strcmp ( cuvant[j] , cuv ) == 0 )
						fine = false;
				if ( fine )
				{
					++numar[propozitie];
					strcpy ( cuvant[++U] , cuv ) ;
				}
			}
			else 
				if ( nrV < max )
				{
					numar[propozitie]=1;
					max=nrV;
					strcpy ( CUVANT[propozitie] , cuv ) ;
					strcpy ( cuvant[1] , cuv ) ;
					U = 1 ;
				}
			while ( s[i] == ' ' )
				++i;
		}
	}
	int produs = 1 ;
	for ( i =1 ; i < n ; ++ i )
	{
		printf ( "%s ", CUVANT[i] ) ;
		produs = ( produs * numar[i] ) % 2003 ;
	}
	printf ( "%s", CUVANT[n] ) ;
	produs = ( produs * numar[n] ) % 2003 ;	
	printf ( "\n%d", produs ) ;
	
	return 0 ;
}
