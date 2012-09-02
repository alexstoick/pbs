#include<cstdio>


int prim [] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199 } ;
bool okey = true ;
int frecv[30005];
void desc ( int N )
{
	int i ;
	
	for ( i = 0 ; prim[i]*prim[i] <= N ; ++ i )
		while ( N % prim[i] == 0 )
		{
			N/=prim[i];
			++frecv[prim[i]];
		}
	if ( N != 1  )
		++frecv[N];
}

int main ( )
{
	
	freopen ( "exp1.in" , "r", stdin ) ;
	freopen ( "exp1.out" , "w", stdout ) ;
	
	int n , m , i , X , max = 0 ;
	
	scanf ( "%d", & m ) ;
	scanf ( "%d", & n ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		scanf ( "%d", & X ) ;
		if ( X > max )
			max = X ;
		desc ( X ) ;
	}
	
	for ( i = 2 ; i <= max ; ++ i )
		if ( frecv[i] % m )
		{
			printf ( "0" ) ;
			return 0 ;
		}
		else
			if ( frecv[i] )
				frecv[i]/=m;
	printf ( "1\n" ) ;
	for ( i = 2 ; i <= max ; ++ i )
		if ( frecv[i] ) 
			printf ( "%d %d\n", i , frecv[i] ) ;
	return 0 ;
}
