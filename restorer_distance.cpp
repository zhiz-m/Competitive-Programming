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
const int N = 100100;

int n,A,R,M,mx,mn;
VI v(N);

ll calc(int h){
    if (h<mn || h>mx)return 1e18;
    //ll ans=0; 
    ll pos=0,neg=0;
    rep(i,0,n){
        if (v[i]>h) pos+=v[i]-h;
        else neg+=h-v[i];
    }
    if (A+R<M){
        return pos*R + neg*A;
    }
    else{
        if (pos>neg) return (pos-neg)*R + neg*M;
        else return (neg-pos)*A + pos*M;
    }
}

ll search(int h){ // -1 is downwards slope, -2 is upwards slope, positive is answer
    //if (h==mn) return calc(h)<=calc(h+1);
    //if (h==mx) return calc(h)<=calc(h-1);
    ll a,b;
    a=calc(h-1);
    b=calc(h);
    //c=calc(h+1);
    //if (a>=b && b<=c)return b;
    if (a>=b)return -1;
    if (a<=b) return -2;
    else assert(0);
}

int main(){
    upgrade();
    cin>>n>>A>>R>>M;
    mx=-1,mn=INT_MAX;
    rep(i,0,n)cin>>v[i],mx=max(mx,v[i]),mn=min(mn,v[i]);
    if (mx==mn){
        cout<<0<<nl;return 0;
    }
    //rep(i,mn,mx+1)cout<<i<<' '<<calc(i)<<nl;
    int l=mn,r=mx+1,mid;
    while(r-l>5){
        mid=(l+r)/2;
        //ll t=search(mid);
        /*
        if (t>=0){
            //DEBUG(mid);
            //DEBUG(calc(mid-1)),DEBUG(calc(mid+1)),DEBUG(calc(mx)),DEBUG(mx);
            cout<<t<<nl;return 0;
        }*/
        if (calc(mid)<=calc(mid-1))l=mid;
        else r=mid+1;
        //cout<<l<<' '<<r<<' '<<mid<<nl;
    }
    ll ans=1e18;
    rep(i,l,r)ans=min(ans,calc(i));
    cout<<ans<<nl;
}