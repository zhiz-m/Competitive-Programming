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
int n, v[N], adj[N][2], valid[N],par[N];
PII t[N];

void dfs(int u, int l, int r){
    if (u==-1)return;
    if (l>r)return;
    if (v[u]>=l && v[u]<=r)valid[v[u]]=1;
    //DEBUG(v[u]),DEBUG(l),DEBUG(r);
    dfs(adj[u][0],l,min(r,v[u]));
    dfs(adj[u][1],max(l,v[u]),r);
}

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n+1){
        cin>>v[i];
        cin>>adj[i][0]>>adj[i][1];
        t[i]=mp(v[i],i);
        valid[i]=par[i]=0;
    }
    sort(t+1,t+n+1);
    t[n+1]=mp(-1,-1);
    int cnt=0;
    rep(i,1,n+1){
        v[t[i].se]=cnt;
        if (t[i].fi!=t[i+1].fi)cnt++;
    }
    rep(i,1,n+1){
        if (adj[i][0]!=-1)par[adj[i][0]]=1;
        if (adj[i][1]!=-1)par[adj[i][1]]=1;
    }
    rep(i,1,n+1)if (par[i]==0)dfs(i,-1,1e9+10);
    int ans=0;
    rep(i,1,n+1)ans+=valid[v[i]]==0;
    cout<<ans<<nl;
}