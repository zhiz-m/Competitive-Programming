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
const ll MOD=998244353;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N = 500500;
int n,k;
VLL fac(N),inv(N);

int main(){
    upgrade();
    cin>>n>>k;
    fac[0]=1;
    rep(i,1,n+1)fac[i] = fac[i-1]*i%MOD;
    inv[n] = powmod(fac[n],MOD-2);
    per(i,1,n+1) inv[i-1] = inv[i] * i %MOD;
    ll ans=0;
    rep(i,1,n+1){
        int c=n/i-1,r=k-1;
        if (c<r)break;
        //cout<<i<<' '<<c<<' '<<r<<nl;
        ll t = ((fac[c] * inv[r])%MOD)*inv[c-r]%MOD;
        ans=(ans+t)%MOD;
    }
    cout<<ans<<nl;
}
