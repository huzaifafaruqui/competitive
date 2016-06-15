#include<cstdio>
#include<string>
using namespace std;

int main()
{	int n,b,a,i,flag;
	char s[20];
	flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d",s,&b,&a);
		if(b>=2400 and a>b)
		{
			flag=1;
		}
	}
	if(flag)
	printf("YES");
	else
	printf("NO");
return 0;
}			
