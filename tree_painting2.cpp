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

VLL s;//value for each subtree in downwards manner, size of subtree
vector<VI> adj;
int cnt=0,n;
ll ans=0;

void calc_s(int a, int b){
    int cur=cnt++;
    rep(i,0,SZ(adj[a])){
        if (adj[a][i]!=b) calc_s(adj[a][i],a);
    }
    s[a]=cnt-cur;
}

ll precalc(int a, int b){
   ll ret =s[a];
   rep(i,0,SZ(adj[a])){
       if (adj[a][i]==b)continue;
       ret+=precalc(adj[a][i],a);
   }
   return ret;
}

void dfs(int a, int b, ll sc){
    ans=max(ans,sc);
    rep(i,0,SZ(adj[a])){
        if (adj[a][i]==b) continue;
        dfs(adj[a][i],a,sc+n-2*s[adj[a][i]]);
    }
}

int main(){
    upgrade();
    cin>>n;
    s.assign(n+1,-1);
    adj.assign(n+1,VI());
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    calc_s(1,-1);
    ll t=precalc(1,-1);
    dfs(1,-1,t);
    cout<<ans<<nl;
}