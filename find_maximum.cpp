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
    VI v,pre,suf;
    VI b;
    int n;cin>>n;
    v.resize(n+1);
    b.assign(n+1,0);
    suf.assign(n+1,0);
    pre.assign(n+1,0);
    rep(i,1,n+1){
        cin>>v[i];
        pre[i]=v[i]+pre[i-1];
    }
    rep(i,1,n+1){
        char c;
        cin>>c;
        b[i]=c-'0';
        //DEBUG(b[i]*v[i]);
    }
    suf[n]=v[n]*b[n];
    suf.pb(0);
    per(i,0,n){
        suf[i]=suf[i+1]+b[i]*v[i];
    }
    ll ans=suf[0];
    //DEBUG(ans);
    //bool f=1;
    per(i,1,n+1){
        if (b[i]==0){continue;}
        ll t=pre[i-1]+suf[i+1];
        //DEBUG(i),DEBUG(t);
        ans=max(ans,t);
    }
    cout<<ans<<nl;
}