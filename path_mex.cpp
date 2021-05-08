#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> adj[200001];
vector<pair<int,int>> input;
int up[200001],cnt=0;
unordered_set<int> ans;

void dfs(int n){
	if (cnt==3) return;
	int suc=0;
	for (int i : adj[n]){
		if(up[n]!=i){
			up[i]=n;
			dfs(i);
			suc++;
		}
	}
	if(!suc || (n==1 && suc==1)){
		ans.insert(n);
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	up[1]=0;
	for (int i=0;i<n-1;i++){
		int i1,i2; cin>>i1>>i2;
		adj[i1].pb(i2);	
		adj[i2].pb(i1);
		input.pb({i1,i2});
	}
	dfs(1);
	int cnt2;
	/*
	if (cnt!=3){
		cnt2=0;
		while (--n)
			cout << cnt2++ << '\n';
	}*/
	//else{
		/*
	if (n==2){
		cout << 0 <<'\n';
		return 0;
	}*/
	cnt2=cnt;
	int cnt3=0;
	for(int i=0;i<n-1;i++){
		if (!ans.count(input[i].first) && !ans.count(input[i].second))
			cout << cnt2++ << '\n';
		else
			cout << cnt3++ << '\n';
	}
	//}
	//cout<<'\n';
}