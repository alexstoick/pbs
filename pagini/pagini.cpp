#include<cstdio>

const int FMAX = 1 << 9 ;
int f [FMAX];

int main ( )
{
	
	freopen ( "pagini.in","r",stdin);
	freopen ( "pagini.out","w", stdout );
	
	int n , i , nr = 0 , max = 0 , curr , x ;
	
	scanf ( "%d", & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d", & x ) ;
		++f[x];
	}
	
	nr=0;
	for ( i = 1 ; i <= 500 ; ++ i )
		if ( f[i] )
		{
			curr=0;
			while ( f[i] )
			{
				++curr;
				++i;
			}
			--i;
			if ( curr > max )
				max=curr;
			if ( curr > 1 )
				++nr;
		}
	if ( max == 1 )
		--max;
	printf ( "%d\n%d",nr,max);
	
	return 0 ;
}