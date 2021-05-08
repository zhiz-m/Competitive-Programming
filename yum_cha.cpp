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

const int N=110, M=1010;
int n, tot, t,k, a[N],b[N], dp[N][M];

int recur(int i, int cost){
    if (cost>tot) return -1e9;
    if (i==0) return 0;
    if (dp[i][cost]!=-1)return dp[i][cost];
    return dp[i][cost] = max(recur(i-1,cost),max(b[i]+recur(i-1,cost-a[i]),2*b[i]+recur(i-1,cost-2*a[i])));
}

void solve(){
    cin>>n>>tot>>t>>k;
    memset(dp, -1, sizeof(dp));
    tot*=(n+1);
    rep(i,1,k+1){
        cin>>a[i]; //price
        b[i]=0;
        rep(j,0,10){
            int x;cin>>x;
            b[i]+=x;
        }
    }
    int ans=recur(k,0)+t;
    cout<<(ans%10==0?ans*11/10:ans/10*11+1)<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}