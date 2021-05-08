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
ll n,m,a[N],b[N],dp[N][N],cnt[N][N];
vector<string> c(N),d(N);

void solve(){
    cin>>n;
    rep(i,1,n+1){
        string x;
        cin>>x>>c[i]>>a[i];
    }
    cin>>m;
    rep(i,1,m+1){
        string x;
        cin>>x>>d[i]>>b[i];
    }
    rep(i,0,m+1)dp[0][i]=cnt[0][i]=0;
    rep(i,0,n+1)dp[i][0]=cnt[i][0]=0;
    
    rep(i,1,n+1)rep(j,1,m+1){
        ll prev=dp[i][j-1],cur=dp[i-1][j-1]+(c[i]==d[j]?a[i]+b[j]:0);
        ll x = cnt[i-1][j-1] +(c[i]==d[j] && a[i]+b[j]!=0);
        //DEBUG(i),DEBUG(j),DEBUG(dp[i-1][j-1]);
        if (cur>prev || (prev == cur && x<cnt[i][j-1])){
            dp[i][j]=cur;
            cnt[i][j]=x;
        }
        else{
            dp[i][j]=prev;
            cnt[i][j]=cnt[i][j-1];
        }
        if (dp[i-1][j]>dp[i][j] || (dp[i-1][j]==dp[i][j] && cnt[i-1][j]<cnt[i][j])){
            dp[i][j]=dp[i-1][j];
            cnt[i][j]=cnt[i-1][j];
        }
    }
    ll ans=0,cur=0;
    rep(i,1,n+1){
        if (dp[i][m]>ans || (dp[i][m]==ans && cur>cnt[i][m])){
            ans=dp[i][m];
            cur=cnt[i][m];
        }
    }
    cout<<ans<<" "<<cur<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}