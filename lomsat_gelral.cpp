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

const int N=100100;
int n;
VI adj[N];
ll ans[N],col[N],oc[N],ind[N];
pair<ll,ll> ind2[N];//ans,oc
map<int,int> v[N];

int join(int t,int u, int d){
    if (SZ(v[u])>SZ(v[d]))swap(u,d);
    ans[t]=ind2[d].fi,oc[t]=ind2[d].se;
    each(i,v[u]){
        v[d][i.fi]+=i.se;
        if (v[d][i.fi]==oc[t]) ans[t]+=i.fi;
        else if (v[d][i.fi]>oc[t]) ans[t]=i.fi,oc[t]=v[d][i.fi];
    }
    return d;
}

void dfs(int u, int prev){
    ans[u]=col[u];
    oc[u]=1;
    v[u][col[u]]=1;
    ind[u]=u;
    ind2[u]=mp(ans[u],oc[u]);
    each(i,adj[u]){
        if (i==prev)continue;
        dfs(i,u);
        ind[u]=join(u,ind[u],ind[i]);
        ind2[ind[u]]=mp(ans[u],oc[u]);
        //v[i].clear();
        //DEBUG(u),DEBUG(i);
    }
}

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n+1)cin>>col[i];
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,-1);
    rep(i,1,n+1)cout<<ans[i]<<" \n"[i==n];
}  