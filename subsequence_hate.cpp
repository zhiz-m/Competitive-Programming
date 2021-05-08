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

string str;
int n;
VI pre(1010),suf(1010);

void solve(){
    cin>>str;
    str='a'+str;
    n=SZ(str);
    int ans=1e9;
    pre[0]=suf[n+1]=0;
    rep(i,1,n+1){
        pre[i]=pre[i-1]+(str[i]=='1');
    }
    per(i,1,n+1){
        suf[i]=suf[i+1]+(str[i]=='0');
    }
    rep(i,1,n+1){
        ans=min(ans,suf[i+1]+pre[i]);
    }
    pre[0]=suf[n+1]=0;
    rep(i,1,n+1){
        pre[i]=pre[i-1]+(str[i]=='0');
    }
    per(i,1,n+1){
        suf[i]=suf[i+1]+(str[i]=='1');
    }
    rep(i,1,n+1){
        ans=min(ans,suf[i+1]+pre[i]);
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