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

ll n, v[N], l[N], m[N], e[N]; // citizens, leaf nodes, max citizens, ex citizens
VI adj[N];

void dfs1(int u, int prev){
    int suc=0;
    l[u] = 0;
    each(i,adj[u]){
        if (i==prev)continue;
        dfs1(i,u);
        suc=1;
        l[u]+=l[i];
    }
    if (!suc)l[u]=1;
}

void dfs2(int u, int prev){
    ll mx=0, ex=0;
    each(i,adj[u]){
        if (i==prev)continue;
        dfs2(i, u);
        mx=max(m[i],mx);
    }
    each(i,adj[u]){
        if (i==prev)continue;
        ex+=(mx-m[i])*l[i]+e[i];
    }
    //DEBUG(u),DEBUG(mx),DEBUG(l[u]),DEBUG(v[u]),DEBUG(ex);
    if (v[u]>=ex){
        if (ex!=0){v[u]-=ex;ex=0;}
        mx+=v[u]/l[u];
        mx+=v[u]%l[u]!=0;
        if (v[u]%l[u]!=0)ex=l[u]-v[u]%l[u];
        v[u]-=(v[u]/l[u])*l[u];
    }
    else ex-=v[u];
    e[u]=ex;
    m[u]=mx;
    //DEBUG(u),DEBUG(m[u]);
    //DEBUG(e[u]);
}

int main(){
    upgrade();
    cin>>n;
    rep(i,2,n+1){
        int a;cin>>a;
        adj[i].pb(a);
        adj[a].pb(i);
    }
    rep(i,1,n+1)cin>>v[i];
    dfs1(1,-1);
    dfs2(1,-1);
    cout<<m[1]<<nl;
}