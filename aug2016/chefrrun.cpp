#include<bits/stdc++.h>

using namespace std;

#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007

vector< int > graph;
vector< vector<int> > ulta_graph;
stack<int> sk;
int total,v[100005];

void dfs(int x)
{
	v[x]=1;
	
	if(!v[graph[x]])
		dfs(graph[x]);
	sk.push(x);	
}

void dfs2(int x)
{
	v[x]=1;
	total++;
	int i;
	
	rep(i,0,ulta_graph[x].size())
		if(!v[ulta_graph[x][i]])
			dfs2(ulta_graph[x][i]);
}

int main()
{
	int t,n,ans,i,x;
	
	scanf("%d",&t);
	
	do{
		
		ans=0;
		scanf("%d",&n);
		
		rep(i,0,n)
			v[i]=0;
			
		graph.resize(n);
		ulta_graph.resize(n);
		
		rep(i,0,n)
		{
			scanf("%d",&x);
			if((x+1+i)%n==i)
				{
					ans++;
					continue;
				}
			graph[i]=(x+1+i)%n;
			ulta_graph[(x+1+i)%n].push_back(i);
		}
		
		rep(i,0,n)
			if(!v[i])
				dfs(i);	
		
		rep(i,0,n)
			v[i]=0;
			
		while(!sk.empty())
		{
			total=0;
			int x=sk.top();
			sk.pop();
			if(!v[x])
				dfs2(x);
			if(total>1)	
			ans+=total;			
		}

	graph.clear();
	ulta_graph.clear();
	printf("%d\n",ans);
	}while(--t);
	
	return 0;
}	
