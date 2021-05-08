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

const int N=5050;
int n,m,dp[N][N];
string a,b;

int main(){
    upgrade();
    cin>>n>>m;
    cin>>a>>b;
    rep(i,0,m)dp[n][i]=0;
    rep(i,0,n)dp[i][m]=0;
    per(i,0,n)per(j,0,m){
        int cur=0;
        cur=max(cur,dp[i+1][j]-1);
        cur=max(cur,dp[i][j+1]-1);
        cur=max(cur,dp[i+1][j+1]-2+4*(a[i]==b[j]));
        dp[i][j]=cur;
    }
    int ans=0;
    rep(i,0,n)rep(j,0,m)ans=max(ans,dp[i][j]);
    cout<<ans<<nl;
}