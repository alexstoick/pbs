#include<fstream>
#include<cstdio>
#include<algorithm>

std::ifstream in ( "colaj.in" ) ;
std::ofstream out ( "colaj.out" ) ;

struct dreptunghi { int x1 , y1 , x2 , y2 ; } ;

dreptunghi dr [ 101 ] ;
int x [ 205 ] , y [ 205 ] ;
int uX , uY ;

int N , n , m;

int mat [ 105 ] [ 105 ] ;

int cautX ( int val )
{
	
	int pas = 1 << 8 , i ;
	
	for ( i = 0 ; pas ; pas >>= 1 )
		if ( i+pas <= uX && x[i+pas] < val ) 
			i+=pas;
		
	return i + 1;
}

int cautY ( int val )
{
	
	int pas = 1 << 9 , i ;
	if ( val == 15 )
		printf ( "" ) ;
	for ( i = 0 ; pas ; pas >>= 1 )
		if ( i + pas <= uY && y[i+pas] < val )
			i+= pas ;
		
	return i + 1;
}

void afisare ( )
{
	
	int i , j ; 
	
	for ( i = 1 ; i <= uX ; ++ i )
	{
		for ( j = 1 ; j <= uY ; ++ j )
			printf ( "%d " , mat[i][j] ) ;
		printf ( "\n" ) ;
	}
	return ;
}

int main ( ) 
{
	

	int i , j ;
	
	in >> N ;
	
	in >> n >> m ;
	
	for ( i = 1 ; i <= N ; ++ i )
	{
		in >> dr[i].x1 >> dr[i].y1 >> dr[i].x2 >> dr[i].y2 ;
		x[++uX] = dr[i].x1 ;
		x[++uX] = dr[i].x2 ;
		y[++uY] = dr[i].y1 ;
		y[++uY] = dr[i].y2 ;
	}
	//sortez
	std::sort ( x + 1 , x + 1 + uX ) ;
	std::sort ( y + 1 , y + 1 + uY ) ;
	
	//elimin dubluri

	for ( i = 2 ; i <= uX ; ++ i )
		if ( x[i-1] == x[i] )
		{
			for ( j = i ; j < uX ; ++ j )
				x[j] = x[j+1] ;
			--uX ;
			--i;
		}
		
	for ( i = 2 ; i <= uX ; ++ i )
		if ( y[i-1] == y[i] )
		{
			for ( j = i ; j < uY ; ++ j )
				y[j] = y[j+1] ;
			--uY ;
			--i;
		}
		
	int Q ;
	
	int poz_x1 , poz_x2 , poz_y1 , poz_y2 ;
	
	for ( Q = 1 ; Q <= N ; ++ Q )
	{
		//printf ( "Dreptunghiul %d -- (%d,%d),(%d,%d)\n" , Q , dr[
		//caut binar primul x
		poz_x1 = cautX ( dr[Q].x1 ) ;
		poz_y1 = cautY ( dr[Q].y1 ) ;
		poz_x2 = cautX ( dr[Q].x2 ) ;
		poz_y2 = cautY ( dr[Q].y2 ) ;
		
		for ( i = poz_x1 ; i <= poz_x2 ; ++ i )
			for ( j = poz_y1 ; j <= poz_y2 ; ++ j )
				mat[i][j] = Q ;
	}
	afisare ( ) ;
	return 0 ;
}
