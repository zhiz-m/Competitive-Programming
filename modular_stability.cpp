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
const ll MOD=998244353 ;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N = 500500;

vector<VI> fact(N);
vector<pair<ll,ll>> p(N); //first is kth power, second is k-1th power;
VI sieve(N);

pair<ll,ll> power(int u){
    pair<ll,ll>ans=mp(1ll,1ll);
    if (p[u]!=mp(0ll,0ll))return p[u];
    each(i,fact[u]){
        ans.fi = ans.fi * p[i].fi % MOD;
        ans.se = ans.se * p[i].se % MOD;
    }
    return ans;
}

int main(){
    upgrade();
    int n,k;cin>>n>>k;
    rep(i,1,k+1)sieve[i]=i;
    rep(i,1,k+1){
        if (sieve[i]==1)continue;
        DEBUG(i),DEBUG(sieve[i]);
        for(int j=2*i;j<=k;j+=i){
            while(sieve[j]%i==0)sieve[j]/=i,fact[j].pb(i);
        }
    }
    DEBUG(1);
    rep(i,1,k+1){
        if (sieve[i]!=1){
            ll ans = 1;
            rep(j,0,n-1)ans = ans * ans % MOD;
            p[i] = mp(ans*ans%MOD,ans);
        }
    }
    DEBUG(1);
    ll ans = 0;
    rep(i,1,k+1){
        ll cnt = k/i;
        pair<ll,ll> pows = power(cnt);
        ans=(ans+pows.fi-pows.se)%MOD;
    }
    cout<<ans<<nl;
}