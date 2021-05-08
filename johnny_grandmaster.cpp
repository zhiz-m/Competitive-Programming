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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N=1000100;
VI v(N);
ll n,p,ans,suc;

void solve(){
    cin>>n>>p;
    ans=0,suc=1;
    rep(i,0,n)cin>>v[i];
    sort(v.begin(),v.begin()+n);
    v[n]=v[n-1];
    per(i,0,n){
        ll res=p;
        ll t=v[i+1]-v[i];
        if (ans>0)
        while(t){
            if (res>=MOD)suc=0;
            res%=MOD;
            if (t&1)ans*=res;
            if (ans>=MOD)suc=0;
            ans%=MOD;
            t>>=1;
            res*=res;
        }
        if(suc){
            ans-=(ans==0?-1:1);
        }
        else{
            ans=(ans-1+MOD)%MOD;
        }
    }
    ans=ans*powmod(p,v[0])%MOD;
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
}