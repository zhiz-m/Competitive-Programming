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
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);}

VI adj[200001];
//int dist[200001];
//int down[200001];
ll num=0;
VLL ans;

void dfs(int n, int prev, int d){
	//dist[n]=d;
	int cur=num;
	for(int i : adj[n]){
		if (i!=prev){
			dfs(i,n,d+1);
		}
	}
	//down[n]=num-cur;
	//if (d==0)d=1;
	ans.pb(d-num+cur);
	num++;	
}

int main(){
	upgrade();
	ll n,k;
	cin>>n>>k;
	rep(i,0,n-1){
		ll a,b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	dfs(1,0,0);
	sort(all(ans),greater<ll>());
	ll cnt=0;
	rep(i,0,k)
		cnt+=ans[i];
	cout<<cnt<<nl;
}