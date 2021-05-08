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

const ld PI=atanl(1)*4;
const ld EP=1e-10;

ld dist(ll a,ll b, ll c, ll d){
    return sqrtl((a-c)*(a-c)+(b-d)*(b-d));
}

int main(){
    upgrade();
    cout<<setprecision(10);
    ll x1,y1,r1,x2,y2,r2; //r1 smaller
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    if (r1>r2) swap(x1,y1),swap(x2,y2),swap(r1,r2);
    ld d=dist(x1,y1,x2,y2);
    if (d-EP+r1<=r2){
        cout<<PI*r1*r1<<nl;
        return 0;
    }
    else if(d+EP>=r1+r2){
        cout<<0<<nl;
        return 0;
    }
    ld t=(d*d+r1*r1-r2*r2)/(2*d);
    //ld h2=sqrtl(r1*r1-t*t);
    ld a1=2*acosl(t/r1),a2=2*acosl((d-t)/r2);
    //DEBUG(a1),DEBUG(a2),DEBUG(sinl(a1)),DEBUG(sinl(a2));
    cout<<a1/2*r1*r1+a2/2*r2*r2-r1*r1*sinl(a1)/2-r2*r2*sinl(a2)/2<<nl;
}