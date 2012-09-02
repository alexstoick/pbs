#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct QQ { 
	char cuv [ 25 ] ; 
	int val ;
};
QQ x[101];
char s[1005];
char cuv[25];

int max ( int a , int b ) 
{
	return a ;
}

bool comp ( QQ a , QQ b )
{
	if ( strcmp ( a.cuv , b.cuv ) < 0 )
		return true ;
	return false;
}

int main ( )
{
	
	freopen ( "reteta.in" , "r" , stdin ) ;
	freopen ( "reteta.out" , "w" , stdout ) ;
	
	int i , numar , uCuv , u = 0 , TIMP = 0 , j ;
	bool gasit ;
	gets ( s ) ;
	
	for ( i = 0 ; s[i] ; )
	{
		//sarim peste spatii si paranteze
		while ( s[i] == '(' || s[i]==' '&& s[i] )
			++i;
		if ( s[i] == ')' )
		{
			++i;
			//cautam numarul
			while ( s[i] == ' ' )
				++i;
			numar = 0 ;
			while ( '0' <= s[i] && s[i] <= '9' && s[i])
			{
				numar = numar*10 + s[i]-'0';
				++i;
			}
			TIMP += numar ;
		}
		if ( 'a' <= s[i] && s[i] <= 'z' )
		{
			//formam cuvantul
			uCuv=-1;
			while ( 'a' <= s[i] && s[i] <= 'z' )
			{
				cuv[++uCuv] = s[i] ;
				++i;
			}
			cuv[++uCuv]=0;
			while ( s[i] == ' ' )
				++i;
			//gasim numarul
			numar = 0 ;
			while ( '0' <= s[i] && s[i] <= '9' && s[i])
			{
				numar = numar*10 + s[i]-'0';
				++i;
			}
			//vedem daca mai exista
			gasit=false;
			for ( j = 1 ; j <= u ; ++ j )
				if ( ! strcmp ( x[j].cuv , cuv ) )
				{
					x[j].val+=numar;
					gasit=true;
					break;
				}
			if ( !gasit ) 
			{
				strcpy(x[++u].cuv , cuv ) ;
				x[u].val=numar;
			}
		}
	}
	printf ( "%d\n" , TIMP ) ;
	
	sort ( x + 1 , x + 1 + u , comp ) ;
	
	for ( i = 1 ; i <= u ; ++ i )
		printf ( "%s %d\n" , x[i].cuv , x[i].val ) ;
	
	return 0 ;
}