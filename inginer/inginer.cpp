#include<cstdio>

struct POINT { int x , y ; } ;

const int NMAX = 1<<7 ;

POINT d[]= { {1,0} , {-1,0} , {0,1} , {0,-1} } ;
int n , m ;
POINT q [ NMAX*NMAX ] ;
int mat[NMAX][NMAX];
void bordare ( )
{
	int i ;
	for ( i = 0 ; i <= n+3 ; ++ i )
		mat[i][0]=mat[i][m+3]=-1;
	for ( i = 0 ; i <= m + 3 ; ++ i )
		mat[0][i]=mat[n+3][i]=-1;
}

void lee ( POINT start, POINT fin )
{
	int c , p , u;
	POINT pct ;
	
	p = u = 1 ;
	q[1] = start ;
	
	while ( p <= u )
	{
		for ( c = 0 ; c < 4 ; ++ c )
		{
			pct.x = q[p].x + d[c].x ;
			pct.y = q[p].y + d[c].y ;
			if ( pct. x == fin.x && pct.y == fin.y  )
			{
				printf ( "%d\n", mat[q[p].x][q[p].y] +2 ) ;
				return ;
			}
			if ( mat[pct.x][pct.y] == 0 )
			{
				q[++u]=pct;
				mat[pct.x][pct.y]=mat[q[p].x][q[p].y]+1;
				if ( pct. x == fin.x && pct.y == fin.y  )
				{
					printf ( "%d\n", mat[fin.x][fin.y] +2 ) ;
					return ;
				}
			}
		}
		++p;
	}
	printf ( "0\n" ) ;
	return ;
}

void reinit ( )
{
	int i , j;
	for ( i = 0 ; i <= n+3 ; ++ i )
		for ( j = 0 ; j <= m+3 ; ++ j )
			if ( mat[i][j] != -1 )
				mat[i][j]=0;
}

int main ( )
{
	freopen ( "inginer.in", "r", stdin ) ;
	freopen ( "inginer.out", "w", stdout ) ;
	

	char s [NMAX];
	POINT start,fin;
	int i , j;
	
	scanf ( "%d%d ", &n , &m ) ;
	
	for ( i = 1; i <= n ; ++ i )
	{
		gets ( s ) ;
		for ( j = 0 ; s[j] ; ++ j )
			if ( s[j] == 'X' )
				mat[i+1][j+2]=-1;
	}
	
	scanf ( "%d%d%d%d" , &start.x , &start.y, &fin.x, &fin.y ) ;
	bordare ( ) ;
	
	while ( start.x+start.y+fin.x+fin.y )
	{
		start.x += 1 ;
		start.y += 1 ;
		fin.x += 1;
		fin.y += 1 ;
		lee ( start,fin ) ;
		reinit();
		scanf ( "%d%d%d%d" , &start.x , &start.y, &fin.x, &fin.y ) ;
	}

	
	
	return 0 ;
}
