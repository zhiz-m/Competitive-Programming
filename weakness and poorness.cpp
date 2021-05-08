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
const double EP=0.00000000001;
const int N=200200;
int n;
vector<double> v(N);

double get(double u){
    //rep(i,0,n)v[i]-=u;
    double cur=0,mx=-1;
    rep(i,0,n){
        cur+=v[i]-u;
        if (cur<0)cur=0;
        mx=max(cur,mx);
    }
    cur=0;
    rep(i,0,n){
        cur-=v[i]-u;
        if (cur<0)cur=0;
        mx=max(cur,mx);
    }
    //rep(i,0,n)v[i]+=u;
    return mx;
}

int main(){
    cin>>n;
    rep(i,0,n)cin>>v[i];
    double l=-10000,r=10000,m,a,b;
    while(r-l>EP){
        m=(r+l)/2;
        a=get(m);
        b=get(m-EP);
        if (a>b)r=m;
        else l=m;
    }

    cout<<fixed<<setprecision(20);
    cout<<min(get(l),get(r))<<nl;
}