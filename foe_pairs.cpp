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

const int N=300300;
int n,m,v[N], fp[N],pos[N];
multiset<int> ms;

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,1,n+1)fp[i]=1e9;
    rep(i,1,n+1)cin>>v[i],pos[v[i]]=i;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        a=pos[a],b=pos[b];
        if (a>b)swap(a,b);
        fp[a] = min(fp[a],b);
    }
    rep(i,1,n+1) if (fp[i]!=1e9)ms.insert(fp[i]);
    ll ans=0;
    rep(i,1,n+1){
        if (ms.empty()) ans+=n-i+1;
        else {
            int mx = *ms.begin();
            //DEBUG(mx);
            ans += mx-i;
            if (fp[i]!=1e9)ms.erase(ms.find(fp[i]));
        }
    }
    cout<<ans<<nl;
}