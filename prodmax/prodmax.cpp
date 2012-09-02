#include <cstdio>

int x [ 1 << 5 ] ;

int form ( int inc , int sf ) 
{
	int nr = 0;
	for ( int i = inc ; i <= sf ; ++ i )
		nr = nr*10 + x[i];
	return nr ;
}

int main ( )
{
	
	freopen ( "prodmax.in", "r" , stdin ) ;
	freopen ( "prodmax.out", "w" , stdout ) ;
	
	int n , u , i , a , b , xm , ym , max = -1 ;
	int st , dr , aux;
	scanf ( "%d" , & n ) ;
	
	u=0;
	while ( n )
	{
		x[++u]=n%10;
		n/=10;
	}
	st=1;
	dr=u;
	while( st < dr )
	{
		aux = x[st];
		x[st]=x[dr];
		x[dr]=aux;
		++st ; --dr;
	}
	
	for ( i = 1 ; i < u ; ++ i )
	{
		a = form ( 1 , i ) ;
		b = form ( i+1 , u ) ;
		if ( a*b > max )
		{
			max=a*b;
			xm = a;
			ym = b ;
		}
	}
	
	printf ( "%d\n%d\n%d" , max , xm , ym ) ;
	
	return 0 ;
}
