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

const int N=220;
int n,m,v1[N],v2[N],dp[N][513];

int main(){
    upgrade();
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    rep(i,1,n+1)cin>>v1[i];
    rep(i,1,m+1)cin>>v2[i];
    rep(i,1,n+1){
        int t[513]={0};
        rep(k,0,513){
            if (dp[i-1][k]==1)
                rep(j,1,m+1){
                    t[k|(v1[i]&v2[j])]=1;
                } 
        }
        rep(j,0,513)dp[i][j]|=t[j];
    }
    rep(i,0,513){
        if (dp[n][i]==1){
            cout<<i<<nl;
            return 0;
        }
    }
}