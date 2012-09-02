#include<cstdio>

int inline pow ( int n , int put )
{
	if ( put == 1 )
		return n ;
	return pow ( n , put-1 ) * n ;
}

int main ( )
{
	freopen ( "felinare.in","r",stdin ) ;
	freopen ( "felinare.out","w",stdout ) ;
	
	int n;
	
	scanf ( "%d", & n ) ;
	
	printf ( "%d", pow ( 2 , n ) - 1 ) ;
	
	
	return 0 ;
}