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
int n,col[N];
ll dp[N][2];
VI adj[N];

void dfs(int u, int prev){
    dp[u][0]=1;
    dp[u][1]=0;
    //dp[u][col[u]]=1;
    //dp[u][col[u]^1]=0;
    each(i,adj[u]){
        if (i==prev)continue;
        dfs(i,u);
        //if (dp[i][1]==0)continue;
        dp[i][0]+=dp[i][1];
        dp[u][1]=dp[u][1]*(dp[i][0])%MOD;
        //DEBUG(dp[u][1]);
        dp[u][1]=(dp[u][1]+dp[i][1]*dp[u][0])%MOD;
        //DEBUG(dp[u][1]);
        dp[u][0]=dp[u][0]*(dp[i][0])%MOD;
    }
    if (col[u]==1)dp[u][1]=dp[u][0],dp[u][0]=0;
}

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n){
        int a;cin>>a;
        adj[i].pb(a);
        adj[a].pb(i);
    }
    rep(i,0,n){
        cin>>col[i];
    }
    dfs(0,-1);
    //DEBUG(dp[4][1]),DEBUG(dp[8][1]),DEBUG(dp[8][0]),DEBUG(dp[9][1]),DEBUG(dp[9][0]);
    //rep(i,0,n)rep(j,0,2)cout<<i<<" "<<j<<": "<<dp[i][j]<<nl;
    cout<<dp[0][1]<<nl;
}