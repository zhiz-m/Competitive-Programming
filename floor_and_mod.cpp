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

const int N=32000;

ll calc(int x, int y, int cur){
    ll l=cur, r=y+1;
    //if ((l+1)*cur>x)return 0;
    while(r-l>1){
        ll mid=(r+l)/2;
        if ((mid+1)*cur <=x){
            l=mid;
        }
        else r=mid;
    }
    return l-cur;
}

void solve(){
    ll x,y;cin>>x>>y;
    ll ans=0;
    rep(i,1,N){
        ans+=calc(x,y,i);
    }
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
}