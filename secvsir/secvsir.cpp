#include<cstdio>
#include<cstring>

char s [ 10000 ] ;
char sir [ 5 ] ;

int conversie ( int n , char sir [] ) 
{
	int usir = -1 , st , dr ;
	char aux ;
	while ( n )
	{
		sir[++usir]=n%10+'0';
		n/=10;
	}
	st=0;
	dr=usir;
	while ( st < dr )
	{
		aux = sir[st];
		sir[st]=sir[dr];
		sir[dr]=aux;
		++st;--dr;
	}
	return usir;
	
}

int main ( )
{
	
	freopen ( "secvsir.in", "r" , stdin ) ;
	freopen ( "secvsir.out", "w", stdout ) ;
	
	int n , i , u , usir , j , contor ;
	bool exista;
	scanf ( "%d", & n ) ;
	
	u = -1 ;
	for ( i = 1 ; i <= n ; ++ i )
	{
		if ( i == 12 )
			printf ( "" ) ;
		usir = conversie ( i , sir ) ;
		exista = false ;
		for ( j = 0 ; j <= u && !exista; ++ j )
			if ( s[j] == sir[0] )
			{
				contor=1;
				while ( s[j+contor] == sir[contor] && sir[contor] )
					++contor;
				if ( contor-1 == usir )
					exista = true ;
			}
		if ( !exista )
		{
			strcat ( s , sir ) ;
			u+=(usir+1);
		}
	}
	
	printf ( "%s" , s ) ;
	
	return 0 ;
}