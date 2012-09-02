#include<cstdio>
#include<algorithm>

using namespace std ;
const int NMAX = 100005 ;
const int valoriMAX = 50005 ;
char s [NMAX];
int valori [ valoriMAX ] ; 
int start [ valoriMAX ];
int u ;

void calc1 ( int start )
{
	
	int max = -100 ;
	bool adaugat = false ;
	int S = 0 ;
	int i ;
	for ( i = start ; i <= u ; ++ i )
		if ( S + valori[i] > 0 )
		{
			S+=valori[i] ;
			if ( S > max )
				max=S;
			adaugat = true ;
		}
		else
		{
			if ( adaugat )
				if ( S > max )
					max=S;
			adaugat = false ;
			S=0;
		}
	if ( adaugat )
		if ( S > max )
			max=S;
	if ( max == -100 )
		//toate negative
		for ( i = start ; i <= u ; ++ i )
			if ( valori[i] > max )
				max = valori[i] ;
	valori[start]=max;
	u=start;
}

void calc2 ( int start )
{
	
	sort ( valori + start , valori + u + 1 ) ;
	valori [ start ] = valori [ start+(u-start+2)/2-1 ];
	u=start;
	
}

int main ( )
{
	
	freopen ( "expresie1.in" , "r", stdin ) ;
	freopen ( "expresie1.out" , "w" , stdout ) ;
	
	int i , numar , U=0;
	int uS = 0 ;
	bool adaugat ;
	int negativ ;
	
	gets ( s ) ;
	
	for ( i = 0 ; s[i] ; )
	{
		if ( s[i] == ',' )
			++i;
		switch ( s[i] )
		{
			case '(': { ++i; start[++uS]=u+1; break; } 
			case ')': { ++i; calc1 ( start[uS] ) ; --uS ; break; }
			case '[': { ++i; start[++uS]=u+1; break; }
			case ']': { ++i; calc2 ( start[uS] ) ; --uS ; break ; }
		}
		negativ = 1 ;
		if ( s[i] == '-' )
		{
			negativ = -1;
			++i;
		}
		//formam numarul
		adaugat = false ;
		numar=0;
		while ( '0' <= s[i] && s[i] <= '9' )
		{
			numar = numar*10 + (s[i]-'0') ;
			++i;
			adaugat = true ;
		}
		if ( adaugat )
		{
			valori[++u]=numar*negativ;
			++U;
		}
	}
	
	printf ( "%d", U ) ;
	int  S = 0 ;
	for ( i= 1 ; i <= u ; ++ i )
		S += valori[i] ;
	printf ( "\n%d", S ) ;
	
	
	return 0 ;
}
