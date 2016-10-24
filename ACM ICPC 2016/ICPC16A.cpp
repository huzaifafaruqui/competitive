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
	int x1,y1,x2,y2,ans=0;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	
	if(x1==x2)
	{
		if(y1<y2)
		{
			ans=1;
		}
		else if(y1>y2)
			ans=2;
	
}
 
	else if(y1==y2)
	{
		if(x1<x2)
		{
			ans=3;
		}
		else if(x1>x2)
			ans=4;
	}
	
	
	if(ans==0)
	{
		puts("sad");
	}
	else if(ans==1)
	{
		puts("up");
	}
	else if(ans==2)
	{
		puts("down");
	}
	
	else if(ans==3)
		puts("right");
	else puts("left");
	
 
 
}
 
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)	
	solve();
	
	return 0;
}	
