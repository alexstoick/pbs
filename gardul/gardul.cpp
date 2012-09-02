#include<cstdio>

int cmmdc ( int a , int b )
{
	int r = 1;
	while ( b )
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a ;
}

int main ( )
{
	
	freopen ( "gardul.in", "r", stdin ) ;
	freopen ( "gardul.out", "w" , stdout ) ;
	
	int n , p , q ;
	
	scanf ( "%d%d%d",&n , & p , & q ) ;
	
	int rosii = n/p , alb = n/q , vio = n / ((p*q)/cmmdc ( p,q ) );
	
	printf ( "%d\n" , n - rosii - alb + vio ) ; 
	printf ( "%d\n%d\n%d" , rosii-vio , alb-vio,vio ) ;
	
	return 0 ;
}