#include<cstdio>

const int NMAX = 1<<9;
short int x[NMAX][NMAX], y[NMAX][NMAX];
int f[NMAX];

inline int max ( int x, int y ) 
{
	if ( x > y )
		return x;
	return y ;
}

inline int min ( int x , int y )
{
	if ( x > y )
		return y ;
	return x ;
}

int main ( )
{
	
	int n , m , i , j , nr , q , k , t ;
	int maxx = -1, qq;
	freopen ( "simetric.in" , "r" , stdin ) ;
	freopen ( "simetric.out" , "w" , stdout ) ;
	
	scanf ( "%d%d" , &n, &m ) ;
	
	for ( i = 1 ; i <= n; ++ i )
		for ( j=1; j <= m; ++ j )
			scanf ( "%d" , & x[i][j] ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		y[i][1]=1;
	for ( j = 1 ; j <= m ; ++ j )
		y[1][j]=1;
		
	for ( i = 2; i <= n ; ++ i )
		for ( j = 2 ; j <= m ; ++ j )
		{
			if ( i== n && j == 6 ) 
				nr=0;
			q = y[i-1][j-1];
			nr=0;
			for ( k = i-1, t=j-1, qq=1 ; k>0 && t>0 && qq <=q; ++qq, -- k, --t )
				if ( x[i][t] == x[k][j] )
					++nr ;
				else
					break;
			y[i][j] = nr + 1;
			++f[y[i][j]];
			maxx = max ( maxx , y[i][j] ) ;
		}
	/*for ( i = 1 ; i <= n ; ++ i )
	{
		for ( j = 1 ; j <= m ; ++ j )
			printf ( "%d ", y[i][j] ) ;
		printf( "\n");
	}*/
	f[1]+=m+(n-1);

	for ( i = maxx ; i >= 1 ; -- i )
		f[i]+=f[i+1];
	
	for ( i = 1 ; i <= maxx ; ++ i )
		printf ( "%d\n" , f[i] ) ;
	
	
	return 0 ;
}
