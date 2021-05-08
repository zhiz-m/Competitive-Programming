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

const int N=1010;
int n,m,k,dp[2][N],vis[N], s[N]; //for diskstra, courier shortest path
PII c[N], e[N]; //courier start/end,  edges; 
vector<PII> adj[N];
priority_queue<PII> pq;

void get(int u, int p){
    rep(i,1,n+1)dp[p][i]=1e9,vis[i]=0;
    dp[p][u]=0;
    pq.push(mp(-dp[p][u],u));
    while(!pq.empty()){
        int cur=pq.top().se;
        pq.pop();
        if (vis[cur])continue;
        vis[cur]=1;
        each(i,adj[cur]){
            if (dp[p][cur]+i.se<dp[p][i.fi]){
                dp[p][i.fi]=dp[p][cur]+i.se;
                pq.push(mp(-dp[p][i.fi],i.fi));
            }
        }
    }
}

int main(){
    upgrade();
    cin>>n>>m>>k;
    int ans=1e9;
    rep(i,0,m){
        int a,b,w;cin>>a>>b>>w;
        e[i]=mp(a,b);
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }
    rep(i,0,k){
        cin>>c[i].fi>>c[i].se;
    }
    rep(i,0,k){
        get(c[i].fi,0);
        s[i]=dp[0][c[i].se];
    }
    rep(i,0,m){
        get(e[i].fi,0);
        get(e[i].se,1);
        int t=0;
        rep(j,0,k){
            int cur=s[j];
            cur=min(cur,dp[0][c[j].fi]+dp[1][c[j].se]);
            cur=min(cur,dp[1][c[j].fi]+dp[0][c[j].se]);
            t+=cur;
        }
        ans=min(ans,t);
    }
    cout<<ans<<nl;
}