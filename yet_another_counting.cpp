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

ll lcm(ll a, ll b){
    if (a==b) return a;
    if (a>b) swap(a,b); // a small, b large
    ll t=a;
    while (t<b || t%b !=0){ t+=a;}
    return t;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        ll a,b,q;cin>>a>>b>>q;
        if (a<b) swap(a,b);
        ll g=lcm(a,b);
        //DEBUG(g),DEBUG(mn);
        //rep(i,100,201){if ((i%10)%7==(i%7)%10) cout<<i<<nl;}
        //return 0;
        rep(i,0,q){ // range: mn and gcd-1, l and r; 
            ll l,r;cin>>l>>r;
            if (g==a || g==b){
                cout<<0<<' ';
                continue;
            }
            if (l-l%g+a>l)l=l-l%g+a;
            if (r-r%g+a>r)r=r-r%g+a-1;
            //DEBUG(l),DEBUG(r);
            /*
            if (suc){
                cout<<r-l+1<<' ';
                continue;
            }*/
            ll num=r/g-l/g;
            //DEBUG(l),DEBUG(r),DEBUG(num);
            if (r<l || r<1){
            //    DEBUG('h');
                cout<<0<<' ';
                continue;
            }
            cout<<r-l+1-a*num<<' ';
        }
        cout<<nl;
    }
}