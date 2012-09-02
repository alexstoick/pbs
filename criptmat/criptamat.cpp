#include<cstdio>
#include<string>

char mat[101][205];
char s[205];

int main ( )
{
	freopen ( "criptmat.in", "r", stdin ) ;
	freopen ( "criptmat.out", "w", stdout ) ;
	
	int n , i , rest , j , U ;
	
	scanf ( "%d " , &n ) ;
	
	gets ( s ) ;
	
	int lung = strlen ( s ) ;
	lung /= n ;
	for ( rest = 0 ; rest <= lung ; ++ rest )
	{
		if ( rest % 2 == 0 ) 
			//directia e corecta
		{
			for ( i = 0 ; i <= n-1; ++ i )
				mat[rest+1][i]=s[rest*n+i];
		}
		else
			//directia inversa
		{
			for ( i = 0 ; i <= n-1 ; ++ i )
				mat[rest+1][n-i-1]=s[rest*n+i];
		}
	}
	U=-1;
	for ( j = 0; j <= n ; ++ j )
		for ( i = 1; i <= lung ; ++ i )
			s[++U]=mat[i][j];
	s[++U]=0;
	printf ( "%s\n" , s ) ;
	return 0 ;
}
