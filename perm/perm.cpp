#include<cstdio>

int a [ 2 ] [ 202 ] [ 200 ] , rezultat [ 200 ] ;
int q [ 2 ] [ 200 ] ;

int inline min ( int a , int b )
{
	if ( a > b ) 
		return a ;
	return b ;
}

int inline max ( int a , int b ) 
{
	if ( a > b )
		return a;
	return b ;
}

void adunare ( int x[] , int y[] , int z[] )
{
	int i , t ;
	int minim = min ( x[0] , y[0] ) ;
	int maxim = max ( x[0] , y[0] ) ;
	for ( i = 1 ; i <= maxim ; ++ i )
		z[i]=x[i]+y[i];
	t=0;
	for ( i = 1 ; i <= maxim ; ++ i )
	{
		z[i]=z[i]+t;
		t=z[i]/10;
		z[i]%=10;
	}
	if ( t == 1 )
	{
		z[maxim+1]=1;
		z[0]=maxim+1;
	}
	else
		z[0]=maxim;
}

void inmultire ( int x[] , int N , int y[] )
{
	int i , t = 0 ;
	for ( i = 1 ; i <= x[0] ; ++ i )
		y[i]=x[i]*N;
	for ( i = 1 ; i <= x[0] ; ++ i )
	{
		y[i]+=t;
		t=y[i]/10;
		y[i]%=10;
	}
	y[0]=x[0];
	while ( t )
	{
		y[++y[0]] = t%10 ;
		t/=10;
	}
}
int k ;
void afisare ( int lin )
{
	for ( int i = 1 ; i <= k ; ++ i )
		printf ( "%d " , q[lin][i] ) ;
	printf ( "\n" ) ;
}

void init ( )
{
	for ( int i = 1 ; i <= rezultat[0]; ++ i )
		rezultat [i] = 0 ;
}

int main ( )
{
	freopen ( "perm.in" , "r" , stdin ) ;
	freopen ( "perm.out" , "w" , stdout ) ;
	
	int n , i , j , h;
	
	scanf ( "%d%d" , & n , & k ) ;
	
	a[1][1][0]=1;
	a[1][1][1]=1;

	for ( i = 2 ; i <= n ; ++ i )
	{
		for ( j = 1 ; j <= k ; ++ j )
		{
			inmultire ( a[1-i%2][j] , i-1 , rezultat ) ;
			adunare ( a[1-i%2][j-1] , rezultat , a[i%2][j] ) ;
			init ( ) ;
			//a[i%2][j]= a[1-i%2][j-1] + a[1-i%2][j] * (i-1) ;
			/*for ( h = 1 ; h <= a[i%2][j][0] ; ++ h )
				printf ( "%d" , a[i%2][j][h] ) ;
			if ( a[i%2][j][0] == 0 )
				printf ( "0 " ) ;
			printf ( " " ) ;*/
		}
		//printf ( "\n" ) ;
	}
	//printf ( "qq:" ) ;
	for ( i=a[n%2][k][0] ; i >= 1 ; -- i )
		printf ( "%d" , a[n%2][k][i] ) ;
	/*printf ( "\n" ) ;
	q[1][1]=1;
	afisare ( 1 ) ;
	for ( i = 2 ; i <= n ; ++ i )
	{
	
		for ( j = 1 ; j <= k ; ++ j )
			q[i%2][j]= q[1-i%2][j-1] + q[1-i%2][j] * (i-1) ;
		afisare ( i % 2 ) ;
	}
*/
	
	return 0 ;
}
