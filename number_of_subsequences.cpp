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

const int N=200200;
ll n, v[N], dp[N][9];
vector<string> s(9);
map<string,int> m;

int main(){
    cin>>n;
    rep(i,0,n){
        char c;cin>>c;
        v[i]=c;
    }
    rep(i,0,3)rep(j,0,3){
        string str="";
        str+='a'+i;
        str+='a'+j;
        s[i*3+j]=str;
        m[str]=i*3+j;
    }
    memset(dp,-1,sizeof(dp));
    if (v[0]=='?' && v[1]=='?'){
        rep(i,0,9)dp[1][i]=0;
    }
    else if (v[1]=='?'){
        string str="";
        str+=v[0];
        rep(i,0,3){
            dp[1][m[str+(char)('a'+i)]]=0;
        }
    }
    else if (v[0]=='?'){
        rep(i,0,3){
            string str="";
            str+='a'+i;
            str+=v[1];
            dp[1][m[str]]=0;
        }
    }
    else{
        string str(1,v[0]);
        str+=v[1];
        dp[1][m[str]]=0;
    }
    rep(i,2,n){
        rep(j,0,9){
            if (dp[i-1][j]==-1)continue;
            rep(k,0,3){
                char cur='a'+k;
                if (v[i]==cur || v[i]=='?'){
                    string str(1,s[j][1]);
                    str+=cur;
                    int p=m[str];
                    if (dp[i][p]==-1)dp[i][p]=0;
                    dp[i][p]=(dp[i][p]+dp[i-1][j]+(j==1 && cur=='c'))%MOD;
                }
            }
        }
    }
    ll ans=0;
    rep(i,0,9){
        if (dp[n-1][i]!=-1)ans=(ans+dp[n-1][i])%MOD;
    }
    cout<<ans<<nl;
}