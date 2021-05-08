#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n,m;

vector<int> adj[200009];
int depth[200009];
int up[200009];
vector<int> ans;
int c=0;

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
	unordered_set<int> st;
	int res;
	while (m--){
		st={};
		ans={};
		res=0;
		cin >> kn;
		max_depth=0;
		for (int i=0;i<kn;i++){
			cin >> input;
			//ans.pb(input);
			st.insert(up[input]);
			if (depth[input]<max_depth){
				max_node=input;
				max_depth=depth[input];
			}
		}
		while (max_node!=0){
			max_node=up[max_node];
			//st.insert(max_node);
			st.erase(max_node);
			if (st.size()==0){
				res=1;
				break;
			}
		}
		/*
		for (int i : ans){
			if (!st.count(up[i])){
				res=0;
				break;
			}
		}
		*/
		if (res){
			puts("YES");
		}
		else
			puts("NO");
	}
}