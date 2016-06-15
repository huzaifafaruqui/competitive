#include<cstdio>

using namespace std;

int main()
{
	int a,b,c,n,i,j,k,flag;
	flag=0;
	scanf("%d",&n);
	for(i=0;i<=n;i+=1234567)
	{
		for(j=0;i+j<=n;j+=123456)	
			{
			
				if((n-i-j)%1234==0)
				{
					flag=1;
					break;
				}
			}
			
			
		if(flag)
		break;
	}					
	if(flag)
	printf("YES");
	else
	printf("NO");
	
return 0;
}	
