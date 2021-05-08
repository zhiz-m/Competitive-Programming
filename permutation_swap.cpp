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
#define each(a,x) for(auto&a:(x))
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef long long ll;
typedef long double ld;
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N=1000100;
int n,m,v[N],ans[N],vis[N];
VI adj[N], v1, v2;

void dfs(int u){
    if (vis[u]) return;
    vis[u]=1;
    v1.pb(u);
    v2.pb(-v[u]);
    each(i,adj[u]) dfs(i);
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,1,n+1)cin>>v[i],vis[i]=0;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    rep(i,1,n+1){
        if (vis[i])continue;
        dfs(i);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        rep(j,0,SZ(v1))ans[v1[j]]=-v2[j];
        v1.clear();
        v2.clear();
    }
    rep(i,1,n+1)cout<<ans[i]<<" \n"[i==n];
}