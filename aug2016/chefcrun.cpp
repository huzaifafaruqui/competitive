#include<bits/stdc++.h>

using namespace std;

#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007
#define pb push_back

long long from_left,from_right,sum,ans,s1,s2;

int a[200005];

int main()
{
	int t,n,i,x,y;
	
	scanf("%d",&t);
	
	do{
		
		
		scanf("%d",&n);
		rep(i,0,n)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d %d",&x,&y);
		x--;
		y--;
		
		
		sum=s1=s2=from_right=from_left=0;
		
		//From right
		i=x;
		while(i!=y)
		{
			
			from_right+=a[i];
			
			sum+=a[i];
			
			if(sum<0)
				sum=0;
			s1=max(sum,s1);
			
			i++;
			i%=n;
		}
		
		
		sum=0;
		
		//From left
		i=x;
		
		while(i!=y)
		{
			i--;
			if(i<0)
				i+=n;
			sum+=a[i];
			if(sum<0)
				sum=0;
			s2=max(sum,s2);

			from_left+=a[i];
		}		
	
	
		ans=min(2*(from_right-s1)+from_left,2*(from_left-s2)+from_right);
		
		
		printf("%lld\n",ans);
	
	}while(--t);
	return 0;
}	
