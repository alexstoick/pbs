#include<fstream>

std::ifstream in ( "diagonala.in" ) ;
std::ofstream out ( "diagonala.out" ) ;

struct CHESTIE { int st , dr ; } ;

const int NMAX = 200005 ;

int dq [ NMAX ];

CHESTIE x [ NMAX ] ;

int front , back ;

bool inauntru ( CHESTIE x , CHESTIE y ) 
{
	return ( x.st <= y.st && y.st <= x.dr ) || ( y.st <= x.st && x.st <= y.dr ) ;
}

void stanga ( int ind )
{
	while ( !inauntru ( x[ dq[front] ] , x[ind] ) )
	{
		dq[front]= -1 ;
		++front ;
	}
	int i ;
	for ( i = front ; i <= back ; ++ i )
		if ( ! inauntru ( x [dq[i]] , x[ind] ) )
			front = i + 1 ;
	return ;
}

void dreapta ( int ind )
{
	if ( inauntru ( x[dq[back]] , x[ind] ) ) 
			dq[++back] = ind ;
	return ;
}

int main ( )
{
	
	int n , i , a , b ;
	int max ;
	
	in >> n ;
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		in >> a >> b ;
		x[i].st = a + i - 1 ; 
		x[i].dr = b + i - 1 ;
	}
	
	max = -1 ;
	dq[1]= 1 ;
	front=back=1;
	for ( i = 2 ; i <= n ; ++ i )
	{
		stanga ( i ) ;
		dreapta ( i ) ;
		if ( (back-front+1) > max )
			max = back-front+1 ;
	}
	out << max ;
	
	return 0 ;
}
