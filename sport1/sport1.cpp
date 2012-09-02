#include<cstdio>

int inline max ( int x , int y )
{
	if ( x > y )
		return x ;
	return y ;
}

int main ( )
{
	
	freopen ( "sport1.in","r",stdin ) ;
	freopen ( "sport1.out" , "w" , stdout ) ;
	
	int a , b , n ;
	int sum = 0 ;
	int nrconc , c ;
	
	scanf ( "%d%d%d", & a , & b , & n ) ;
	
	sum = a+b;
	nrconc = 2 ;
	while ( nrconc < n )
	{
		
		if ( a == b && a == 5 )
		{
			a=b;
			b=2;
			sum+=2;
		}
		else
		if ( a != b )
		{
			c = max ( a , b ) ;
			a=b;
			b=c;
			sum += c ;
		}
		else
			if ( a == b && ( a == 3 || a == 4 ) )
			{
				a = b ;
				b=3;
				sum+=3;
			}
		nrconc++;
	}
	
	double qq = sum*1.000 / n ;
	
	qq-=0.01;
	
	printf ( "%.2lf" , qq ) ;
	
	return 0 ;
}