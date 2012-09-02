#include<cstdio>

int cmmdc ( int a , int  b ) 
{
	int r = b  ;
	while ( r )
	{
		r = a % b ;
		a = b ;
		b = r ;		
	}
	return a ; 
}

int main ( ) 
{
	
	freopen ( "desen2.in","r", stdin ) ;
	freopen ( "desen2.out","w",stdout);
	
	int n , m ;
	
	scanf ( "%d%d", & n , & m ) ;
	
	int x = cmmdc ( n,m ) ;
	if ( x != 1 )
		printf ( "%d\n%d", n*m/x , n/x * m /x ) ;
	else
		printf ( "%d\n%d", n*m , n*m ) ;
	
	return 0 ;
}
