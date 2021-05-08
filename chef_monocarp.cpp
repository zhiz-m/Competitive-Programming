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

const int N=220;
int n,v[N],dp[N][2*N];

int calc(int u){
    //DEBUG(u),DEBUG(u*(u+1)/2);
    return u*(u+1)/2;
}

int cost(int u, int p){
    if (p+v[u]<=u){
        return v[u]*(u-p-v[u]+1) + calc(v[u]-1);
    }
    if (u<p){
        return v[u]*(p-u) + calc(v[u]-1);
    }
    int l=u-p, r=p+v[u]-u-1;
    return calc(l)+calc(r);
}

int recur(int u, int p){
    if (p>2*n+1)return 1e9;
    if (dp[u][p]!=-1)return dp[u][p];
    //DEBUG(p),DEBUG(v[u]);
    int c=cost(u,p), ans=1e9;
    int nex = u+1;
    while(nex<n+1&&v[nex]==0)nex++;
    //DEBUG(nex);
    //if (nex==n+1) return dp[u][p]=c;
    if (nex!=n+1)ans=min(c+recur(nex,p+v[u]),recur(u,p+1));
    else ans=min(c,recur(u,p+1));
    //rep(i,p+v[u],2*n+1)ans=min(ans,c+recur(nex,i));
    return dp[u][p]=ans;
}

void solve(){
    cin>>n;
    rep(i,0,n+10)v[i]=0;
    rep(i,0,n+10)rep(j,0,2*n+10)dp[i][j]=-1;
    rep(i,0,n){
        int a;cin>>a;
        v[a]++;
    }
    int ans=1e9;
    rep(i,1,n+1){
        if (v[i]!=0){
            rep(j,1,2*n+1)ans=min(ans,recur(i,j));
            break;
        }
    }
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}