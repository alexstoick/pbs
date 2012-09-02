#include<cstdio>

int inline abs ( int x )
{
	if ( x < 0 )
		return -x ;
	return x ;
}

int main () 
{
	
	freopen ( "grupe1.in", "r", stdin ) ;
	freopen ( "grupe1.out", "w", stdout ) ;
	
	int n , grupe , val , first , i , b ,f , x;
	bool ok ;
	char s [ 250 ] ;
	
	scanf ( "%d%d ", & n , & grupe ) ;
	
	gets ( s ) ;
	
	ok = true ;
	first = 0 ;
	
	for ( ; grupe ; -- grupe )
	{
		scanf ( "%d" , & val ) ;
		if ( first )
		{
			if ( abs ( first - val ) > 1 )
				ok = false ;
		}
		else
			first = val ;
		b=f=0;
		for ( i = 1 ; i <= val ; ++ i )
		{
			scanf ( "%d", & x ) ;
			if ( s[x-1] == 'b' )
				++b ;
			else
				++f ;
		}
		if ( abs ( b - f ) > 1 )
			ok = false ;
		printf ( "%d %d\n", b , f ) ;
	}
	
	if ( ok )
		printf ( "DA\n" ) ;
	else
		printf ( "NU\n" ) ;
	
	
	
	return 0 ;
}
