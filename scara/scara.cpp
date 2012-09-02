#include<cstdio>

int main ( )
{
	
	freopen ( "scara.in","r",stdin ) ;
	freopen ( "scara.out","w",stdout ) ;
	
	int n ;
	
	scanf ( "%d", & n ) ;
	
	if ( n % 4 == 0 )
		if ( n / 4 % 2 == 0 ) //par
			printf ( "%d %d" , n/4-1 , n/4-1 ) ;
		else
			printf ( "%d %d" ,  n/4 + 2 , n /4-1 ) ;
	else
	{

		if ( n / 4 % 2  ) //par
			printf ( "%d %d", n/4 + 4 - n%4 , n / 4) ;
		else
			printf ( "%d %d", n/4 + n%4 - 1 , n / 4 ) ;
	}
	
	
	
	
	return 0 ;
}