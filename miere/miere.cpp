#include<fstream>
#include<cstdio>
//std::ifstream in ( "miere.in" ) ;
//std::ofstream out ( "miere.out" ) ;

const int NMAX = 50005 ;
int n , m , ZI;

int x [ NMAX ] ;

int caut ( long long val )
{
	long long i , pas = 1LL<<16;
	
	if ( val > (long long)x[n] + (long long)n*ZI )
		return n ;
	
	for ( i = 0 ; pas ; pas >>= 1 )
		if ( i+pas <= n && val >= x[i+pas]+(i+pas)*ZI ) 
			i+=pas ;
	return (int)i ;
}

int main ( )
{
	int i ;
	long long val ;
	freopen ( "miere.in" , "r" , stdin ) ;
	scanf ( "%d", & n ) ; //in >> n ;
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%lld", & val ) ;//in >> val ;
		x[i] = x[i-1] + (long long) val ;
	}
	
	scanf ( "%d", & m ) ;//in >> m ;
	ZI = 0 ;
	
	freopen ( "miere.out", "w", stdout ) ;
	
	for ( ; m ; -- m )
	{
		scanf ( "%lld", & val ) ;//in >> val ;
		//out << caut ( val ) << "\n" ;
		printf ("%d\n", caut(val) ) ;
		++ZI;
	}
	
	
	return 0 ;
}
