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
void solve()
{
	int n,k,sum=0,a[1000],b,i;
	scanf("%d %d",&n,&k);
	rep(i,0,n)
	{
		scanf("%d",&a[i]);
		
	}
	
	
	rep(i,1,n)
	{
		if(a[i]+a[i-1]<k)
		{
			b=k-(a[i]+a[i-1]);
			a[i]+=b;
			sum+=b;
		}
	}
	
	printf("%d\n",sum);
	rep(i,0,n)
	{
		printf("%d ",a[i]);
	}
		

}

int main()
{
	int t,i;
	t=1;
	//scanf("%d",&t);
	for(i=1;i<=t;i++){
		solve();
	}
	
	
	return 0;
}	
