#include<cstdio>

int main ( )
{
	
	freopen ( "cifre1.in","r",stdin ) ;
	freopen ( "cifre1.out","w",stdout ) ;
	
	long long n ;
	
	scanf ( "%lld", & n ) ;
	long long cif = 1 ;
	long long put = 9 , putv=0;
	long long NR = 0 ;
	
	while ( n > put )
	{
		NR += (long long )cif * ((put+1)-putv) ;
		putv=put+1L;
		put*=10;
		put+=9;
		++cif;
	}
	if ( NR == 0 )
		NR+=n;
	else
	{
		put-=9;
		put/=10;
		NR += ((long long)n-put)*cif ;
		--NR;
	}
	printf ( "%lld", NR ) ;
	
	
	return 0 ;
}