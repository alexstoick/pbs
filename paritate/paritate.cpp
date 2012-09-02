#include<cstdio>

const int NMAX = 65000 ;
char s[NMAX<<3];
char sir[NMAX];
int vall[NMAX];

const int put2 [10] = { 1 , 2 , 4 , 8 , 16 , 32 , 64 , 128 } ;

int main ( )
{
	//0 - nr par de 1
	//1 - nr IMPAR de 1
	
	freopen ( "paritate.in", "r" , stdin ) ;
	freopen ( "paritate.out" , "w", stdout ) ;
	
	bool corect ;
	int i , nr , val , nr1 , j ;
	int u = -1 ,uv = 0 ;
	scanf ( "%s", s) ;
	corect = true ;
	for ( i = 0 ; s[i] ; i += 8 )
	{
		nr = i/8;
		val=nr1=0;
		if ( i == 8*8128 ) 
			printf ( "" ) ;
		for ( j = 1 ; j <= 7 ; ++ j )
		{
			if(s[j+i]=='1' )
			{
				val += put2 [ 7 - j ] ;
				++nr1;
			}
		}
		if ( (nr1%2) != (s[i]-'0') )
		{
			corect = false ;
			vall[++uv]=nr ;
		}
		sir[++u]=(char)val ;
	}
	if ( corect ) 
		printf ( "DA\n%s" , sir ) ;
	else
	{
		printf ( "NU\n") ;
		for ( i = 1 ; i <= uv ; ++ i )
			printf ( "%d ", vall[i] ) ;
	}
	return 0 ;
	
} 
