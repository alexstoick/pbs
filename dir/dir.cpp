#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

char s[1605];

char cale[100][1600];
char FIS[102][1600];
char nume[255];
int u = 0 , ufis = 0;
int LUNGS;

void addFisier ( )
{
	int i ;
	/*for ( i =1 ; i <= u ; ++ i )
		printf ( "%s\\", cale[i]);
	printf("\n");*/
	for ( i = 1 ; i <= u ; ++ i )
	{
		strcat ( FIS[ufis], cale[i] ) ;
		FIS[ufis][strlen(FIS[ufis])]='\\' ;
	}
	strcat ( FIS[ufis] , nume ) ;
	//printf ( "addFisier -- %s\n" , FIS[ufis] ) ;
	++ufis;
}

void prelucr ( int start ) 
{
	int i ;
	if ( start >= LUNGS )
		return ;
	
	for ( i = start ; s[i]!='(' && s[i]!=',' && s[i]!=')' ;++i)
		nume[i-start]=s[i];
	
	nume[i-start]=NULL;
	
	//printf ( "!%s!!---%d\n", nume , u ) ;
		
	if ( nume[0]>='a' && nume[0]<='z' ) 
		addFisier();
	else
		strcpy( cale[++u], nume ) ;
	
	while ( s[i]=='(' || s[i]==')' || s[i]==',' )
	{
		if ( s[i]==')' )
		{
			--u;
		}
		++i;
	}
	
	prelucr ( i ) ;
	--u;
}

 int comp(const void * a,const void * b) 
 { 
	char *x=(char*)a; 
	char *y=(char*)b; 
	return strcmp(x,y);
 }

int comp ( char a[] , char b[] )
{
	if ( strcmp ( a , b )  )
		return true ;
	return false;
}

int main ( )
{
	
	freopen ( "dir.in" , "r", stdin ) ;
	freopen ( "dir.out", "w" , stdout ) ;
	
	gets ( s ) ;
	LUNGS=strlen(s);
	prelucr ( 0 ) ;
	
	qsort(FIS,ufis+1,sizeof(char)*100,comp) ;
	printf ( "%d\n", ufis ) ;
	for ( int i = 1 ; i <= ufis ; ++ i )
		printf ( "%s\n" , FIS[i] ) ;
	
	return 0 ;
}