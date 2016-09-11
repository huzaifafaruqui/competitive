//let's steal some points
//ganda waala brute force

#include<bits/stdc++.h>

using namespace std;

#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007


int n,a[1001],m[1001][1001];
long long int ans;

void preprocess()
{
	int i,j;
	rep(i,0,n)
	rep(j,i,n)
	{
		if(i==j)
			m[i][j]=a[i];
		else
			m[i][j]=max(m[i][j-1],a[j]);
	}
}

int main()
{
	scanf("%d",&n);
	int i,j;
	rep(i,0,n)
		scanf("%d",&a[i]);
	
	preprocess();
	

	rep(i,0,n-1)
	{
		rep(j,i+1,n)
		{	
			if((a[i]&a[j])==a[i] or (a[i]&a[j])==a[j])
				ans+=m[i][j];			
		}
	}
	
	printf("%lld",ans);
	return 0;
}	

