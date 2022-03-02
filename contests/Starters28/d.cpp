#include<iostream>
#include <stdio.h>
#include<vector>
using namespace std;
#define endl "\n"
#define int long long int 

vector<vector<int>> graph;
vector<vector<int>> depth;

int max_depth=0;
int n;
void dfs(int u,int p,int d){
	depth[d].push_back(u);
	max_depth=max(max_depth,d);
	for(auto x:graph[u]){
		if(x==p)
			continue;
		dfs(x,u,d+1);
	}
}

bool check(int d){
	cout<<"? "<<depth[d].size()<<" ";
	for(auto u:depth[d])
		cout<<u+1<<" ";
	cout<<endl << flush;
	int flag;
	cin>>flag;
	/* fflush(); */
	return flag==1;
}

int search_depth(){
	int start=0,end=max_depth;
	int ans=0;
	while(start<=end){
		int mid=(start+end)/2;
		if(check(mid))
			end=mid-1,ans=mid;
		else
			start=mid+1;
	}
	return ans;
}

bool check_set(int start,int end,int d){
	cout<<"? "<<end-start+1<<" ";
	for(int i=start;i<=end;i++)
		cout<<depth[d][i]+1<<" ";
	cout<< endl << flush;
	int flag;
	cin>>flag;
	return flag==1;
}

int search_set(int d){

	int start=0,end=depth[d].size() - 1;
	int mid=start;
	while(start<end){
		mid=(start+end)/2;
		if(check_set(start,mid,d))
			end=mid;
		else
			start=mid+1;
	}
	return end;

}

signed main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		graph.clear();
		depth.clear();
		graph.resize(n);
		depth.resize(n);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			u--,v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		dfs(0,-1,0);
		/* cout<<max_depth<<endl << flush; */
		/* for(int i=0;i<=max_depth;i++){ */
		/* 	for(auto x:depth[i]) */
		/* 		cout<<x<<" "; */
		/* 	cout<<endl << flush; */
		/* } */
		int d=search_depth();
		/* cout<<"Depth :"<<d<<endl << flush; */
		int answer=search_set(d);
		cout<<"! "<<depth[d][answer]+1<<endl << flush;
	}
	return 0;
}