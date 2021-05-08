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

int dp[10][10][10]; //num 1, num 2, result
int ans[10][10];

int main(){
    upgrade();
    string str;cin>>str;
    rep(i,0,10)rep(j,0,10)rep(k,0,10)dp[i][j][k]=21;
    rep(i,0,10)rep(j,0,10)ans[i][j]=0;
    rep(a,0,10)rep(b,a,10){
        rep(i,0,10)rep(j,0,10){
            if (i==0 && j==0)continue;
            int t=(a*i+b*j)%10;
            //assert(t>=0 && t<10);
            //DEBUG(a),DEBUG(b),DEBUG(t);
            //DEBUG(i+j);
            assert(dp[a][b][t]>=0);
            dp[a][b][t]=dp[b][a][t]=min(dp[a][b][t],i+j);
        }
    }
    //rep(i,0,10)rep(j,0,10)rep(k,0,10)DEBUG(dp[i][j][k]);
    rep(i,1,SZ(str)){
        int num=str[i]-str[i-1]+10;
        num%=10;
        //DEBUG(num);
        rep(a,0,10){
            rep(b,0,10){
                //DEBUG(dp[a][b][num]);
                //DEBUG(ans[a][b]);
                if (ans[a][b]==-1) continue;
                if(dp[a][b][num]==21){
                    ans[a][b]=-1;continue;
                }
                ans[a][b]+=max(dp[a][b][num]-1,0);
            }
        }
    }
    rep(i,0,10){
        rep(j,0,10)
            cout<<ans[i][j]<<' ';
        cout<<nl;
    }
}