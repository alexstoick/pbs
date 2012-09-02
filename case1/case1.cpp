#include<cstdio>

int barbati,femei,copii;
int rude [4];

int main ( )
{
	
	freopen ( "case1.in","r", stdin );
	freopen ( "case1.out","w", stdout);
	int n , i , x ;
	scanf ( "%d", & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d", &x);
		copii += x%10;
		x/=10;
		femei += x%10;
		x/=10;
		barbati += x%10;
		x/=10;
		++rude[x];
	}
	
	for ( i=1 ; i <= 3 ; ++ i )
		printf ( "%d\n", rude[i] ) ;
	
	printf ( "%d\n%d\n%d", barbati, femei, copii ) ;
	
	
	return 0 ;
}
