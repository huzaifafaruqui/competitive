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
		int d,ans=0;
		scanf("%d",&d);
		d++;
		while(d)
		{
			ans+=d%10;
			d/=10;
		}
		ans%=9;
	if(!ans)
		ans=9;
		printf("%d\n",ans);
 
}
 
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)	
	solve();
	
	return 0;
}	
