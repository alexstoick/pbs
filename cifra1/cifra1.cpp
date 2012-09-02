#include<cstdio>

int main ( )
{
	
	freopen ( "cifra1.in","r",stdin ) ;
	freopen ( "cifra1.out","w",stdout );
	
	int n , m ;
	int x [ 15 ] ;
	int u = 0 ;
	int st , dr , i , sum = 0 , aux ;
	
	scanf ( "%d%d", & n , & m ) ;
	
	while ( n )
	{
		x[++u]=n%10;
		n/=10;
	}
	
	st=1;dr=u;
	while ( st < dr )
	{
		aux=x[st];
		x[st]=x[dr];
		x[dr]=aux;
		++st;--dr;
	}
	
	sum = 0;
	i=1;
	while ( sum < m )
	{
		sum += x[i];
		++i;
	}
	printf ( "%d", x[i-1] ) ;
	
	return 0; 
}