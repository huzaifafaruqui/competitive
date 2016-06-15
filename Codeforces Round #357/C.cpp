#include<cstdio>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{	int i,n,a;
	char inp[100];
	vector< pair<int, int> > out;
	priority_queue<int,vector<int>,greater<int> > min_heap;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
 		scanf("%s",inp);
			if(strcmp(inp,"removeMin")!=0)
				scanf("%d",&a);
		if(strcmp(inp,"insert")==0)                   //1insert 2remove 3getmin
		{    //printf("%d inserted..",a);
			min_heap.push(a);
			out.push_back(make_pair(1,a));
		}
		else if(strcmp(inp,"getMin")==0)
		{
			while(!min_heap.empty()&&min_heap.top()<a)
			{	
				min_heap.pop();
				out.push_back(make_pair(2,0));
			}
			
			if(!min_heap.empty()&&min_heap.top()==a)
			{
				out.push_back(make_pair(3,a));
			}
			else
				{
					min_heap.push(a);
					out.push_back(make_pair(1,a));
					out.push_back(make_pair(3,a));
				}
		}
	
		else if(min_heap.empty())
		{
							out.push_back(make_pair(1,1));
				out.push_back(make_pair(2,1));
		}
		else
			{
			 out.push_back(make_pair(2,0));
				min_heap.pop();
			}
	}
	printf("%d\n",out.size());
	for(i=0;i<out.size();i++)
	{
		if(out[i].first==1)
			printf("insert %d\n",out[i].second);
		else if(out[i].first==2)
			printf("removeMin\n");
		else
			printf("getMin %d\n",out[i].second);
	}
	return 0;
}	
