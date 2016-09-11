#include<bits/stdc++.h>

using namespace std;

#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007
#define inf 1000000000000000000
#define pb push_back
#define mp make_pair
#define LL long long int
#define all(x) x.begin(),x.end()
#define clr(x,n) for(int _=0;_<n;_++)x[_]=0;
#define trace(x)                cerr << #x << ": " << x << endl;
#define tracearray(x,n)	for(int i=0; i<n;i++) cerr << #x << "[" << i<< "]: " << x[i] << endl;

#define N 501

int adj[N][N];
bitset <500> FL[31][N];

void solve()
{
	int n,i,j,k,m,x,y,t;
	
	bitset<500> out,temp;
	
	scanf("%d",&n);
	
	rep(i,0,n)
	{
		rep(j,0,n){
			scanf("%d",&adj[i][j]);
			FL[0][i][j]=adj[i][j];
			}
	}
	
	rep(i,1,31)
	{
		rep(j,0,n)
		{
			rep(k,0,n)
				if(FL[i-1][j][k])
					FL[i][j]|=FL[i-1][k];
		}
	}
	
	
	scanf("%d",&m);
	
	rep(i,0,m)
	{
		scanf("%d %d",&y,&x);
		out&=0;
		
		x--;
		out[x]=1;
				
		t=0;
		while(y)
		{
			if(y&1){
			temp=0;
			rep(j,0,n)
			{
				if(out[j])
				{
					temp|=FL[t][j];	
				}
			}
			out=temp;
			}
			t++;
			y=y>>1;
				
		}
		
		if(out.any())
		{
			printf("%d\n",out.count());
			rep(j,0,n)
			{
				if(out[j])
				printf("%d ",j+1);
			}
		}
		else
		{
			printf("0\n-1");
		}
		
		puts("");		
		
	}//for m		
			
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
