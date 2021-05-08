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

VLL v,am,pre; //occurences,pre

int main(){
    upgrade();
    ll n,s;cin>>n>>s;
    v.assign(n,0);
    rep(i,0,n)cin>>v[i];
    s*=8; // s in bytes
    s/=n;
    if (s>=19) {cout<<0<<nl;return 0;}
    ll mx = 1ll<<s; // number of different elements
    sort(all(v));
    v.pb(-1);
    int cnt=1;
    am.pb(-1);
    rep(i,1,n+1){
        if (v[i]!=v[i-1]){
            am.pb(cnt);
            cnt=1;
        }
        else cnt++;
    }
    //rep(i,0,SZ(am))DEBUG(am[i]);
    if (SZ(am)<=mx){
        cout<<0<<nl;return 0;
    }
    pre.assign(SZ(am),0);
    rep(i,1,SZ(am)){
        pre[i]=am[i]+pre[i-1];
    }
    //rep(i,0,SZ(pre))DEBUG(pre[i]);

    ll ans=n;
    //DEBUG(mx);
    rep(i,mx,SZ(pre)){
        ans=min(ans,n-(pre[i]-pre[i-mx]));
    }
    cout<<ans<<nl;
}