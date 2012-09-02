/*#include<cstdio>

void toUpperCase ( char s[] )
{
	
	for ( int i=0; s[i] ; ++ i )
		s[i] -= 32;
	
}

int main ( )
{
	
	freopen ( "dictionary.in" , "r" , stdin ) ;
	freopen ( "dictionary.out", "w" , stdout ) ;
	
	char s [ 150 ] ;
	int nr = 0 , q ;
	
	for ( char letter = 'c' ; letter <= 'd'; ++letter )
	{
		
		printf ( "_global.words_%c=[ ", (char)(letter - 32) ) ;
		
		gets ( s ) ;
		while ( s[0] != letter ) 
			gets ( s ) ;
		q=0;
		while ( s[0] == letter )
		{
			toUpperCase(s);
			if ( q == 0 )
			{
				printf ( "\"%s\"", s ) ;
				q=1;
			}
			else
				printf ( ",\"%s\"", s ) ;
			++nr;
			if ( nr == 15 )
				printf ( "\n" ) ;
			gets ( s ) ;
		}
		printf ( "];\n" ) ;
	}
	
	
	return 0 ;
}*/
#include<iostream>
using namespace std;
int st[20],i,n,k;
void init()
{
	st[k]=0;
}

int succesor()
{
	if(st[k]<n) 
	{
		st[k]++; 
		return 1;
	}
	return 0;
}
int valid()
{
	int s=0;
	for(i=1;i<=k;i++) 
		s+=st[i];
	return (s<=n);
}
int solutie()
{
	int s=0;
	for(i=1;i<=k;i++) 
		s=s+st[i];
	if(s==n) 
		return 1;
	return 0 ;
}
void tipar()
{
	for(i=1;i<=k;i++) 
		cout<<st[i]<<" ";
	cout<<endl;
}
void bkt()
{
	int as;
	k=1;init();
	while(k>=1)
	{
		do{}
		while((as=succesor()) && !valid());
		if(as)
			if(solutie()) 
				tipar();
			else
			{
				k++;
				init();
			}
		else 
			k--;
	   }
}
int main()
{
	cout<<"n=";
	cin>>n;
	bkt();
	return 0 ;
}
