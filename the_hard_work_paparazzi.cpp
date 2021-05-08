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
int r,n,t[N],x[N],y[N],dp[N][2]; // val, suffix val

int main(){
    upgrade();
    cin>>r>>n;
    memset(dp,-1,sizeof(dp));
    t[0]=0;
    x[0]=y[0]=1;
    dp[0][0]=dp[0][1]=0;
    rep(i,1,n+1){
        cin>>t[i]>>x[i]>>y[i];
        int prev = max(0,i-1000);
        dp[i][0]=i-1000>=0?dp[prev][1]+1:-1;
        rep(j,prev,i){
            if (dp[j][0]==-1 ||t[i]-t[j]<abs(x[i]-x[j])+abs(y[i]-y[j]))continue;
            dp[i][0]=max(dp[j][0]+1,dp[i][0]);
        }
        dp[i][1]=max(dp[i-1][1],dp[i][0]);
    }
    cout<<dp[n][1]<<nl;
}