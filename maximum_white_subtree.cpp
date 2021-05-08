#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define SZ(x) (int)(x).size()
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=b-1;i>=a;i--)
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);}

VI adj[200001];
VI colour(200001);
stack<int> stk;
queue<int> qu;
VI up(200001);
VI mx(200001);

void increase(int v){
	VI sums;
	int cnt=0;
	for (int i: adj[v]){
		if(i!=up[v] && mx[i]>0)
			cnt+=mx[i];
	}
	mx[v]=cnt+colour[v];
}

void bfs(){
	if(SZ(qu)==0)
		return;
	int v=qu.front();
	qu.pop();
	for (int i : adj[v]){
		if (i!=up[v]){
			qu.push(i);
			up[i]=v;
		}
	}
	stk.push(v);
	bfs();
}

void dfs(int v){
	if(v!=1){
		if (mx[v]>0){
			mx[v]=max(mx[v],mx[up[v]]);
		}
		else{
			mx[v]=max(mx[v],mx[v]+mx[up[v]]);
		}
	}
	for (int i : adj[v]){
		if (i != up[v])
			dfs(i);
	}
}

int main(){
	upgrade();
	int n;cin>>n;
	rep(i,1,n+1){
		cin>>colour[i];
		colour[i]=(colour[i]==1)?colour[i]:-1;
	}
	int i1,i2;
	rep(zz,0,n-1){
		cin>>i1>>i2;
		adj[i1].pb(i2);
		adj[i2].pb(i1);
	}
	up[1]=1;
	qu.push(1);
	bfs();
	while(!stk.empty()){
		increase(stk.top());
		stk.pop();
	}
	dfs(1);
	rep(i,1,n+1){
		cout<<mx[i]<<" ";
	}
	cout<<'\n';
}