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

const int N=1010;
int n,m,dp[N][N],best[N][N],v[N];

int recur(int l, int r){ //r is r+1, l starts at 1
    //DEBUG(1);
    if (dp[l][r]!=-1)return dp[l][r];
    if (r-l<=1){
        best[l][r]=r;
        return dp[l][r]=0;
    }
    int ans=1e9;
    recur(l,r-1);
    recur(l+1,r);
    //DEBUG(l),DEBUG(r),DEBUG(best[l][r-1]),DEBUG(best[l+1][r]);
    int t;
    rep(i,best[l][r-1],min(r,best[l+1][r]+1)){
        t=recur(l,i)+recur(i,r);
        if (t<ans){
            ans=t;
            best[l][r]=i;
        }
    }
    ans+=v[r]-v[l];
    //DEBUG(ans);
    return dp[l][r]=ans;
}

int main(){
    upgrade();
    v[0]=0;
    while(true){
        cin>>n>>m;
        if (cin.eof())return 0;
        rep(i,0,m+2)rep(j,0,m+2)dp[i][j]=best[i][j]=-1;
        rep(i,1,m+1){
            cin>>v[i];
        }
        v[m+1]=n;
        rep(inc,0,m+2){
            rep(l,0,m+1){
                int r=l+inc;
                if (r>m+1)break;
                if (r-l<=1){
                    best[l][r]=r;
                    dp[l][r]=0;
                    continue;
                }
                int ans=1e9;
                int t;
                rep(i,best[l][r-1],min(r,best[l+1][r]+1)){
                    t=recur(l,i)+recur(i,r);
                    if (t<ans){
                        ans=t;
                        best[l][r]=i;
                    }
                }
                ans+=v[r]-v[l];
                //DEBUG(ans);
                dp[l][r]=ans;
            }
        }
        //cout<<recur(0,m+1)<<nl;
        cout<<dp[0][m+1]<<nl;
    }
}