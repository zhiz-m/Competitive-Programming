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

vector<VI> u,v; //original, processed
VLL fact;
int main(){
    upgrade();
    int n,m;cin>>n>>m;
    //u.assign(n+1,VI());
    v.assign(m+1,VI());
    fact.assign(m+1,1);
    rep(i,2,m+1){
        fact[i]=fact[i-1]*i%MOD;
    }
    rep(i,1,n+1){
        int c;cin>>c;
        rep(j,0,c){
            int type;cin>>type;
            v[type].pb(i);
        }
    }
    sort(all(v));
    ll ans=1;
    ll cnt=1;
    rep(i,2,m+2){
        if (i==m+1 || v[i]!=v[i-1]){
            ans=ans*fact[cnt]%MOD;
            cnt=1;
        }
        else cnt++;
    }
    cout<<ans<<nl;
}