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

const int N=1000100;

int n,m,dp[N][8];
vector<VI> v,v2;

int bits(int a){
    int cnt=0;
    while(a){
        cnt+=a&1;
        a>>=1;
    }
    return cnt;
}

int valid(int a, int b){
    if ((bits(a&3)+bits(b&3))%2==0)return 0;
    if (m==3 && (bits(a&6)+bits(b&6))%2==0) return 0;
    return 1;
}

int cost(int a, int i){
    int cnt=0;
    rep(j,0,m){
        //cnt+=(a&1)!=v[i][j];
        cnt+=(a&1)!=v[i][j];
        //a>>=1;
        a>>=1;
    }
    //DEBUG(a),DEBUG(b),DEBUG(i),DEBUG(cnt);
    return cnt;
}

int main(){
    upgrade();
    cin>>n>>m;
    v.assign(n,VI(m));
    rep(i,0,n)rep(j,0,m){
        char c;cin>>c;
        v[i][j]=c-'0';
    }
    if (n==1 || m==1){
        cout<<0<<nl;
        return 0;
    }
    if (n>=4 && m>=4){
        cout<<-1<<nl;
        return 0;
    }
    if (m>3){
        swap(n,m);
        v2=v;
        v.assign(n,VI(m));
        rep(i,0,n)rep(j,0,m)v[i][j]=v2[j][i];
    }
    rep(i,0,n)rep(j,0,8)dp[i][j]=-1;
    rep(i,0,1<<m)dp[0][i]=cost(i,0);
    rep(i,1,n){
        rep(j,0,1<<(m))rep(k,0,1<<(m)){
            if (dp[i-1][j]==-1)continue;
            if (!valid(j,k))continue;
            int c=cost(k,i);
            dp[i][k]=(dp[i][k]==-1)?dp[i-1][j]+c:min(dp[i][k],dp[i-1][j]+c);
            //DEBUG(i),DEBUG(dp[i][k]);
        }
    }
    int ans=1e9;
    rep(i,0,1<<(m)){
        //DEBUG(dp[n-2][i]);
        if (dp[n-1][i]==-1)continue;
        ans=min(ans,dp[n-1][i]);
    }
    cout<<ans<<nl;
}