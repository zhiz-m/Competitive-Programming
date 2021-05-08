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

const int N=100100;
int n,m;
VI p;
vector<VI> dp;
string s,t;

// credit cp-algorithms.com // returns z[], where z[i] is the largest integer j such that str[0...j] = str[i...i+j-1]
VI z_function(string s){
    VI z(SZ(s),0);
    int l=0, r=0;
    rep(i,1,SZ(s)){
        if (i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<SZ(s) && s[i+z[i]]==s[z[i]])
            z[i]++;
        if (i+z[i]-1>r)
            l=i, r=i+z[i]-1;
    }
    return z;
}

int main(){
    upgrade();
    cin>>s>>t;
    dp.assign(SZ(s)+20,VI(SZ(t)+20,-1));
    VI z=z_function(t);
    rep(i,1,SZ(t)){
        if (i+z[i]==SZ(t)) p.pb(z[i]);
    }
    n=SZ(s),m=SZ(t);
    s='-'+s;
    t='-'+t;
    dp[0][0]=0;
    rep(i,1,n+1){
        
        rep(j,1,m+1){
            if (dp[i-1][j-1]!=-1 && (s[i]==t[j] || s[i]=='?')){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
                //DEBUG(1);
            }
            if (j==m && dp[i][j] != -1){
                //DEBUG(2);
                dp[i][0]=max(dp[i][0],dp[i][j]+1);
                each(cur,p){
                    dp[i][cur]=max(dp[i][cur],dp[i][0]);
                }
            }
        }
        dp[i][0]=max(dp[i][0],dp[i-1][0]);
        rep(j,1,m)dp[i][0]=max(dp[i][0],dp[i][j]);
    }
    cout<<dp[n][0]<<nl;
}