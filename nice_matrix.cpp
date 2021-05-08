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

const int N=110;
int v[N][N], n, m;

void solve(){
    cin>>n>>m;
    ll cost=0;
    rep(i,0,n)rep(j,0,m)cin>>v[i][j];
    rep(i,0,n/2)rep(j,0,m/2){
        ll a=v[i][j], b=v[i][m-j-1], c=v[n-i-1][j], d=v[n-i-1][m-j-1];
        vector<ll> cur={a,b,c,d};
        sort(all(cur));
        ll avg = cur[1];
        cost+=abs(a-avg)+abs(b-avg)+abs(c-avg)+abs(d-avg);
    }
    if (n%2!=0)
        rep(j,0,m/2){
            cost+=abs(v[n/2][j]-v[n/2][m-j-1]);
        }
    if (m%2!=0)
        rep(i,0,n/2){
            cost+=abs(v[i][m/2]-v[n-i-1][m/2]);
        }
    cout<<cost<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}