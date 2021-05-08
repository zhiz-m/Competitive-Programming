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

ll n,a[3],b[3];

int main(){
    upgrade();
    cin>>n;
    rep(i,0,3)cin>>a[i];
    rep(i,0,3)cin>>b[i];
    ll mx = min(a[0],b[1]) +min(a[1],b[2]) + min(a[2],b[0]);
    ll mn, best=1e18;
    rep(i,0,3)rep(j,0,3)rep(k,0,3){
        if (i==j || j==k || i==k) continue;
        ll y[]={i,j,k},a2[]={a[0],a[1],a[2]},b2[]={b[0],b[1],b[2]};
        mn=0;
        rep(x,0,3){
            rep(m,0,3){
                if (m==(y[x]+1)%3)continue;
                //DEBUG(a2[y[x]]);
                ll t = min(a2[y[x]],b2[m]);
                a2[y[x]] -= t;
                b2[m] -= t;
            }
            mn+=a2[y[x]];
        }
        best=min(mn,best);
    }
    cout<<best<<" "<<mx<<nl;
}