#include<cstdio>
#include<algorithm>
using namespace std;

const int NMAX = 1 << 15 ;

int f [ NMAX ] , x [ NMAX ] , v [ 1<<4 ] ;

int main ( ) 
{
	
	freopen ( "loto.in" , "r" , stdin ) ;
	freopen ( "loto.out" , "w" , stdout ) ;
	
	int n , i , j , dif , aux ;
	
	scanf ( "%d" , & n );
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d", & x[i] ) ;
		f[x[i]]=1;
	}
	
	for ( i = 1 ; i <= 6 ; ++ i )
	{
		scanf ( "%d" , & v[i] ) ;
		f[v[i]]=-1;
	}
	
	sort ( x + 1 , x + 1 + n ) ;
	sort ( v + 1 , v + 7 ) ;
	x[n+1]=10000;
	aux=0;
	for ( i = 1 ; i <= n ; ++ i )
		if ( x[i] == v[1] )
		{
			j=i-1;
			dif=10000;
			if(j)
			while ( j > 0 && f[x[j]] != 1 ) --j;
			if ( j )
			{
				dif = v[1]-x[j];
				aux=x[j];
			}
			j=i+1;
			while ( f[x[j]] != 1 && j <= n ) 
				++j;
			if ( x[j] - v[1] <= dif )
			{
				v[1]=x[j];
				f[v[1]]=0;
			}
			else
			{
				v[1]=aux;
				f[v[1]]=0;
			}
			break;
		}
	for ( i = 1 ; i <= n ; ++ i )
		if ( x[i]==v[6] )
		{
		j=i-1;
		dif=10000;
		if(j)
		while ( j > 0 && f[x[j]]!= 1 ) 
			--j;
		if (j)
		{
			dif = v[6]-x[j];
			aux=x[j];
		}
		j=i+1;
		while ( f[x[j]]!= 1 && j <= n ) 
			++j;
		if ( x[j] - v[6] <= dif )
			v[6]=x[j];
		else
			v[6]=aux;
		break;
		}
		
	sort ( v + 1 , v + 7 ) ;
	for ( i = 1 ; i <= 6 ; ++ i )
		printf ( "%d " , v[i] ) ;
		
	return 0 ;
}
