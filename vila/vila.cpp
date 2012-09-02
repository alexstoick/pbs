#include<cstdio>

const int NMAX=1<<7;
int mat[NMAX][NMAX];
const int dx[] = { -1 , 1 , 0 , 0 } ;
const int dy[] = { 0 , 0 , -1 , 1 } ;

int nrcamera,marime[NMAX];

int inline max ( int x , int y )
{
	if ( x > y )
		return x ;
	return y ;
}

void dfs ( int i , int j )
{
	int c ;
	int xn , yn ;
	mat[i][j]=nrcamera;
	++marime[nrcamera];
	for ( c = 0 ; c < 4 ; ++ c )
	{
		xn = i + dx[c] ;
		yn = j + dy[c] ;
		if ( !mat[xn][yn] )
			dfs( xn , yn ) ;
	}	
}

void bordare ( int n , int m )
{
	int i , j ;
	for ( i = 0 ; i <= n + 1 ; ++ i )
		mat[i][0]=mat[i][m+1]=-1;
	for ( j = 0 ; j <= m + 1 ; ++ j )
		mat[0][j]=mat[n+1][j]=-1;
}

int main ( ) 
{
	
	freopen ( "vila.in", "r", stdin ) ;
	freopen ( "vila.out", "w", stdout ) ;
	
	int n , m , i , j , M , xn , yn ;
	int Mi=0,Mj=0,mm;
	int c , ch, vecini ;
	char caract ;
	
	scanf ( "%d%d ", &n,&m ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		for ( j =1 ; j <= m ; ++ j )
		{
			scanf ( "%c ",&caract ) ;
			if ( caract == '1' ) 
				mat[i][j]=-1;
		}
	
	/*for ( i = 1 ; i <= n ; ++ i )
	{
		for ( j = 1 ; j <= m ; ++ j )
			printf ( "%2d ", mat[i][j] ) ;
		printf ( "\n" ) ;
	}*/
	
	bordare ( n , m ) ;
	
	for ( i = 1 ; i <= n ; ++ i )
		for ( j = 1 ; j <= m ; ++ j )
			if ( !mat[i][j] )
			{
				++nrcamera;
				dfs ( i , j ) ;
			}
	printf ( "%d ", nrcamera ) ;
	M=-1;
	for ( i = 1 ; i <= nrcamera; ++ i )
		M=max(M,marime[i]);
	printf ( "\n%d\n",M ) ;
	/*for ( i = 1 ; i <= n ; ++ i )
	{
		for ( j = 1 ; j <= m ; ++ j )
			printf ( "%2d ", mat[i][j] ) ;
		printf ( "\n" ) ;
	}*/
	for ( i = 2 ; i < n ; ++ i )
		for ( j = 2 ; j < m ; ++ j )
			if ( mat[i][j]==-1 )
			{
				vecini=0;
				for ( c = 0 ; c < 4 ; ++ c )
				{
					xn = i + dx[c] ;
					yn = j + dy[c] ;
					if ( mat[xn][yn] != -1 )
					{
						++vecini;
						ch=mat[xn][yn];
					}
				}
				if ( vecini == 0 )
					continue ;
				if ( vecini == 4 )
				{
					mm=M;
					M=max( M , marime[ mat[i][j] ] + 1 );
					if ( M != mm )
					{
						Mi=i;
						Mj=j;
					}
					continue;
				}
				//gasim cele 2 
				for ( c = 0 ; c < 4 ; ++ c )
				{
					xn = i + dx[c] ;
					yn = j + dy[c] ;
					if ( mat[xn][yn] != -1 && mat[xn][yn] != ch )
					{
						mm=M;
						M= max ( M , marime[ch] + marime[ mat[xn][yn] ] ) ;
						if ( M != mm )
						{
							Mi=i;
							Mj=j;
						}
					}
				}
			}
	printf ( "%d %d %d", Mi,Mj,M+1 );
	return 0 ;
}
