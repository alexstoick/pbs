#include<cstdio>

int g [ 2005 ];
long long rez[2005];
const int INF   = 0x3f3f3f3f;

long long inline min ( long long x , long long y )
{
	if ( x > y )
		return y;
	return x ;
}

long long inline max ( long long x , long long y )
{
	if ( x > y )
		return x ;
	return y;
}

int main ( )
{
	
	freopen ( "gaz.in" , "r", stdin ) ;
	freopen ( "gaz.out", "w", stdout ) ;
	
	long long L , P , D , C , n , i , j , extra , TOTAL = 0 , s = 0 ;
	
	scanf ( "%lld%lld%lld%lld" , & L , & P , & D , & C ) ;
	
	scanf ( "%lld", & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%lld", & g[i] ) ;
		TOTAL += g[i] ;
	}
	
	for ( i = 1; i <= 2001 ; ++ i )
		rez [i] = INF ;
	
	rez [ 0 ] = 0 ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		extra = 0 ;
		s = g[i] ;
		for ( j = i -1 ; j >= 0 ; -- j )
		{
			rez[i]=min ( rez[i], (long long)rez[j] + extra*C + P ) ;
			s += g[j] ;
			extra += max ( 0 , (long long)s - g[j] - L ) ;
		}
	}
	
	printf ( "%lld", rez[n] + TOTAL * D ) ;
	
	return 0 ;
	
}
