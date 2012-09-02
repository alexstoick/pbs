#include<fstream>

using namespace std ;

ifstream in ( "difprim.in" ) ;
ofstream out( "difprim.out" ) ;

const int NMAX = 10000005;

bool ciur[NMAX] ;

int main ( ) 
{
	int a , b ;
	long long	i , j;
	int U = 0 ;
	in >> a >> b ;
	
	ciur[0]=ciur[1]=true ;
	for ( i = 2 ; i <= 3200 ; ++ i )
		if ( ! ciur[i] )
			for ( j = i*i ; j <= NMAX ; j+= i  )
				ciur[j] = true ;
	
	if ( a % 2 == 0 )
		-- a;
	int st , dr ;
	
	st = dr = 0 ;
	
	int max = -1 ;
	int maxS , maxD ;
	
	for ( i = a ; i <= b ; i+=2 )
		if ( !ciur[i] )
		{
			if ( ! st )
				st = i ;
			else
			{
				if ( ! dr )
					dr = i ;
				else
				{
					st=dr;
					dr = i ;
				}
				if ( max < dr - st )
				{
					max = dr - st ;
					maxD = dr ;
					maxS = st ;
				}
			}
		}

	if ( max == -1 )
		out << "-1\n" ;
	else
		out << maxS << " " << maxD << "\n" ; 
	
	return 0 ;
}