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

const int N=200200;
int n,x,par[N],h[N],d[N];
VI adj[N];

void dfs(int u){
    d[u]=h[u];
    each(i,adj[u]){
        if (i==par[u])continue;
        h[i]=h[u]+1;
        par[i]=u;
        dfs(i);
        d[u]=max(d[u],d[i]);
    }
}

int main(){
    upgrade();
    cin>>n>>x;
    rep(i,1,n){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    par[1]=-1;
    h[1]=0;
    dfs(1);
    int cur=x;
    rep(i,0,(h[x]-1)/2){
        cur=par[cur];
    }
    cout<<d[cur]*2<<nl;
}