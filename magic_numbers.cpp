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

const int N=2020;
ll n,m,d,v[N],dp[N][N][2];

ll calc(){
    rep(p,0,n){
        rep(mod,0,m){
            int temp;
            if (p%2==1){
                temp=(mod*10+d)%m;
                dp[p+1][temp][0] += dp[p][mod][0];
                if (d == v[p+1])
                    dp[p+1][temp][1] += dp[p][mod][1];
                else if (d < v[p+1])
                    dp[p+1][temp][0] += dp[p][mod][1];
                dp[p+1][temp][1] %= MOD;
                dp[p+1][temp][0] %= MOD;
                continue;
            }
            rep(i,0,10){
                if (i==d || (i==0 && p==0))continue;
                temp=(mod*10+i)%m;
                dp[p+1][temp][0] += dp[p][mod][0];
                dp[p+1][temp][1] %= MOD;
                dp[p+1][temp][0] %= MOD;
            }
            rep(i,0,10){
                if (i==d || (i==0 && p==0))continue;
                temp = (mod*10+i)%m;
                if (i>v[p+1])break;
                else if (i==v[p+1]) dp[p+1][temp][1] += dp[p][mod][1];
                else dp[p+1][temp][0] += dp[p][mod][1];
                dp[p+1][temp][1] %= MOD;
                dp[p+1][temp][0] %= MOD;
            }
        }
    }
    return dp[n][0][0]+dp[n][0][1];
}

ll check(){
    return dp[n][0][1]>0;
}

int main(){
    upgrade();
    cin>>m>>d;
    string str;cin>>str;
    n=SZ(str);
    rep(i,1,n+1)v[i]=str[i-1]-'0';
    memset(dp,0,sizeof(dp));
    //rep(i,0,m+1)rep(j,0,2)dp[0][i][j]=0;
    dp[0][0][1] = 1;
    ll ans1 = calc()-check();
    cin>>str;
    rep(i,1,n+1)v[i]=str[i-1]-'0';
    memset(dp,0,sizeof(dp));
    //rep(i,0,m+1)rep(j,0,2)dp[0][i][j]=0;
    dp[0][0][1] = 1;
    ll ans2 = calc();
    cout<<(ans2-ans1+MOD)%MOD<<nl;
}