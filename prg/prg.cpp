#include<iostream.h>

int f[11];

int main()
{
	
	int n,i,x,uc;
	
	cin>>n;
	
	for(i=1;i<=n;++i)
	{
		cin>>x;
		do
		{
			uc=x%10;//ultima cifra
			f[uc]=1;//marcam existenta cifrei
			x=x/10;//eliminam cifra
		}while(x);
	}
	
	for (i=0;i<10;++i)
		if( f[i]==1 ) //cifra exista
			cout<<i<<" ";//afisam cifra
	
	return 0;
}