#include<bits/stdc++.h>

using namespace std;
 
#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007
#define N 200005
#define f first
#define s second
 
#define pii pair<int,int>
#define piii pair< pii, int > 
#define mp make_pair
#define ll long long int 
#define gc getchar_unlocked
 
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
 
 
 
int maxy,n;
 
bool cmp(piii a, piii b)
{
	if(a.f.f<b.f.f)  // if x co-ordinate is smaller
		return true;
	else if(a.f.f==b.f.f and a.f.s<b.f.s) //x coordinate is equal and y is smaller
		return true;
	return false;
}	
 
vector< piii > pts;
 
long long int tree[4*N],lazy[4*N];
     
     
    
    
long long int ST[4*N], Add[4*N];
 
 
void init(int k,int L,int R)
{
	ST[k]=0;
	Add[k]=0;
	if(L==R)
		return ;
	int mid = (L + R) >> 1;	
	init(k << 1, L, mid);	 
 	init((k << 1) + 1, mid + 1,R);
}

void update(int k, int L, int R, int i, int j, int v)
{
    if (L > j || R < i) return;
    if (i <= L && R <= j)
    {
        ST[k] += v;
        Add[k] += v;
        return;
    }
 
    Add[k << 1] += Add[k];
    Add[(k << 1) + 1] += Add[k];
    ST[k << 1] += Add[k];
    ST[(k << 1) + 1] += Add[k];
    Add[k] = 0;
 
    int mid = (L + R) >> 1;
    update(k << 1, L, mid, i, j, v);
    update((k << 1) + 1, mid + 1, R, i, j, v);
 
    ST[k] = max(ST[k << 1], ST[(k << 1) + 1]);
}

 
long long query(int k, int L, int R, int i, int j)
{
    if (L > j || R < i) return -1000000000;
    if (i <= L && R <= j) return ST[k];
 
    Add[k << 1] += Add[k];
    Add[(k << 1) + 1] += Add[k];
    ST[k << 1] += Add[k];
    ST[(k << 1) + 1] += Add[k];
    Add[k] = 0;
 
    int mid = (L + R) >> 1;
    return max(query(k << 1, L, mid, i, j), query((k << 1) + 1, mid + 1, R, i, j));
}
    		
long long solve(int l)
{
	long long ans=0;
	int i,j;
	
	i=j=0;
	
	while(j<n)
	{
		while(j<n and pts[j].f.f-pts[i].f.f<=l-1)
		{
			update(1,1,maxy+l-1,pts[j].f.s,pts[j].f.s+l-1,pts[j].s);
			j++;
		}
		
		ans=max(query(1,1,maxy+l-1,1,maxy+l-1),ans);
		int cx=pts[i].f.f;
		while(i<n and pts[i].f.f==cx){
			update(1,1,maxy+l-1,pts[i].f.s,pts[i].f.s+l-1,-pts[i].s); //delete an interval
				i++;
		}	
	} //modified sweep line algo
	
	
	
	return ans;
	
}	
				
 
int main()
{
	long long out,ans;
	
	out=ans=maxy=0;
	
	int l,low,high,mid,i,x,y,c,len;
	
	scanint(n);
	scanint(l);
	
	pts.resize(n);
	
	rep(i,0,n)
	{
		scanint(x);
		scanint(y);
		scanint(c);
		pts[i]=mp(mp(x,y),c);
		maxy=max(y,maxy);
	} //input	
	
	sort(pts.begin(),pts.end(),cmp);  //checked working fine
	
	low=1;
	high=l;
	
	len=l;
	
	
 
	
	ans=solve(l);  //maximum possible in square of side l
	
 
	init(1,1,maxy+l-1);
	while(low<=high)
	{                                                                               
		
		mid=(low+high)/2;
		out=solve(mid);
		//cout<<mid<<endl;
		if(out<ans)
		{
			low=mid+1;
		}
		else if(out>=ans)
		{
			len=mid;
			high=mid-1;
		}
		init(1,1,maxy+l-1);
	}  //binary search for minimum possible length
	
	printf("%lld %d",ans,len);
	
	return 0;
}	
 
