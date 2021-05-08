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
ll n,m,tot[N],h[N],s[N],suc;
VI adj[N];

void dfs1(int u, int prev){
    each(i,adj[u]){
        if (i==prev)continue;
        dfs1(i,u);
        tot[u]+=tot[i];
    }
    if (tot[u]+h[u]<0 || h[u]>tot[u]|| (tot[u]+h[u])%2==1)suc=0;
    h[u]=(tot[u]+h[u])/2;
    s[u]=tot[u]-h[u];
    //DEBUG(u),DEBUG(tot[u]),DEBUG(h[u]),DEBUG(s[u]);
}

void dfs2(int u, int prev){
    ll cnt=0;
    each(i,adj[u]){
        if (i==prev)continue;
        dfs2(i,u);
        cnt+=h[i];
    }
    if (h[u]<cnt)suc=0;
}

void solve(){
    cin>>n>>m;
    suc=1;
    rep(i,1,n+1)adj[i].clear();
    rep(i,1,n+1)cin>>tot[i];
    rep(i,1,n+1)cin>>h[i];
    rep(i,1,n){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    cout<<(suc?"YES":"NO")<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}