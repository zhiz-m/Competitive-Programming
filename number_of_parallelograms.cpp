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

const int N=2020;
ll n,x[N],y[N];
map<pair<ld,ll>,ll> line;

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n){
        cin>>x[i]>>y[i];
    }
    rep(i,0,n)rep(j,i+1,n){
        ld slope;
        ll dist;
        if (x[i]==x[j]) slope=1e18;
        else slope = (ld)(y[i]-y[j])/(ld)(x[i]-x[j]);
        if (slope==-0) slope = 0;
        dist = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
        line[mp(slope,dist)] ++;
    }
    ll ans=0;
    each(i,line){
        //DEBUG(i.fi.fi),DEBUG(i.fi.se),DEBUG(i.se);
        ans += i.se * (i.se-1)/2;
    }
    cout<<ans/2<<nl;
}