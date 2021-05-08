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

ll v[N],n,k,z,pre[N];

void solve(){
    cin>>n>>k>>z;
    rep(i,1,n+1)cin>>v[i];
    if (k==1){
        cout<<v[1]+v[2]<<nl;
        return;
    }
    pre[0]=0;
    rep(i,1,n+1){
        pre[i]=pre[i-1]+v[i];
    }
    ll ans=-1;
    rep(i,2,n+1){
        ll tot=k-i+1;
        if (tot<0)break;
        ll num = tot/2;
        if (z<tot-num){
            ans=max(ans,z*(v[i-1]+v[i])+pre[k+1-2*z]);
        }
        else{
            ans=max(ans,pre[i]+(tot-num)*v[i-1]+num*v[i]);
        }
    }
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}