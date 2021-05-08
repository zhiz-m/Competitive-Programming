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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N=200100;
ll n,tot=0;
vector<VI> adj(N);
VI cost(N),cur(N),fin(N);

void dfs1(int u, int prev, int c){
    cost[u]=min(c,cost[u]);
    each(i,adj[u]){
        if (i==prev)continue;
        dfs1(i,u,cost[u]);
    }
}

PII dfs2(int u, int prev){
    int odd=0,even=0;
    if (cur[u]==1 && fin[u]==0)odd++;
    else if (cur[u]==0 && fin[u]==1)even++;
    each(i,adj[u]){
        if (i==prev)continue;
        PII p=dfs2(i,u);
        odd+=p.fi,even+=p.se;
    }
    ll t=min(odd,even);
    tot+=t*cost[u];
    odd-=t;
    even-=t;
    return mp(odd,even);
}

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n+1){
        cin>>cost[i]>>cur[i]>>fin[i];
    }
    rep(i,1,n){
        int a,b;cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    dfs1(1,-1,2e9);
    PII p=dfs2(1,-1);
    if(p!=mp(0,0))cout<<-1<<nl;
    else cout<<2*tot<<nl;
}