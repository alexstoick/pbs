#include<cstdio>

struct COADA { int x , y ; } ;

COADA q [ 22501 ] ;

bool cheie [ 22501 ] ;
bool visit [ 152 ] [ 152 ] ;
int x [ 152 ] [ 152 ] ;

int dx[] = { 0 , 0 , 1 , -1 } ;
int dy[] = { 1 , -1 , 0 , 0 } ; 

int main ( )
{
	
	freopen ( "castel.in", "r", stdin ) ;
	freopen ( "castel.out", "w", stdout ) ;
	
	int n , m , k , startx , starty ;
	int p , u , c , camere , xn , yn ;
	int i , j ;
	
	scanf ( "%d%d%d" , & n , & m , & k ) ;
	
	starty = k%m ;
	if ( starty == 0 )
	{
		starty = m ;
		startx = k/m;
	}
	else
		startx = k/m + 1 ;
	
	cheie[k] = true ;
	
	for ( i = 1 ; i <= n ; ++ i )
		for ( j = 1 ; j <= m ; ++ j )
			scanf ( "%d", & x[i][j] ) ;
	
	p = u = 1 ;
	q[p].x = startx ;
	q[p].y = starty ;
	visit [startx][starty] = true ;
	camere = 1 ;
	
	bool GO = true ;
	
	while ( GO )
	{
		GO = false ;
		for ( p = 1 ; p <= u ; ++ p )
		{
			for ( c = 0 ; c < 4 ; ++ c )
			{
				xn = q[p].x + dx[c] ;
				yn = q[p].y + dy[c] ;
				if ( cheie [ x[xn][yn] ] && x[xn][yn] )
				{
					++camere;
					x[xn][yn] = 0 ;
					visit [xn][yn] = true ;
					cheie [ x[xn][yn] ] = true ;
					cheie [ (xn-1)*m + yn ] = true ;
					q[++u].x = xn ;
					q[u].y = yn ;
					GO = true ;
				}
			}
		}
	}
	
	printf ( "%d" , camere -1  ) ;
	
	return 0 ;
}
