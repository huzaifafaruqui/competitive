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
 
#define N 800005
 
int a[N],m[N];
vector<int> fact[N];
 
 
void solve()
{
	int n,i,j,lol=0;
	LL ans=0,temp;
	clr(m,N);
	scanf("%d",&n);
	rep(i,0,n)
	{
		scanf("%d",&a[i]);
		lol=max(lol,a[i]);
	}
	sort(a,a+n);
	
	rep(i,0,n)
	{
		
		
		m[a[i]]++;
		m[a[i]]%=MOD;		
		for(j=2*a[i];j<=lol;j+=a[i])
		{
			m[j]+=m[a[i]];
			m[j]%=MOD;
		}
		
	}
	
	
		
	rep(i,0,n)
	{		
		ans+=m[a[i]];
		ans%=MOD;
	}
		printf("%lld\n",ans);
}
 
int main()
{
	
	
	int t,i,j;
	
	
	
	scanf("%d",&t);
	for(i=1;i<=t;i++)	
	solve();
	
	return 0;
}	
