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

ll h,n,q,st;
set<ll> s;


int main(){
    upgrade();
    cin>>h>>n>>q;
    st=1;
    rep(i,0,h-1)st*=2;
    rep(i,0,n){
        ll a;cin>>a;
        s.insert(a);
    }
    rep(i,0,q){
        ll a;cin>>a;
        ll cur=a-st;
        ll d=1;
        while(a!=0){
            int f=a%2;
            a/=2;
            if (s.find(a)!=s.end()){
                if (f)cur-=d;
                else cur+=d;
            }
            d*=2;
        }
        cout<<cur<<nl;
    }
}