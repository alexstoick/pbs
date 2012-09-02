#include<cstdio>

struct VALORI { int hi , lo ; } ;

VALORI val [ 15005 ] ;
int k ;

int uneste ( )
{
	if ( val[k-1].hi + 1 == val[k].lo )
	{
		val[k-1].hi = val[k].hi;
		--k;
		return 1 ;
	}
	else
		if ( val[k].hi + 1 == val[k-1].lo )
		{
			val[k-1].lo = val[k].lo ;
			--k;
			return 1 ;
		}
	return 0 ;
}


int main ( )
{
	freopen ( "reactii.in", "r", stdin ) ;
	freopen ( "reactii.out" , "w", stdout ) ;
	
	int N , test , i , x ;
	
	scanf ( "%d%d", & N , & test ) ;
	
	for ( ; test ; -- test )
	{
		k=0;
		for ( i = 1 ; i <= N ; ++ i )
		{
			scanf ( "%d", & x ) ;
			val[++k].lo = x ;
			val[k].hi = x ;
			for ( ; k > 1 && uneste ( ) ; ) ;
		}
		if( k == 1 )
			printf ( "1\n" ) ; 
		else
			printf ( "0\n" ) ;
	}
	
	return 0 ;
}
