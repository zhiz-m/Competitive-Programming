#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n,m;

vector<int> adj[200009];
int depth[200009];
int up[200009];
vector<pair<int,int>> ans;
int c=0;

bool rev(const pair<int,int> &a,const pair<int,int> &b){
	return a.first < b.first;
}

int dfs(int nd, int prev){
	c--;
	up[nd]=prev;
	depth[nd]=c;
	for (int i : adj[nd]){
		if (i!=prev){
			//puts("down");
			dfs(i,nd);
		}
	}
	c++;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n >> m;
	int in1,in2;
	for (int i=0;i<n-1;i++){
		cin >> in1 >> in2;
		adj[in1].pb(in2);
		adj[in2].pb(in1);
	}
	dfs(1,0);
	int kn;
	int max_node;
	int max_depth;
	int input;
	int res;
	while (m--){
		st={};
		ans={};
		res=0;
		cin >> kn;
		max_depth=0;
		for (int i=0;i<kn;i++){
			cin >> input;
			ans.pb(make_pair(depth[input],input));
			if (depth[input]<max_depth){
				max_node=input;
				max_depth=depth[input];
			}
		}
		sort(ans.begin(),ans.end(),rev);
		depth=1;
		int ind=0;
		for(;;){
			if (ans[0]!=)
		}
		if (res){
			puts("YES");
		}
		else
			puts("NO");
	}
}