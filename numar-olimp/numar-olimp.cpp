/*#include<cstdio>

int u , put10 , u10 ;

const int NMAX = 1 << 11 ;
int x [ NMAX ];
int p10 [NMAX];
int putere5 , putere2 ;

void afis ( )
{
	int i ;
	printf ( "%d\n" , u ) ;
	for ( i = 1 ; i <= u ; ++ i )
		printf ( "%d" , x[i] ) ;
	printf ( "\n%d\n" ,  u10 ) ;
	for ( i = 1 ; i <= u10 ; ++ i )
		printf ( "%d" , p10[i] ) ;
}

int put5 ( int x[] , int u ) 
{
	int y [NMAX];
	int uy = 0 ;
	int nr , i ;
	nr = 0 ;
	uy=0;
	bool ok ;
	ok=true;
	while ( ok )
	{
		for ( i = 1 ; i <= u ; ++ i )
		{
			nr=nr*10+x[i];
			if ( nr >= 5 )
			{
				y[++uy]=nr/5;
				nr%=5;
			}
		}
		if ( nr ) 
			ok=false;
		else
		{
			++putere5;
			if ( putere5 > u10-1 )
				return u ;
			for ( i = 1 ; i <= uy ; ++ i )
				x[i]=y[i];
			u=uy;
			uy=0;
		}
	}
	return u ;
}

int impx ( int x[] , int u , int n )
{
	int y [ NMAX ] , uy = 0 ;
	int i , nr = 0 ;
	for ( i = 1 ; i <= u ; ++ i )
	{
		nr=nr*10+x[i];
		if ( nr == 0 && x[i] == 0 )
			y[++uy]=0;
		if ( nr > n )
		{
			y[++uy] = nr / n ;
			nr%=n;
		}
	}

	for ( i = 1 ; i <= uy ; ++ i )
		x[i]=y[i];
	
	return uy ;
}

int put2 ( int x[] , int u )
{
	int y [NMAX] , uy = 0 ;
	int nr=0 , i ;
	bool ok = true;
	while ( ok )
	{
		for ( i = 1; i <= u; ++ i )
		{
			nr = nr*10 + x[i];
			if ( nr >= 2 )
			{
				y[++uy] = nr / 2 ;
				nr %= 2;
			}
		}
		if ( nr ) 
			ok = false;
		else
		{
			++putere2;
			if ( putere2 > u10-1 )
				return u ;
			for ( i = 1 ; i <= uy ; ++ i )
				x[i]=y[i];
			u=uy;
			uy=0;
		}
	}
	
	
	
	return u ;
	
}


int main ( ) 
{
	
	freopen ( "numar.in" , "r" , stdin ) ;
	freopen ( "numar.out" , "w" , stdout ) ;
	
	int n1 , n2 , i ;
	
	u = 0 ;
	
	bool prim0 = false ;
	
	scanf ( "%d%d" , & n1 , & n2 ) ;
	
	for ( i = 1 ; i <= n1 ; ++ i )
	{
		scanf ( "%d" , & x[i] ) ;
		if ( ! x[i] )
		{
			--n1;--i;
		}
	}
	
	if ( n1 != 1 || (n1==1 && x[1]!=0) )
		u=n1;
	else
		prim0 = true ;
	for ( i = 1 ; i <= n2 ; ++ i )
			scanf ( "%d" , & x[u+i] ) ;
	u+=i-1;
	if ( n2 == 1 && x[u] == 0 )
	{
		printf ( "%d\n" , n1 ) ;
		for ( i = 1 ; i <= n1 ; ++ i )
			printf ( "%d" , x[i] ) ;
		printf ( "\n1\n1" ) ;
		return 0 ;
	}
	if ( prim0 ) 
		++put10;
	put10 += n2 ;
	
	p10[1]=1;
	u10=put10+1;
	
	//caz 1: se termina in 0
	
	i = u ;
	while ( x[i] == 0 )
	{
		--u10;
		--i;
	}
	u=i;
	if ( x[u] % 2 && x[u] != 5 )
	{
		afis ( ) ;
		return 0 ; 
	}
	
	//caz 2: se termina in 5=> are put5 dar nu are put2

	if ( x[u] == 5 )
	{	
		u = put5 ( x , u ) ; 
		for ( i = 1 ; i <= putere5 ; ++ i )
		{
			u10 = impx ( p10 , u10 , 5 ) ;
			if ( p10[u10] != 5 )
				break;
		}
	}
	
	//caz 3: se termina in par=> are put2 , nu are put5
	if ( x[u] % 2 == 0 )
	{
		u=put2( x , u ) ;
		for ( i = 1 ; i <= putere2; ++ i )
		{
			u10 = impx ( p10, u10 , 2 ) ;
			if ( p10[u10] % 2 )
				break;
		}
	}
	
	afis();
	
	return 0 ; 
	
}*/
#include<iostream.h>
#include<conio.h>
#include<math.h>
int main()
{
int n, v[100],i,div;
cin>>n;
for(i=1;i<=n;i++)cin>>v[i];
div=2;
for(i=1;i<=n;i++)
{
	while(div<=v[i]/2)
	{
		if(v[i]%div==0)
			cout<<v[i];
		div++;
	}
}
return 0;
}