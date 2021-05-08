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
const ll MOD=998244353;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N=200200;
int n, k,v[N], need[N],pos[N],b[N];

void solve(){
    cin>>n>>k;
    rep(i,1,n+1)need[i]=1;
    need[0]=need[n+1]=0;
    rep(i,1,n+1)cin>>v[i],pos[v[i]]=i;
    rep(i,1,k+1){
        int a;cin>>a;
        b[i]=pos[a];
        need[pos[a]]=0;
    }
    //rep(i,1,n+1)DEBUG(i),DEBUG(need[i]);
    ll ans=1;
    rep(i,1,k+1){
        //DEBUG(b[i]),DEBUG(need[b[i]-1]+need[b[i]+1]);
        ans = ans * (need[b[i]-1]+need[b[i]+1])%MOD;
        need[b[i]]=1;
    }
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}