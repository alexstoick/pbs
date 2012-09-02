#include<cstdio>
#include<cstring>

const int NMAX = 102 ;

char s[NMAX][NMAX];
char sir [ NMAX ] ; 
int f[NMAX], poz[NMAX],pred[NMAX],predq[NMAX];

int main ( )
{
	
	freopen ( "concat.in", "r", stdin ) ;
	freopen ( "concat.out", "w", stdout ) ;
	
	int u,n , i , contor , j , q ;
	int LUNG ;
	
	gets ( sir ) ;
	LUNG = strlen ( sir ) ;
	scanf ( "%d ", &n ) ;
	
	
	for ( i = 1 ; i <= n ; ++ i )
		gets ( s[i] ) ; 
	
	for ( i = 1 ; i <= n ; ++ i )
	{
		q = strlen ( s[i] ) ;
		for ( j = LUNG - q  ; j >= 0 ; -- j )
			if ( f[j] )
			{
				contor = 0 ;
				while ( s[i][contor] == sir[j+contor] && sir[j+contor] )
				{
					++contor ;
				}
				if ( contor == q )
					if ( f[j+q] < f[j]+1 )
					{
						//pred[i+strlen(s[pred[i]])] > i
						if ( !pred[j+q+strlen(s[pred[j+q]])+1] || ( pred [j+q] && pred[j+q+strlen(s[pred[j+q]])+1] && pred[j+q+strlen(s[pred[j+q]])+1] > i ) || !pred[j+q] )
						{
							if ( j+q == 3 )
								printf ( "" ) ;
							f[j+q] = f[j]+1;
							poz[j+q]=j;
							pred[j+q]=i;
						}	
					}
			}
		//daca se potriveste la inceput adaugam.
		contor = 0 ;
		if ( i == 16 )
			printf ( "" ) ;
		while ( s[i][contor] == sir [contor] && sir[contor] )
			++contor;
		if ( contor == q )
		{
			if ( !f[contor] ) 
			{
				f[contor] = 1 ;
				poz[j+q]= -1 ;
				pred[contor] = i ;
			}
		}
	}

	i=strlen(sir);
	printf ( "%d\n" , f[i] ) ;
	u = 0 ;
	while ( pred[i] )
	{
		predq[++u]=pred[i];
		i = poz[i] ; 
	}
	for ( i = u ; i >= 1 ; -- i )
		printf ( "%d ", predq[i] ) ;
	
	return 0 ;
}
