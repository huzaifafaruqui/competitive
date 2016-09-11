//BRUTE FORCE
//BRUTE FORCE
//BRUTE FORCE
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define rep(i,j,k) for(i=j;i<k;i++)
#define MOD 1000000007
#define mp make_pair
#define pb push_back
 
long long h[11],m[11];
 
long long n, maxh;
 
vector< pair<long long,long long> > ans;
 
long long zigzag1(long long t)  //h1 is small
{
	// Case 'M', i.e. h1 is small long 
	
	long long i;
	rep(i,1,n)
	{
		if(i&1)
		{
			if(h[i]+t*m[i]<=h[i-1]+t*m[i-1])
				return 0;
		}
		else if(h[i]+t*m[i]>=h[i-1]+t*m[i-1])
				return 0;
	}
	return 1;
}
 
long long zigzag2(long long t)  //h1 is large
{
	// Case 'W', i.e. h1 is large
	long long i;
	rep(i,1,n)
	{
		if(i&1)
		{
			if(h[i]+t*m[i]>=h[i-1]+t*m[i-1])
				return 0;
		}
		else if(h[i]+t*m[i]<=h[i-1]+t*m[i-1])
				return 0;
	}
	return 1;
}
 
 long long b_search(long long s, long long a, long long b,long long c, long long d)
 {
 	long long e,lo,hi,mid;
 	
 	lo=s;
 	hi=MOD-7;
 	e=-1;
 	if(a+b*s<c+d*s)
 		return s;
 	while(lo<=hi)
 	{
 		mid=(lo+hi)/2;
 		
 		if(a+b*mid<c+d*mid)
 		{	
 			e=mid;
 			hi=mid-1;
 		}
 		else
 			lo=mid+1;
 	}
 	
 	return e;
 }	
long long b_search2(long long a, long long b,long long c, long long d)
 {
 	long long e,lo,hi,mid;
 	
 	lo=0;
 	hi=MOD-7;
 	e=-1;
 	
 	while(lo<=hi)
 	{
 		mid=(lo+hi)/2;
 		
 		if(a+b*mid>=c+d*mid)
 		{	
 			e=mid;
 			hi=mid-1;
 		}
 		else
 			lo=mid+1;
 	}
 	
 	return e;
 }	




long long get_start(long long x)  //Parameter x is for case no.
{
	long long t_min,t_max,i,r=0;
	t_max=MOD;
	t_min=0;
	if(x==1)
	{
		rep(i,1,n)
		{
			
			if(i&1)  //odd no.
			{
				
				if(h[i]>h[i-1])
				{
					r=b_search2(h[i-1],m[i-1],h[i],m[i]);
					if(r!=-1)
					t_max=min(t_max,r-1);
					if(t_min>t_max)	
						return -1;
				}	
				else{	
					r=b_search(t_min,h[i-1],m[i-1],h[i],m[i]);
					if(r==-1)
						return -1;	
					t_min=max(t_min,r);  
					if(t_min>t_max)	
						return -1;
					}	
			
				
				
			}
			else
			{
				
				
				if(h[i]<h[i-1])
				{
					r=b_search2(h[i],m[i],h[i-1],m[i-1]);
					if(r!=-1)
					t_max=min(t_max,r-1);
					if(t_min>t_max)	
						return -1;
				}	
				else{	
					r=b_search(t_min,h[i],m[i],h[i-1],m[i-1]);
					if(r==-1)
						return -1;	
					t_min=max(t_min,r);  
					if(t_min>t_max)	
						return -1;
					}	
				
				
			}
		}
		
		return t_min;
	}
	
	else if(x==2)
	{
		rep(i,1,n)
		{
			if(i&1)
			{
				
				
				if(h[i]<h[i-1])
				{
					r=b_search2(h[i],m[i],h[i-1],m[i-1]);
					if(r!=-1)
					t_max=min(t_max,r-1);
					if(t_min>t_max)	
						return -1;
				}	
				else{	
					r=b_search(t_min,h[i],m[i],h[i-1],m[i-1]);
					if(r==-1)
						return -1;	
					t_min=max(t_min,r);  
					if(t_min>t_max)	
						return -1;
					} 
				
						
			}
			else
			{
				
					
				if(h[i]>h[i-1])
				{
					r=b_search2(h[i-1],m[i-1],h[i],m[i]);
					if(r!=-1)
					t_max=min(t_max,r-1);
					if(t_min>t_max)	
						return -1;
				}	
				else{	
					r=b_search(t_min,h[i-1],m[i-1],h[i],m[i]);
					if(r==-1)
						return -1;	
					t_min=max(t_min,r);  
					if(t_min>t_max)	
						return -1;
					}	
						
					
				
			}
		}
		return t_min;
	}					
	
}

 
long long get_end(long long x, long long s)    
{
      /* Search for end point
   	returns -1 for infinity
   	
   	x=case no.
   	s=start point
   */	
	long long lo,hi,e,mid;
	
	e=-1;
	lo=s+1;
	hi=MOD-7;
	
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if( (x==1 and !zigzag1(mid)) or (x==2 and !zigzag2(mid)) )	
		{	e=mid;
			hi=mid-1;
		}	
		else
		{	
			lo=mid+1;
		}
	}
	
	return e; 
}	
 
int main()
{
	long long i,t,start,end;
	
	scanf("%lld",&t);
	
	do{
	
	maxh=0;
	ans.clear();
	scanf("%lld",&n);
	
	rep(i,0,n){
		scanf("%lld %lld",&h[i],&m[i]);
		maxh=max(h[i],maxh);
		}
		
	if(n==1)
	{
		printf("1\n0 Inf\n");
		continue;
	}
		
	start=get_start(1);   //find starting polong long for 'M' case  
	
	if(start!=-1)   //if start polong long for case 'M' found
	{
		end=get_end(1,start);
		ans.pb(mp(start,end));
	}	
	
	start=get_start(2);  //Similarly, for case 'W'
	
	if(start!=-1)
	{
		end=get_end(2,start);
		ans.pb(mp(start,end));
	}

	sort(ans.begin(),ans.end());
	if(ans.size()>1 and ans[1].first==ans[0].second)
		{
			ans[0].second=ans[1].second;
			ans.pop_back();
		}
	
	printf("%d\n",ans.size());
	
	rep(i,0,ans.size())
	{
		printf("%lld ",ans[i].first);
		if(ans[i].second==-1)
			printf("Inf\n");
		else
			printf("%lld\n",ans[i].second-1);
					
	}
	
	}while(--t);
	return 0;
}	
