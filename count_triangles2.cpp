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

int main(){
    upgrade();
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    ll prev=0,en=b-a+1,trail=LLONG_MIN;
    ll tot=0;
    per(y,b,c+1){
        ll z=c;
        ll x=z-y+1;
        //DEBUG(x);
        if (x>b){
            break;
        }
        trail=x-a+1;
        prev+=b-max(a,x)+1;
        en=min(en,b-x+1);
        tot++;
    }
    if (trail==LLONG_MIN){
        cout<<0<<nl;return 0;
    }
    ans+=prev;
    //DEBUG(prev);
    trail=min(b-a+1,trail);
    //DEBUG(trail);
    ll cnt=0;
    rep(z,c+1,d+1){
        if (trail>0){
            prev-=trail;
            en--;
            trail++;
            if (en<=0)trail--,cnt++;
        }
        else{
            trail++;
        }
        trail=min(trail,b-a+1);
        trail=min(trail,tot-cnt);
        if(prev<0)break;
        ans+=prev;
    }
    cout<<ans<<nl;
}