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

const int N=100100;
const long double PI=4*atan((long double)1);
vector<PII> v(N);
vector<pair<long double,int>> r(N);
int n;

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n){
        int x,y;cin>>x>>y;
        v[i].fi=x,v[i].se=y;
    }
    rep(i,0,n){
        r[i].se=i;
        r[i].fi=atan2((long double)v[i].se,(long double)v[i].fi);
        if (r[i].fi<0)r[i].fi+=2*PI;
    }
    sort(r.begin(),r.begin()+n);
    int v1=r[0].se,v2=r[n-1].se;
    long double ans=r[n-1].fi-r[0].fi;
    if (ans>PI)ans=2*PI-ans;
    rep(i,0,n-1){
        if (-r[i].fi+r[i+1].fi<ans)v1=r[i].se,v2=r[i+1].se,ans=-r[i].fi+r[i+1].fi;
    }
    cout<<v1+1<<' '<<v2+1<<nl;
}