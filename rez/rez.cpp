#include<cstdio>

int u , uS , start [ 1500 ] ;
int val [ 1500 ] ;
char s [ 1500 ] ;

void calc ( int start ) 
{
	
	int V = 1 , SUM = 0 ;
	int i ;
	for ( i = start ; i <= u ; ++ i )
	{
		V *= val[i] ;
		SUM += val[i] ;
	}
	
	val [start] = V/SUM ;
	u=start;
}

int main ( )
{
	
	freopen ( "rez.in", "r", stdin ) ;
	freopen ( "rez.out", "w", stdout ) ;
	
	gets ( s ) ;
	
	int i , numar ;
	bool serie ;
	
	for ( i=0 ; s[i] ; )
	{
		
		switch ( s[i] )
		{
			case '(' : { start[++uS] = u+1 ; ++ i ; break ; } 
			case ')' : { calc ( start[uS] ) ; --uS ; ++ i ; break ; }
		}
		//suntem pe R
		if ( s[i] ) //daca nu a fost ultima paranteza
		{
			++i ; //R sau virgula
			if ( s[i] == 'R' )
				++ i ;
			numar = 0 ;
			while ( '0' <= s[i] && s[i] <= '9' )
			{
				numar = numar*10 + s[i]-'0' ;
				++ i ;
			}	
			if ( ! serie )
				val [ ++ u ] = numar ;
			else
				val [ u ] += numar ;
			if ( s[i] == 'R' || s[i] == '(' ) 
				serie = true ;
		}
		
	}
	
	int SUM = 0 ;
	
	for ( i = 1 ; i <= u ; ++ i )
		SUM += val[i] ; 
	
	printf ( "%d", SUM ) ;
	
	return 0 ;
}

