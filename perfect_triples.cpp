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

int main(){
    upgrade();
    vector<VLL> m(4);
    m[0].pb(0);
    m[0].pb(0);
    m[0].pb(0);
    m[1].pb(1);
    m[1].pb(2);
    m[1].pb(3);
    m[2].pb(2);
    m[2].pb(3);
    m[2].pb(1);
    m[3].pb(3);
    m[3].pb(1);
    m[3].pb(2);
    int tc;cin>>tc;
    while(tc--){
        ll n;cin>>n;
        ll b=-1;
        ll t=1;
        while(t<=n){
            b++;
            t<<=2;
        }
        t>>=2;
        //DEBUG(b);
        VI v;
        ll st=(n-t)/3;
        rep(i,0,b){
            v.pb(st%4);
            st/=4;
        }
        v.pb(1);
        ll ans=0;
        ll p=0;
        int f=(n-1)%3;
        //DEBUG(f);
        rep(i,0,SZ(v)){
            //DEBUG(v[i]),DEBUG(f);
            ans|=(m[v[i]][f]<<p);
            p+=2;
        }
        cout<<ans<<nl;
    }
}