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

const int N=30;
int n, v[N], dp[N][N][3];// 0, a ,b 

bool recur(int l, int r, int f){ //[i,j)
    if (dp[l][r][f]!=-1) return dp[l][r][f];
    if (r-l==1){
        if (f==1 && v[l]=='a') return 1;
        if (f==0 && v[l]=='b') return 1;
        return 0;
    }
    if (l==r)return 1;
    int ret=0;
    if ((f==1 && v[l]=='a') || (f==0 && v[l]=='b')) ret=recur(l+1,r,2);
    rep(i,l+1,r){
        if (v[i] == v[l]){ 
            ret |= recur(l+1,i,v[i]=='a') && recur(i+1,r,f);
            //ret |= recur(l+1,i,v[i]=='a') && recur(i+1,r,2);
        }
    }
    return (dp[l][r][f] = ret);
}

void solve(){
    string s;cin>>s;
    n=SZ(s);
    memset(dp,-1,sizeof(dp));
    rep(i,0,n)v[i]=s[i];
    cout<<recur(0,n,2)<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}