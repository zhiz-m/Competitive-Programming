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

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        ll x,y,a,b;cin>>x>>y>>a>>b;
        ll cost=0;
        if (x<=0 && y>=0) {cout<<(y-x)*a<<nl;continue;}
        else if (y<=0 && x>=0) {cout<<(x-y)*a<<nl;continue;}
        if (x<=0){
            cost+=(max(x,y)-min(x,y))*a;
            if (b>2*a) cost+=2*a*(min(abs(x),abs(y)));
            else cost += b*(min(abs(x),abs(y)));
        }
        if (x>=0){
            cost+=(max(x,y)-min(x,y))*a;
            if (b>2*a) cost+=2*a*(min(x,y));
            else cost += b*(min(x,y));
        }
        cout<<cost<<nl;
    }
}