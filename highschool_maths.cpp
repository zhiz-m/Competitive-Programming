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

const int N=200100;
ll a,b;

ll get(ll t){
    rep(i,2,N){
        if (t%i==0) return i;
    }
    return t;
}

int main(){
    cin>>a>>b;
    ll c,d;
    c = get(a),d=get(b);
    ll ans = c+d;
    if (c==d) ans=c;
    rep(i,2,N){
        if (a==i)continue;
        if (a%i ==0){
            if (b%i ==0)
                ans = min(ans,(ll)i);
        }
    }/*
    rep(i,2,N){
        if (a==i) break;
        if (a%i ==0 && b%(a/i) == 0){
            ans = min(ans,a/i);
        }
    }
    rep(i,2,N){
        if (b==i)break;
        if (b%i ==0 && a%(b/i) == 0){
            ans = min(ans,b/i);
        }
    }*/
    cout<<ans<<nl;
}