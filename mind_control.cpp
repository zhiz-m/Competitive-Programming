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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO
const int N=4000;
VI v(N);
int n,m,k,ans,t;

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        cin>>n>>m>>k;
        m=n-m;
        ans=-1;
        rep(i,0,n)cin>>v[i];
        k=min(n-m-1,k);
        rep(i,0,k+1){
            t=1e9+1;
            rep(j,i,i+n-m-k){
                t=min(t,max(v[j],v[j+m]));
            }
            ans=max(ans,t);
        }
        cout<<ans<<nl;
    }
}