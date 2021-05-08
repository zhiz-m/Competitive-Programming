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

const int N=300300;
int n,k,d,loc[N],r[N],vis[N],pol[N];
VI adj[N], ans;
queue<PII> q;
map<PII,int> m;

void bfs(){
    int u,o;
    tie(u,o)=q.front();
    q.pop();
    if (vis[u]) return;
    loc[u]=o;
    vis[u]=1;
    each(i,adj[u])q.push(mp(i,o));
}

void dfs2(int u, int prev){
    if (pol[u])q.push(mp(u,u));
    each(i,adj[u]){
        if (i==prev)continue;
        dfs2(i,u);
    }
}

void dfs(int u, int prev){
    if (prev!=-1 && loc[u]!=loc[prev]){
        ans.pb(m[mp(u,prev)]);
    }
    each(i,adj[u]){
        if (i==prev)continue;
        dfs(i,u);
    }
}

int main(){
    upgrade();
    cin>>n>>k>>d;
    memset(pol,0,sizeof(pol));
    int c=0;
    rep(i,0,k){
        cin>>r[i];
        if (pol[r[i]]){
            c++;
            continue;
        }
        loc[r[i]]=0,pol[r[i]]=1;
    }
    k-=c;
    rep(i,1,n){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        m[mp(a,b)]=m[mp(b,a)]=i;
    }
    memset(vis,0,sizeof(vis));
    dfs2(1,-1);
    while(!q.empty())bfs();
    //rep(i,1,n+1)DEBUG(loc[i]);
    dfs(1,-1);
    //DEBUG(SZ(ans));
    //assert(k-1==SZ(ans));
    cout<<k-1<<nl;
    rep(i,0,k-1)cout<<ans[i]<<" \n"[i==k-1];
}