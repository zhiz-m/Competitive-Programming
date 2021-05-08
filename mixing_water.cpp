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
ll h,c,x;
ll get(ll n){
    ll t=(n+1)*h+n*c;
    return t;
}

void solve(){
    cin>>h>>c>>x;
    if (2*x<=h+c){
        cout<<2<<nl;return;
    }
    else if (x==h){
        cout<<1<<nl;return;
    }
    else{
        ll n=(h-x)/(2*x-h-c);
        DEBUG(n);
        ll t1 = get(n),t2=get(n+1);
        //DEBUG(n);
        //DEBUG(n);DEBUG(((long double)(n+1)*h+n*c)/(2*n+1));
        //DEBUG(n+1);DEBUG(((long double)(n+2)*h+(n+1)*c)/(2*n+3));
        //DEBUG((double)(2*h+c)/3);
        //assert(t2-0.000001<x);
        if (t1*(2*n+3)+t2*(2*n+1)<=2*x*(2*n+1)*(2*n+3))cout<<2*n+1<<nl;
        else cout<<2*n+3<<nl;
        //cout<<fixed<<setprecision(8);
        //cout<<n<<' '<<((double)(n+1)*h+n*c)/(2*n+1)<<nl;
        //cout<<n+1<<' '<<((double)(n+2)*h+(n+1)*c)/(2*n+3)<<nl;
        //rep(i,0,20)cout<<1<<' '<<((double)(i+1)*h+i*c)/(2*i+1)<<nl;
        //cout<<((int)2*n+1)<<nl;
    }
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}