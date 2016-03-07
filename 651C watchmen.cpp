/*Program Developed By oculto*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<utility>
#include<string.h>
#include<cstdio>
#include<map>
#define MOD 1000000007
#define FOR(i,a,n) for(i=a;i<n;i++)
#define nl  cout<<'\n'
#define MAX_INT 2147483647
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	pair<int, int> g;
	map< pair<int, int>,int > cpoints;
	map<pair<int, int>, int>::iterator it2;
	map<int ,int> x,y;
	map<int, int>::iterator it;
	int n,i,j,a,b;
	cin>>n;
	long long c,ans=0;
	
	FOR(i,0,n)
	{  cin>>a>>b;
	   g=make_pair(a,b);
		cpoints[g]++;
		x[a]++;
		y[b]++;
		
	}
	ans=0;
	
	for(it=x.begin();it!=x.end();it++)
	{  
		if(it->second>1)
		{
			c=(long long)it->second*(it->second-1);
			ans+=c/2;
		}
	}
	
	for(it=y.begin();it!=y.end();it++)
	{
		if(it->second>1)
		{
			c=(long long)it->second*(it->second-1);
			ans+=c/2;
		}
	}
	
	for(it2=cpoints.begin();it2!=cpoints.end();it2++)
	{
		if(it2->second>1)
		{
			c=(long long)it2->second*(it2->second-1);
			ans-=c/2;
		}
	}
	
	//sort(points.begin(),points
	
	
	cout<<ans;
return 0;
}
