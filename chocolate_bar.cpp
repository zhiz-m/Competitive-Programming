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

int dp[33][33][55];

int solve(int n, int m, int k){
    if (k<0)return 1e9;
    if (dp[n][m][k]!=-1)return dp[n][m][k];
    //if (n*m<k)return dp[n][m][k]=1e9;
    if (n*m==k || k==0)return dp[n][m][k]=0;
    int ans=1e9,a,b;
    rep(i,1,n){
        a=i*m,b=(n-i)*m;
        rep(j,0,51){
            if (k-j>b)continue;
            if (j>a)break;
            ans=min(ans,solve(i,m,j)+solve(n-i,m,k-j)+m*m);
        }
    }
    rep(i,1,m){
        a=i*n,b=(m-i)*n;
        rep(j,0,51){
            if (k-j>b)continue;
            if (j>a)break;
            ans=min(ans,solve(n,i,j)+solve(n,m-i,k-j)+n*n);
        }
    }
    return dp[n][m][k]=dp[m][n][k]=ans;
}

int main(){
    upgrade();
    rep(i,0,33)rep(j,0,33){
        rep(z,1,55)dp[i][j][z]=-1;
        dp[i][j][0]=0;
    }
    int tc;cin>>tc;
    while(tc--){
        int n,m,k;
        cin>>n>>m>>k;
        cout<<solve(n,m,k)<<nl;
    }
}