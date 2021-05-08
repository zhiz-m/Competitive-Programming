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

ll n,k,l1,l2,r1,r2;

void solve(){
    cin>>n>>k>>l1>>r1>>l2>>r2;
    ll cost,gain;
    ll initial;
    if (l1>l2)swap(l1,l2),swap(r1,r2);
    if (r1<l2){
        cost = l2-r1;
        initial=0;
        gain=r2-l1;
    } else {
        cost=0;
        if (r1>=r2){
            gain=l2-l1+r1-r2;
            initial=(r2-l2)*n;
        }
        else{
            gain=r2-r1+l2-l1;
            initial = (r1-l2)*n;
        }
    }
    if (k<=initial){
        cout<<0<<nl;
        return;
    }
    else k-=initial;
    if (k<=gain){
        cout<<cost+k<<nl;
        return;
    }
    //DEBUG(1);
    ll ans=cost+gain;k-=gain,n--;
    if (cost+gain>=2ll*gain){
        cout<<ans+2ll*k<<nl;
        return;
    }
    //DEBUG(1);
    //DEBUG(k),DEBUG(cost),DEBUG(gain);
    if (n*gain<k){
        //DEBUG(n*gain);
        //DEBUG(ans),DEBUG(n),DEBUG(k);
        
        cout<<ans+n*gain+(k-n*gain)*2+n*cost<<nl;
    }
    else{
        ll num=k/gain;
        //DEBUG(num);
        //if (k-gain*num==0)
        if (k-gain*num>0 && cost<(k-gain*num))cout<<ans+(num+1)*cost+k<<nl;
        else cout<<ans+num*cost+num*gain+(k-gain*num)*2<<nl;
    }
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}