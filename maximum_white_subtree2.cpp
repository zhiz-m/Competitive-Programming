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

vector<VI> adj;
VI dp,colour,ans;
int n;

int precalc(int v, int pre){
    int cur=colour[v];
    for(int t : adj[v]){
        if (t==pre) continue;
        cur+=max(0,precalc(t,v));
    }
    //DEBUG(v),DEBUG(dp[v]);
    return dp[v]=cur;
}

void reroot(int v, int pre){
    ans[v]=dp[v];
    for(int t: adj[v]){
        if (t==pre)continue;
        dp[v]-=max(0,dp[t]);
        dp[t]+=max(0,dp[v]);
        reroot(t,v);
        dp[t]-=max(0,dp[v]);
        dp[v]+=max(0,dp[t]);
    }
}

int main(){
    upgrade();
    cin>>n;
    dp.assign(n+1,-1);
    colour.assign(n+1,-1);
    ans.assign(n+1,-1);
    adj.assign(n+1,VI());
    rep(i,1,n+1) {
        cin>>colour[i];
        colour[i]= (colour[i]==0) ? -1 : 1;
    }
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    //DEBUG(n);
    precalc(1,-1);
    //DEBUG(n);
    reroot(1,-1);
    //DEBUG(n);
    rep(i,1,n+1)cout<<ans[i]<<" \n"[i==n];
}