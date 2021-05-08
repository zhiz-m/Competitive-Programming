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
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll ans=0;
    ll cur=0;
    ll ex1=0;
    ll ex2=0;
    rep(z,c,d+1){
        if (b+c==z)break;
        int diff=b+c-z +1;
        if (z==c){
            per(y,-INT_MAX,c+1){
                ll x=z+1-y;
                if (x>b)break;
                int suc=1;
                if (x<a){ex1++;suc=0;}
                if (y<b){ex2++;suc=0;}
                if (suc)cur+=b-max(a,x)+1;
            }
            ans+=cur;
            //DEBUG(cur),DEBUG(ex1);
        }else{
            cur-=max(0ll,diff*(c-max())-ex1);
            //DEBUG(cur),DEBUG(diff);
            ans+=cur;
            ex1=max(0ll,ex1-1);
        }
        DEBUG(cur),DEBUG(ex1),DEBUG(diff);
    }
    cout<<ans<<nl;
}