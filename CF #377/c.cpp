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

LL max(LL a, LL b, LL c)
{
	return max(max(a,b),c);
}

void solve()
{
	LL b,d,s,ans,ma,mi,p[][3]={{0,0,0},{1,1,0},{1,0,0}};
	cin>>b>>d>>s;
	int i,j;
	
	ans=3*max(b,d,s)-(b+d+s);
	
	
	
	
	d++;
	ans=min(ans,3*max(b,d,s)-(b+d+s));
	d--;
	b++;
	ans=min(ans,3*max(b,d,s)-(b+d+s));
	b--;
	s++;
	ans=min(ans,3*max(b,d,s)-(b+d+s));
	s--;
	b--;
	ans=min(ans,3*max(b,d,s)-(b+d+s));	
	b++;
	d--;
	ans=min(ans,3*max(b,d,s)-(b+d+s));
	d++;
	s--;
	ans=min(ans,3*max(b,d,s)-(b+d+s));
	s++;

cout<<ans;

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
