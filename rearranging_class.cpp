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
ll a[N],b[N],c[N],n,one[N],zero[N]; //desired one but given zero, desired zero but given one
VI adj[N];
ll ans=0;

void dfs1(int u, int prev, ll best=1e9){
    
    best=min(best,a[u]);
    a[u]=best;
    //DEBUG(u),DEBUG(best);
    each(i,adj[u]){
        if (i==prev)continue;
        dfs1(i,u,best);
    }
}

void dfs2(int u, int prev){
    if (b[u] && !c[u])zero[u]++;
    else if (!b[u] && c[u]) one[u]++;
    each(i,adj[u]){
        if (i==prev)continue;
        dfs2(i,u);
        one[u]+=one[i];
        zero[u]+=zero[i];
    }
    int t=min(zero[u],one[u]);
    ans+=2*t*a[u];
    zero[u]-=t,one[u]-=t;
}

int main(){
    upgrade();
    cin>>n;
    memset(one,0,sizeof(one));
    memset(zero,0,sizeof(zero));
    rep(i,1,n+1)cin>>a[i]>>b[i]>>c[i];
    rep(i,1,n){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    //DEBUG(1);
    dfs1(1,-1,1e9);
    //DEBUG(2);
    dfs2(1,-1);
    //DEBUG(3);
    if (one[1]!=zero[1]){
        cout<<-1<<nl;
        return 0;
    }
    cout<<ans<<nl;
}