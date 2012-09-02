#include<cstdio>
#include<string>

char lowercase ( char n )
{
	if ( 'a' <= n && 'z' >= n )
		return n;
	//litera mare
	return (n + 32 ) ;
}

char enunt[26][300];
char varA[26][300];
char varB[26][300];
char varC[26][300];
char varD[26][300];



int main ( )
{
	int i , j;
	char s [ 5000 ] ;
	freopen ( "fis.in", "r", stdin ) ;
	freopen ( "fis.out", "w" , stdout ) ;
	
	int lin=1 , col = 1 ;
	printf ( "texte[1][1]=\"" ) ;
	for ( i = 1 ; i <= 80 ; ++ i )
	{
		gets(s);
		if ( s[0] == 0 ) 
		{
			if ( col == 1 )
				++col ;
			else
			{
				++lin;
				col = 1 ;
			}
			printf ( "\";\ntexte[%d][%d]=\"" , lin , col ) ;
			continue ;
		}
		
		for ( j = 0 ; s[j] ; ++ j )
			if ( s[j] == '…' )
				strcpy ( s+j , s+j+1 ) ;
		printf ( "%s\\n" , s ) ;
	}
	
	/*
	for ( i = 1 ; i <= 16; ++ i )
	{
		
		gets ( s ) ;
		//if ( i % 4 )
	//	{
			strcpy ( s , s+3 ) ;
		//}
		//s[strlen(s)-1]=0;
		if ( i <= 25 )
			strcpy( varA[i] , s );
		else
			if ( 25 < i && i <= 50 )
				strcpy ( varB[i-25] , s ) ;
			else
				strcpy ( varC[i-50] , s ) ;
		/*switch ( i % 4 )
		{
			case 1: strcpy ( varA[i/4] , s ) ;
			case 2: strcpy ( varB[i/4] , s ) ;
			case 3: strcpy ( varC[i/4] , s ) ;
		}
	}

	printf ( "var rasp1:Array = [ ") ;
	
	for ( i = 1 ; i <= 16 ; ++ i )
		printf ( " \"%s\", \n" , varA[i] ) ;
	
	printf ( " ];\n" ) ;
	
	printf ( "var rasp2:Array = [ ") ;
	
	for ( i = 1 ; i <= 25 ; ++ i )
		printf ( " \"rasp%cf4\", \n" , (varB[i][0]-32) ) ;
	
	printf ( " ];\n" ) ;
	
	printf ( "var rasp3:Array = [ ") ;
	
	for ( i = 1 ; i <= 25 ; ++ i )
		printf ( " \"rasp%cf5\", \n" , (varC[i][0]-32) ) ;
	
	printf ( " ];\n" ) ;	
	*/
	return 0 ; 
}
