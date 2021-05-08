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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO
const int N=1010;
int n,st,cnt;
vector<VI> adj(N);

void dfs(int u, int prev){
    each(i,adj[u]){
        if (i==prev)continue;
        cnt++;
        dfs(i,u);
    }
}

void solve(){
    cin>>n>>st;
    cnt=0;
    rep(i,1,n+1){
        adj[i].clear();
    }
    rep(i,1,n){
        int a,b;cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    if (SZ(adj[st])<2){
        cout<<"Ayush"<<nl;return;
    }
    dfs(st,-1);
    if (cnt%2==0)cout<<"Ashish"<<nl;
    else cout<<"Ayush"<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}