#include<cstdio>

int main ( ) 
{
	
	freopen ( "expresie.in" , "r", stdin ) ;
	freopen ( "expresie.out" , "w", stdout ) ;
	
	int n , i ;
	long long prod , max1 =-1, max1i , max2=-1 , max2i , S = 0 , max = -1 , maxi;
	int x [ 1 << 10 ] ;
	
	scanf ( "%d", & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i ) 
	{
		scanf ( "%d", &x[i] ) ;
		S+= x[i];
	}
	
	S=0;
	
	for ( i = 1 ; i < n ; ++ i )
	{
		prod= (long long)x[i]*x[i+1];
		if ( prod >= max1 )
		{
			max2=max1;
			max2i=max1i;
			max1=prod;
			max1i=i;
		}
		else
			if ( prod > max2 )
			{
				max2=prod;
				max2i=i;
			}
	}
	
	for ( i = 1 ; i < n-1 ; ++ i )
	{
		prod=(long long)x[i]*x[i+1]*x[i+2];
		if ( prod>max )
		{
			max=prod;
			maxi=i;
		}
	}
	if ( max > max1 + max2 )
		max1i=max2i=0;
	else
		maxi=0;
	
	for ( i = 1 ; i <= n ; ++ i )
		if ( i == max2i || i == max1i )
			++i;
		else
			if ( i == maxi )
				i+=2;
			else
				S+=(long long)x[i];
	
	if ( max1i )
		S+=(long long)max1+max2;
	else
		S+=max;
	
	printf ( "%lld", S );
	
	
	
	return 0 ;
}