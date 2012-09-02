#include<fstream>

std::ifstream in ( "simpla.in" ) ;
std::ofstream out ( "simpla.out" ) ;

int suma ( int x )
{
	int q = 0 ;
	while ( x )
	{
		q += x%10 ;
		x /= 10 ;
	}
	return q ;
}

int main ( )
{
	int a , b ;
	
	in >> a >> b ;
	if ( a == b )
	{
		out << 1-suma(a)%2 ;
		return 0 ;
	}
	
	if ( a + 2 == b )
		if ( suma(a)%2 == 0 )
		{
			out << "2" ;
			return 0 ;
		}
	int val =0 ;
	if ( b < 10 && a == 0 )
		out << b/2 + 1 ;
	else
		out << (b-a+1)/2 ;
	
	return 0 ;
}
