#include<cstdio>
#include<algorithm>
using namespace std;

struct STR { int val , ind ; } ;

STR x[105 ] ;
int y[105];

bool comp ( STR a , STR b ) 
{
	return (a.val<b.val) ;
}

int main ( ) 
{
	
	freopen ( "siruri1.in", "r", stdin ) ;
	freopen ( "siruri1.out" , "w", stdout ) ;
	
	int n , i , ind ;
	
	scanf ( "%d" , & n ) ;
	
	for ( i = 1;  i <= n ; ++ i )
	{
		scanf ( "%d", & x[i].val ) ;
		y[i]=x[i].val;
		x[i].ind = i ;
	}
	
	sort ( x+1 , x +1 + n , comp ) ;
	
	for ( ind = 1 ; ind <= n ; ++ ind )
		for ( i = 1 ; i <= n ; ++ i )
			if ( x[i].ind == ind )
				printf( "%d ", i ) ;
	
	return 0 ;
}
