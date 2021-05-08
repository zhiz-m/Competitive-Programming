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

const int N=55;
ll n,k,m, dp[N][N][N]; // index, number of bars, length of last bar

ll recur(int i, int b, int l){
    if (i==0 && l==0 && b==0)return 1;
    if (i==1){
        if (b==1 && l==1) return 1;
        return 0;
    }
    if (b==0 || i<=0 || l==0)return 0;
    if (dp[i][b][l]!=-1)return dp[i][b][l];
    ll ans=0;
    ans+=recur(i-1,b,l-1);
    if (l==1)
    rep(t,1,m+1){
        ans+=recur(i-1,b-1,t);
    }

    return dp[i][b][l]=ans;
}

int main(){
    upgrade();
    while(cin>>n>>k>>m){
        memset(dp,-1,sizeof(dp));
        ll ans=0;
        rep(i,1,m+1) ans+=recur(n,k,i);
        cout<<ans<<nl;
    }
}