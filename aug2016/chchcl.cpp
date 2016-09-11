#include<bits/stdc++.h>

using namespace std;

#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007

int main()
{
	int t;
	long long int n,m;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		((n*m)&1==1)?puts("No"):puts("Yes");
	}
	
	
	
	return 0;
}	
