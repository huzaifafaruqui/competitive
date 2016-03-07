/*Program Developed By oculto*/d
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<utility>
#include<string.h>
#include<cstdio>

#define MOD 1000000007
#define FOR(i,a,n) for(i=a;i<n;i++)
#define nl  cout<<'\n'
#define MAX_INT 2147483647
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,a,n,x,y;
	long long sum;
	cin>>n;
	x=y=0;
	FOR(i,0,n)
	{
	  cin>>a;	
	 	x=x|a;
	}
	
	FOR(i,0,n)
	{
	  cin>>a;	
	 	y=y|a;
	}
	
	sum=x+y;
	cout<<sum;
	
return 0;
}
