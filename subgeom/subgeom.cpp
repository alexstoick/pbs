#include<cstdio>
#include<algorithm>

using namespace std ;

struct  chestie { int val , i ; } ; 

chestie x [ 5005 ] ;
chestie y [ 5005 ] ;

bool comp ( chestie x , chestie y )
{
	return x.val < y.val || ( x.val == y.val && x.i < y.i ) ;
}

int inline maxx ( int x , int y )
{
	if ( x > y )
		return x ;
	return y ;
}


int A [ 5005 ] ;
bool marked [ 100005 ] ;

int main ( )
{
	
	freopen ( "subgeom.in", "r", stdin ) ;
	freopen ( "subgeom.out", "w", stdout ) ;
	
	int test , best  ;
	int max , ratie ;
	int j , sol , val ;
	int p1 , p2 , q1 , q2 , i , N ;
	
	scanf ( "%d" , & test ) ;
	
	for ( ; test ; -- test )
	{
		
		scanf ( "%d", & N ) ;
		max = -1 ;
		for ( i = 0 ; i < N ; ++ i ) 
		{
			scanf ( "%d", & val ) ;
			x[i].i = i ;
			y[i].i = i ;
			x[i].val = val ;
			y[i].val = val ;
			if ( val > max )
				max = val ;
		}
		sort ( x , x + N , comp ) ;
		best=1;
		
		for ( ratie = 2 ; ratie*ratie <= max ; ++ ratie )
		{
			for ( i = 0 ; i < N ; ++ i )
				A[i] = 1 ;
			p1 = p2 = 0 ;
			
			while ( p2 < N && x[p2].val < x[p1].val * ratie )
				++p2;
			
			bool afis = false;
			
			while ( p2 < N )
			{
				if ( x[p2].val == x[p1].val * ratie )
				{
					q1 = p1 ;
					q2 = p2 ;
					sol = 1 ;
					while (q2 < N && x[q2].val == x[p2].val) 
					{
						while ( x[q1].val == x[p1].val && x[q1].i < x[q2].i)
							sol = maxx(sol, A[q1++] + 1 ) ;		
						afis=false;
						A[q2] = maxx(A[q2], sol);
						++q2;
					}

					while ( x[q1].val == x[p1].val )
						++q1;

					p2 = q2;
					p1 = q1;
				}
				else
					++p1;

				while (p2 < N && x[p2].val < x[p1].val * ratie )
					++p2;
			}
			for ( i = 0; i < N; ++i)
				best = maxx(best, A[i]);
		}

		if ( best > 1 )
		{
			printf ( "%d\n", best ) ;
			continue ;
		}
		
		bool gasit = false ;
		
		for ( i = 0 ; i <= max ; ++ i )
			marked[i] = false ;
		
		for ( i = 0 ; i < N && !gasit ; ++ i )
		{
			if ( marked [ y[i].val ] )
				gasit = true ;
			for ( j = y[i].val * y[i].val ; j < max ; j += y[i].val )
				marked [ j ] = true ;
		}
		if ( gasit )
		{
			printf ( "2\n" ) ;
			continue ;
		}
		else
		{
			printf ( "1\n" ) ;
			continue ; 
		}
	}
	
	return 0 ;
}
