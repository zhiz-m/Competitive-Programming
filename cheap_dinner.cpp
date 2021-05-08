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

const int N=150200;

int n[4], v[4][N], dp[4][N];
VI excl[3][N];

int calc(VI a){
    int l=0, r=SZ(a);
    if (r>0 && a[0]!=0)return 0;
    while(r-l>1){
        int mid=(r+l)/2;
        if (a[mid]>mid)r=mid;
        else l=mid;
    }
    return r;
}

int main(){
    upgrade();
    rep(i,0,4)cin>>n[i];
    rep(i,0,4)rep(j,0,n[i])cin>>v[i][j];
    rep(i,0,3){
        int m;cin>>m;
        rep(j,0,m){
            int a,b;cin>>a>>b;
            excl[i][a-1].pb(b-1);
        }
    }
    rep(i,0,n[3])dp[3][i]=v[3][i];
    per(i,0,3){
        vector<PII> t;
        VI cur;
        rep(j,0,n[i+1])t.pb(mp(dp[i+1][j],j));
        sort(all(t));
        cur.resize(n[i+1]);
        rep(j,0,n[i+1])cur[t[j].se]=j;
        rep(j,0,n[i]){
            VI t2;
            each(k,excl[i][j]){
                t2.pb(cur[k]);
                //DEBUG(i),DEBUG(j),DEBUG(cur[k]);
            }
            sort(all(t2));
            int best=calc(t2);
            //DEBUG(i),DEBUG(j),DEBUG(best);
            if (best==n[i+1]){
                dp[i][j]=1e9;
                //cout<<dp[i][j]<<nl;
                //DEBUG(i),DEBUG(j),DEBUG(-2);
                continue;
            }
            
            dp[i][j]=t[best].fi==1e9?1e9:t[best].fi+v[i][j];
            //DEBUG(i),DEBUG(j),DEBUG(dp[i][j]);
        }
        //cout<<nl;
    }
    int ans=1e9;
    rep(i,0,n[0])ans=min(ans,dp[0][i]);
    cout<<(ans==1e9?-1:ans)<<nl;
}