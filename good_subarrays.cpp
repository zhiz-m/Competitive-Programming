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
int n,v[N],pre[N];
map<int,VI> m;

void solve(){
    cin>>n;
    m.clear();
    string s;cin>>s;
    rep(i,1,n+1){
        v[i]=s[i-1]-'0'-1;
        pre[i]=pre[i-1]+v[i];
    }
    rep(i,0,n+1){
        m[pre[i]].pb(i);
    }
    ll ans=0;
    rep(i,1,n+1){
        int t=pre[i];
        ans+=lower_bound(all(m[t]),i)-m[t].begin();
    }
    cout<<ans<<nl;
}

int main(){
    upgrade();
    v[0]=pre[0]=0;
    int tc;cin>>tc;
    while(tc--)solve();
}