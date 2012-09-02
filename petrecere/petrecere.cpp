#include<cstdio>

int a [ 3 ] [ 3003 ] ;

int inline max ( int x , int y )
{
	if ( x > y ) 
		return x ;
	return y ;
}

void adunare ( int X[] , int Y[] , int Z[] )
{
	int lung = max ( X[0] , Y[0] ) ;
	int t = 0 , i ;
	
	for ( i = 1 ; i <= lung ; ++ i )
	{
		Z[i]=X[i]+Y[i]+t;
		t=Z[i]/10;
		Z[i]%=10;
	}
	Z[0]=lung;
	if ( t )
	{
		Z[++Z[0]]=t;
	}
}

void inmultire ( int N , int X[] ,int Y[] )
{
	int i , t = 0 , u;
	for ( i = 1 ; i <= X[0] ; ++ i )
	{
		Y[i]=X[i]*N+t;
		t=Y[i]/10;
		Y[i]%=10;
	}
	Y[0]=X[0];
	if ( t )
	{
		u=Y[0];
		Y[++u]=t;
		while ( Y[u] > 9 )
		{
			Y[++u]=Y[u-1]/10;
			Y[u-1]%=10;
		}
		Y[0]=u;
	}
}

int main ( )
{
	freopen ( "petrecere.in" , "r", stdin ) ;
	freopen ( "petrecere.out", "w", stdout ) ;
	
	int n , i  ;
	
	scanf ( "%d" , & n ) ;
	
	a[2][0] = 1 ;
	a[2][1] = 2 ;
	a[1][0] = a[1][1] = 1 ;
		
	for ( i = 3 ; i <= n ; ++ i )
	{
		inmultire ( i-1 , a[(i-2)%3] , a[i%3]) ;
		adunare ( a[i%3] , a[(i-1)%3] , a[i%3] ) ;
	}
	
	for ( i = a[n%3][0] ; i >= 1 ; -- i )
		printf ( "%d" , a[n%3][i] ) ;
	
	return 0 ;
}
