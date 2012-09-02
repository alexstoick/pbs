#include<cstdio>

const int NMAX = 1<<7;

struct POINT { int x , y ; } ;
POINT romeo,julieta;
POINT q [NMAX*NMAX];

int matR[NMAX][NMAX];
int matJ[NMAX][NMAX];
int n , m ;

int dx[] = { 1 , -1 , 0 , 0 , -1 , -1 , 1 , 1 } ;
int dy[] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
void afisareR ( )
{
	int i , j ;
	for ( i = 1 ; i <= n ; ++ i )
	{
		for ( j = 1 ; j <= m ; ++ j )
			printf ( "%2d ", matR[i][j] ) ;
		printf ( "\n" ) ;
	}
}
void afisareJ ( )
{
	int i , j ;
	for ( i = 1 ; i <= n ; ++ i )
	{
		for ( j = 1 ; j <= m ; ++ j )
			printf ( "%2d ", matJ [i][j] ) ;
		printf ( "\n" ) ;
	}
}
void bordare ( )
{

	int i , j ;
	for ( i = 0 ; i <= n + 1 ; ++ i )
		matR[i][0]=matR[i][m+1]=matJ[i][0]=matJ[i][m+1]=-1;
	for ( j = 0 ; j <= m + 1 ; ++ j )
		matR[0][j]=matR[n+1][j]=matJ[0][j]=matJ[n+1][j]=-1;

}

void lee ( POINT start , int matQ[NMAX][NMAX] ) 
{
	int p , u , c;
	int xn , yn ;
	p=u=1;
	q[p].x = start.x ;
	q[p].y = start.y ;
	
	while ( p <= u )
	{
		for ( c = 0 ; c < 8 ; ++ c )
		{
			xn=q[p].x + dx[c];
			yn=q[p].y + dy[c];
			if ( matQ[xn][yn] == 0 )
			{
				q[++u].x = xn ;
				q[u].y = yn ;
				matQ[xn][yn] = matQ[q[p].x][q[p].y] + 1 ;
			}
		}
		++p;
	}
}

int main ( )
{
	
	freopen ( "rj.in", "r", stdin ) ;
	freopen ( "rj.out", "w", stdout ) ;
	
	int  i , j ;
	int min=NMAX*NMAX+5 , mini, minj  ;
	char s[NMAX];
	
	scanf ( "%d%d ", & n , & m ) ;
	
	for ( i =1 ; i <= n; ++ i )
	{
		gets ( s ) ;
		for ( j = 0 ; s[j]; ++ j )
			if ( s[j] == 'R' )
			{
				romeo.x = i ;
				romeo.y= j+1;
				matR[i][j+1]=1;
			}
			else
				if ( s[j] == 'J' )
				{
					julieta.x = i ;
					julieta.y = j+1;
					matJ[i][j+1]=1;
				}
				else
					if ( s[j] == 'X' )
						matR[i][j+1]=matJ[i][j+1]=-1;
	}
	
	bordare ( ) ;
	lee ( romeo , matR) ;
	lee ( julieta , matJ ) ;
	/*afisareR () ;
	printf ( "\n" );
	afisareJ () ;*/
	
	for ( i = 1 ; i <= n ; ++ i )
		for ( j = 1 ; j <= m ; ++ j )
			if ( matR[i][j] == matJ[i][j] && matR[i][j] != -1 && matR[i][j] != 0 ) 
				if ( matR[i][j] < min )
				{
					min = matR[i][j] ;
					mini = i ;
					minj = j ;
				}
	printf ( "%d %d %d" , min, mini , minj ) ;
	
	return 0 ;
}

