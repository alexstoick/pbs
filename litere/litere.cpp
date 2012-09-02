#include<fstream>
#include<cstdio>

std::ifstream in ( "litere.in" ) ;
std::ofstream out ( "litere.out" ) ;

int f [ 30 ] ;
char s [15000] ;

int main ( )
{
	
	int n , i;
	
	in >> n >> std::ws ;
	in.getline ( s , 10025 );
	out<<sizeof ( f ) ;
	int SUM = 0 , j ;
	
	for ( i = 0 ; s[i] ; ++ i )
	{
		++ f[ s[i] - 'a' ] ;
	
		for ( j = s[i]-'a'+1 ; j <= 25 ; ++ j )
			SUM += f[j] ;
	}
	
	out << SUM ;
	
	return 0 ;
}
