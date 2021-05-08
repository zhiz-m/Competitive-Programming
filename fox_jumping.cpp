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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N = 330;
VI v(N),cost(N),dp(600,1e9);
vector<VI> fac(N);
int n;

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n)cin>>v[i];
    rep(i,0,n)cin>>cost[i];
    rep(i,0,n){
        int f=2,cur=v[i];
        while(f*f<=cur){
            if (cur%f==0){
                while(cur%f==0)cur/=f;
                fac[i].pb(f);
            }
            f++;
        }
        if (cur!=1)fac[i].pb(cur);
    }
    int ans=1e9;
    rep(i,0,n){
        int tot=(1<<SZ(fac[i]))-1;
        rep(j,0,tot)dp[j]=1e9;
        dp[tot]=cost[i];
        rep(j,0,n){
            if (i==j)continue;
            int b=0,p=0;
            rep(k,0,SZ(fac[j])){
                while(p<SZ(fac[i])&&fac[i][p]<fac[j][k])p++;
                if (p==SZ(fac[i]))break;
                if (fac[i][p]==fac[j][k])b|=(1<<p);
            }
            rep(k,0,tot+1){
                if (dp[k]==1e9)continue;
                dp[k&b]=min(dp[k&b],dp[k]+cost[j]);
            }
        }
        ans=min(ans,dp[0]);
    }
    if (ans==1e9)cout<<-1<<nl;
    else cout<<ans<<nl;
}