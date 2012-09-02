#include<fstream>
#include<cmath>
#include<values.h>

using namespace std;

ifstream in ( "expo.in" ) ;
ofstream out ( "expo.out" ) ;

long long h , w , n ;

bool ok ( long long L )
{
	if ( L/h >= n )
		return true ;
	if ( L/w >= n  )
		return true ;
	return ( ( (long long)(L/h) * (L/w) ) >= n ) ;
}

long long caut ( ) 
{
	long long i , pas = (1LL<<62);//LLONG_MAX ;
	
	for ( i = 0 ; pas ; pas >>= 1 )
		if ( ! ok ( i + pas ) )
			i += pas ;
	return i + 1;
}

int main ( )
{
	
	in >> h >> w >> n ;
	
	out << caut ( ) ;
	
	return 0 ;
}
