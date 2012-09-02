#include<cstdio>

const int QMAX = 1005 ;

struct PUNCT
{ 
	int x , y ;
};

int dx[] = {-1, 0, 1,  0} ;
int dy[] = { 0, 1, 0, -1} ;
int mat[QMAX][QMAX], N , M ;
PUNCT st[ QMAX * QMAX ] ;
int v ;

bool interior ( int x , int y )
{
	return ( x >= 0 && y >= 0 && x <= N+1 && y <= M + 1 ) ;
}

void Fill ( int x , int y , int Q )
{
	
	int xn , yn , c ;
	int top = 0 ;
	st[top].x = x ;
	st[top].y = y ;
	mat[x][y]= v ;
	while ( top >= 0 )
	{
		x = st[top].x ;
		y = st[top].y ;
		--top ;
		for ( c = 0 ; c < 4 ; ++ c )
		{
			xn = x + dx[c] ;
			yn = y + dy[c] ;
			if ( interior ( xn , yn ) )
				if ( mat[xn][yn] == Q )
				{
					mat[xn][yn] = v ;
					st[++top].x = xn ;
					st[top].y = yn ;
				}
		}
	}
}

void rez ( )
{
	int i , j ;
	int drept , maxV , nrmax ;
	drept = 0 ;
	maxV = 0 ;
	nrmax = 0 ;
	for ( i = 1 ; i <= N ; ++ i )
		for ( j = 1 ; j <= M ; ++ j )
			if ( mat[i][j] <= 0 )
			{
				v = mat[i-1][j-1]+1;
				if ( v % 2 == 0 )
				{
					++drept;
					if ( maxV < v )
					{
						maxV=v;
						nrmax=1;
					}
					else
						if ( maxV == v )
							++nrmax;
				}
				Fill ( i , j , mat[i][j] ) ;
			}
	printf ( "%d %d %d\n", drept , maxV/2 , nrmax ) ;
}

void afis ( )
{
	int i , j ;
	for ( i = 0 ; i <= N+1 ; ++ i )
	{
		for ( j = 0 ; j <= M+1 ; ++ j )
			printf ( "%2d " , mat[i][j] ) ;
		printf ( "\n" ) ;
	}
}

int main ( )
{
	freopen ( "dreptunghiuri.in" , "r", stdin ) ;
	freopen ( "dreptunghiuri.out", "w", stdout ) ;
	
	int i , j , xx ;
	
	scanf ( "%d%d", & N , & M ) ;
	
	for ( i = 1 ; i <= N ; ++ i )
	{
		for ( j = 1 ; j <= M ; ++ j )
		{
			scanf ( "%d", & xx ) ;
			mat[i][j] = -xx;
		}
	}
	v=1;
	Fill ( 0 , 0 , 0 ) ;
	//afis();
	rez();
	//afis();
}
