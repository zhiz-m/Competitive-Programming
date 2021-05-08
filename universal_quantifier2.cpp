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

const int N = 200100;
int n,m,suc=1;
VI up[N],down[N],vis(N,0),done(N,0),dp1(N,-1),dp2(N,-1);
string ans;

int dfs1(int u){
    if (done[u]||!suc) {suc=0;return -1;}
    if (dp1[u]!=-1)return dp1[u];
    done[u]=1;
    int ret=u;
    each(i,up[u]) ret=min(ret,dfs1(i));
    done[u]=0;
    return dp1[u]=ret;
}

int dfs2(int u){
    if (dp2[u]!=-1)return dp2[u];
    int ret=u;
    each(i,down[u]) ret=min(ret,dfs2(i));
    return dp2[u]=ret;
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,0,n)ans+='E';
    //DEBUG(ans1);
    rep(i,0,m){
        int a,b;cin>>a>>b;
        up[a].pb(b);
        down[b].pb(a);
    }
    rep(i,1,n+1) dfs1(i);
    if (!suc){
        cout<<-1<<nl;
        return 0;
    }
    rep(i,1,n+1) dfs2(i);
    int cnt=0;
    rep(i,1,n+1)if((dp1[i]==i) && (dp2[i]==i))ans[i-1]='A',cnt++;
    cout<<cnt<<nl;
    cout<<ans<<nl;
}