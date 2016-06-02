/*Program Developed By oculto*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<utility>
#include<string.h>
#include<cstdio>

#define MOD 1000000007
#define rep(i,a,n) for(i=a;i<n;i++)
#define nl printf("\n")
#define MAX_INT 2147483647
using namespace std;

int index(char c)
{
	if(c>='0'&&c<='9')
	return c-'0';
	if(c>='A'&&c<='Z')
	return c-'A'+10;
	if(c>='a'&&c<='z')
	return c-'a'+36;
	if(c=='-')
	return 62;
	return 63;
	
}
int a[64];
int main()
{
	long long ans=1;
	int i,j,k;
	char s[100005];
	rep(i,0,64)
	rep(j,0,64)
	{
		k=i&j;
		a[k]++;
	}/*
	rep(i,0,64)
	cout<<a[i]<<" ";*/
		//a[i&j]++;
	
	//for(i=0;i<64;i++)
	
	cin>>s;	
	//scanf("%s",s);
	rep(i,0,strlen(s))
	{
		k=index(s[i]);
		//cout<<k<<" ";
		ans=(ans%MOD)*(a[k]%MOD);
		ans%=MOD;
	}
	ans%=MOD;
	//printf("%I64d",ans%MOD);
	cout<<ans;
return 0;
}

