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

const int N=550, M=70000;
ll n,dp[N][M];

int main(){
    upgrade();
    scanf("%lld",&n);
    int tot=0;
    rep(i,1,n+1)tot+=i;
    if (tot%2==1){
        printf("%d\n",0);
        return 0;
    }
    rep(i,0,N)rep(j,0,M)dp[i][j]=0;
    dp[0][0]=1;
    rep(i,1,n+1)rep(j,0,M){
        if (j-i>=0)
            dp[i][j] = (dp[i-1][j-i] + dp[i-1][j]) % MOD;
        else
            dp[i][j] = dp[i-1][j];
    }
    //printf("%d\n", tot/2);
    printf("%lld\n",(dp[n][tot/2]*powmod(2,MOD-2))%MOD);
}