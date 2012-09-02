#include<stdio.h>
short int func(int a,int b)
{
	if(a==0 && b==0) return 1;
	if(a==0 || b==0) return 0;
	return ( func(a - 1, b) + a * func(a - 1, b - 1) )%3;
}	
int main()
{
	freopen("mod3.in","r",stdin);
	freopen("mod3.out","w",stdout);
	int t,i,a,b;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%hd\n",func(a,b));
	}
	return 0;
}