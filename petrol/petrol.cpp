#include<cstdio>

int n  ; 
double E , D ;

int main ( )
{
	
	freopen ( "petrol.in", "r", stdin ) ;
	freopen ( "petrol.out", "w", stdout ) ;

	int i ;
	int cont1,cont2,mine1=1001,mine2=1001,mind1=1001,mind2=1001;
	int e , d ;
	double s1 , s2 ;
	
	scanf ( "%d%lf%lf", & n , & E , & D ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d%d" , &e , &d ) ;
		if ( e < mine1 )
		{
			mine2=mine1;
			mine1=e;
			cont1=i;
		}
		else
			if ( e < mine2 )
				mine2=e;
		if ( d < mind1 )
		{
			mind2=mind1;
			mind1=d;
			cont2=i;
		}
		else
			if ( d < mind2 )
				mind2=d;
		
	}
	
	if ( cont1 == cont2 && mine1!=mine2 && mind1 !=mind2 )
	{
		s1=(double)E/mine1 + (double)D/mind2;
		s2=(double)E/mine2 + (double)D/mind1;
		if ( s1 > s2 )
			printf ( "%.3lf",s1);
		else
			printf ( "%.3lf",s2);
	}
	else
	{
		s1 = (double)E/mine1+(double)D/mind1;
		printf ( "%.3lf",s1);
	}
	
	return 0 ;

}
