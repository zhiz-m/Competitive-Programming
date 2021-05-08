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
int n;
pair<ll,ll> dp[N][3];
string s;

pair<ll,ll> recur(int u, int f){
    if (u==n) return mp(-1,1);
    if (dp[u][f]!=mp((ll)-1,(ll)-1)) return dp[u][f];
    if (f==2){
        if (s[u]!='C') return dp[u][f]=recur(u+1,f);
        PII prev_c = recur(u+1,f);
        PII prev_tot = recur(u+1,0);
        
        if (prev_tot.fi==prev_c.fi){
            dp[u][f] = mp(prev_tot.fi, (prev_tot.se+prev_c.se)%MOD);
        }
        else dp[u][f] = prev_tot;
        if (dp[u][f].fi==-1)dp[u][f]=mp(0,1);
        if (prev_c.fi==0 && dp[u][f].fi==0)dp[u][f].se=(dp[u][f].se+prev_c.se)%MOD;
    }
    else if (f==1){
        if (s[u]!='M') return dp[u][f]=recur(u+1,f);
        PII prev_m = recur(u+1,f);
        PII prev_tot = recur(u+1,2);
        if (prev_tot.fi==prev_m.fi){
            dp[u][f] = mp(prev_tot.fi, (prev_tot.se+prev_m.se)%MOD);
        }
        else dp[u][f] = prev_tot;
    }
    else if (f==0){
        if (s[u]!='I') return dp[u][f]=recur(u+1,f);
        PII prev_i = recur(u+1,f);
        PII prev_tot = recur(u+1,1);
        if (prev_tot.fi!=-1)prev_tot.fi+=1;
        if (prev_tot.fi==prev_i.fi){
            dp[u][f] = mp(prev_tot.fi, (prev_tot.se+prev_i.se)%MOD);
        }
        else dp[u][f] = prev_tot;
    }
    return dp[u][f];
}

int main(){
    upgrade();
    cin>>n>>s;
    rep(i,0,N)dp[i][0]=dp[i][1]=dp[i][2]=mp(-1,-1);
    cout<<max(recur(0,0).fi,0ll)<<nl<<recur(0,0).se<<nl;
}  