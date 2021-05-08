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

const int N=3030;
int n,ans[N];
PII v[N];

void solve(){
    cin>>n;
    rep(i,1,2*n+1)cin>>v[i].fi,v[i].se=i;
    sort(v+1,v+2*n+1);
    VI a[2],b[2];
    rep(i,1,n+1){
        int t=v[i].se;
        if(t<=n)a[0].pb(t);
        else b[0].pb(t-n);
    }
    rep(i,n+1,2*n+1){
        int t=v[i].se;
        if(t<=n)a[1].pb(t);
        else b[1].pb(t-n);
    }
    rep(i,0,SZ(a[0])){
        ans[a[0][i]]=b[1][i];
    }
    rep(i,0,SZ(b[0])){
        ans[a[1][i]]=b[0][i];
    }
    rep(i,1,n+1)cout<<ans[i]<<" \n"[i==n];
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}