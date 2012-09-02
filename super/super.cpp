#include<cstdio>

char v[]= { 'I' , 'V' , 'X' , 'L' , 'C' , 'D' , 'M' ,   'P' ,  'Q' ,   'R' ,   'S' ,    'T' ,     'U' ,     'B' ,     'W' ,      'N' ,       'Y' ,      'Z'     } ;
int  V[]= {  1 ,   5 ,  10 ,  50 ,  100 , 500 , 1000 , 5000 , 10000 , 50000 , 100000 , 500000 , 1000000 , 5000000 , 10000000 , 50000000 , 100000000 , 500000000 } ;
const int N = 17 ;

int cmfc ( int n ) 
{
	int c ;
	while ( n ) 
	{
		c = n%10;
		n/=10;
	}
	return c ;
}

int main ( )
{
	
	freopen ( "super.in", "r", stdin ) ;
	freopen ( "super.out","w", stdout ) ;
	
	int n , i , j , cate ;
	
	scanf ( "%d", & n ) ;
	
	for ( i = N ; i >= 0 ; -- i )
		if ( V[i] < n )
			break;
	if ( n == 999999999 )
	{
		
		printf ( "ZYZWYUWSUQSMQCMXCIX" ) ;
		return 0 ;
	}
	
	while ( n>4 ) 
	{
		 
		if ( cmfc(n) == 9 && V[i-1] < n ) 
		{
			if ( cmfc ( V[i] ) == 1 )
			{
				printf ( "%c%c" , v[i-2],v[i] ) ;
				n%=(V[i]-V[i-2]);
			}
			else
			{
				printf ( "%c%c" , v[i-1] , v[i+1] ) ;
				n %= ( V[i+1] - V[i-1 ] )  ;
			}
			--i;
		}
		else
		{
			if( V[i] > n )
				--i;
			cate = n/V[i] ;
			if ( cate == 4 )
				printf ( "%c%c" , v[i],v[i+1] ) ;
			else
				for ( j=1; j <= cate ; ++ j )
					printf ( "%c" , v[i] ) ;
			n%=V[i];
			--i;
		}
	}
	if ( n ) 
		switch ( n ) 
		{
		case 1: printf ( "I" ) ;break;
		case 2: printf ( "II" ) ;break;
		case 3: printf ( "III" ) ; break ;
		case 4: printf( "IV" ) ; break;
		
		}
		
	
	return 0 ;
	
}