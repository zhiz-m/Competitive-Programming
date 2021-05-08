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

const int N=10000100;
ll n,x,y,dp[N];

void calc(int i){
    if (i>n+1)return;
    ll dist = i-i/2;
    dp[i]=min(dp[i/2]+y, dp[i/2]+x*dist);
    calc(i*2);
}

int main(){
    upgrade();
    cin>>n>>x>>y;
    memset(dp,-1,sizeof(dp));
    dp[1]=x;
    calc(2);
    rep(i,3,n+1){
        if (i%2==0)continue;
        dp[i]=min(dp[i-1]+x,dp[i+1]+x);
        calc(i*2);
    }
    cout<<dp[n]<<nl;
}