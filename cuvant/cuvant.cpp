#include<cstdio>
#include<cstring>

char sir [26][12];
int indice [26];

bool identic ( char a[] , char b[] )
{
	int contor = 0 ;
	while ( a[contor ] == b[contor] && a[contor] )
		++contor;
	if ( a[contor] == 0 )
		return true ;
	return false;
}

bool acelasi ( char a[] , char b[] )
{
	char copie [ 26 ] ;
	strcpy ( copie , b ) ;
	if ( strlen(a) != strlen ( b ) )
		return false;
	/*if ( identic ( a , b ) )
		return false;*/
	//frecventa
	int lungB = strlen ( b ) , i  , j;
	char aux ;
	for ( i = 0 ; i < lungB-1 ; ++ i )
	{
		aux= b[0] ;
		b[lungB]=aux;
		strcpy ( b+0, b+1) ;
		if ( strcmp ( a , b ) == 0 )
		{
			strcpy ( b, copie ) ;
			return true ;
		}
	}
	strcpy ( b , copie ) ;
	return false ;
}

int main ( )
{
	
	freopen ( "cuvant.in", "r", stdin ) ;
	freopen ( "cuvant.out", "w", stdout ) ;
	
	int u , i , n , j;
	bool ok , primul ;
	
	scanf ( "%s ", sir[1] ) ;
	u = 1 ;
	indice[1]=1;
	while ( sir[u][strlen(sir[u])-1] != '!' )
	{
		scanf ( "%s ", sir [ ++u ] ) ;
		indice[u]=u;
	}
	sir[u][strlen(sir[u])-1]=0;
	ok = false;
	primul = true ;
	n=u;
	while ( ! ok )
	{
		ok= true;
		for ( i = 2 ; i <= n ; ++ i )
			if ( acelasi ( sir[i-1],sir[i] ) )
			{
				if ( primul )
				{
					printf ( "%d\n" , indice[i] ) ;
					primul=false;
				}
				for ( j = i ; j < n ; ++ j )
				{
					strcpy ( sir[j] , sir[j+1] ) ;
					indice[j]=indice[j+1];
				}
				--n;--i;
				ok = false ;
			}
	}
	if ( primul )
		printf ( "0\n" ) ;
	for ( i = 1 ; i <= n ; ++ i )
		printf ( "%d ", indice[i] ) ;
	
	return 0 ;
}
