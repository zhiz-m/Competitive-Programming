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

const int N=20200;
ll k,v[N],tot;

ll dfs(int cur, int l, int r){ // r not inclusive
    int mid = (l+r)/2;
    ll b=1e9;
    rep(i,l,r){
        ll t=v[i];
        if (t>=cur)b=min(b,t);
    }
    if (b==1e9)return 0;
    ll cost=(b-cur)*(b-cur);
    //DEBUG(l),DEBUG(r),DEBUG(cur),DEBUG(cost);
    //DEBUG(cost),DEBUG(b),DEBUG(cur);
    if (r-l>1)
        cost += dfs(b, l, mid) + dfs(b, mid, r);
    return cost;
}

int main(){
    upgrade();
    cin>>k;
    tot=1;
    rep(i,0,k)tot*=2;
    //DEBUG(tot);
    rep(i,0,tot)cin>>v[i];
    cout<<dfs(v[0], 0, tot)<<nl;
}