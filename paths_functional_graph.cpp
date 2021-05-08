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

const int N=100100, M=35;
ll n,k,s[N][M],m[N][M],adj[N],w[N],to[N][M];

pair<ll,ll> get(int u){ // s,m
    int i=0;
    pair<ll,ll> ret=mp(0,1e9);
    while(k>=(1ll<<i)){
        if (k&(1ll<<i)){
            ret.fi +=s[u][i];
            ret.se = min(ret.se, m[u][i]);
            u=to[u][i];
        }
        i++;
    }
    return ret;
}

int main(){
    upgrade();
    cin>>n>>k;
    rep(i,0,n)cin>>adj[i];
    rep(i,0,n)cin>>w[i];
    rep(j,0,M){
        rep(i,0,n){
            if(j==0){
                to[i][j]=adj[i];
                s[i][j]=m[i][j]=w[i];
            }
            else{
                int t = to[i][j-1];
                to[i][j]=to[t][j-1];
                s[i][j]=s[i][j-1]+s[t][j-1];
                m[i][j]=min(m[i][j-1],m[t][j-1]);
            }
        }
    }
    rep(i,0,n){
        pair<ll,ll> ans=get(i);
        cout<<ans.fi<<" "<<ans.se<<nl;
    }
}