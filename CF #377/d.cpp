#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007
#define inf 1000000000000000000
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define clr(x,n) for(int _=0;_<n;_++)x[_]=0;
#define trace(x)                cerr << #x << ": " << x << endl;
#define tracearray(x,n)	for(int i=0; i<n;i++) cerr << #x << "[" << i<< "]: " << x[i] << endl;

int a[100005],b[100005],p[100005],m;

int poss(int n)
{
	int rem=m,l=0,x,i;
	
	for(i=n-1;i>=l;i--)
	{
		x=a[i];
		
		if(x!=0 and !b[x])
		{
			if(p[x]>i-l)
			{
				return 0;
			}
			rem--;
			
			b[x]=1;
			l+=p[x];
			
			if(rem==0)
				return 1;
		}
		
		else
			l=max(0,l-1);
	}

	if(rem)
		return 0;
	return 1;				
	
}
void solve()
{
	int n,mid,low,high,i,ans;
	
	scanf("%d %d",&n,&m);
	rep(i,0,n)
	{
		scanf("%d",&a[i]);
	}
	rep(i,1,m+1)
		scanf("%d",&p[i]);
	low=1;
	high=n;
	
	if(poss(high)==0)
	{
		puts("-1");
		return;
	}
	
	else
	{
		ans=high;
		clr(b,m+1);
		while(low<=high)
		{
			mid=(low+high)/2;
			if(poss(mid))
			{
				ans=mid;
				high=mid-1;
			}
			else
				low=mid+1;
			clr(b,m+1);	
		}
		
		printf("%d",ans);
	}

}

int main()
{
	int t,i;
	t=1;
	
	for(i=1;i<=t;i++){
		solve();
	}
	
	
	return 0;
}	
