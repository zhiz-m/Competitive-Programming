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

const int N=200200;
int a[N],n;

void solve(){
    ll s=0,cur=0,ans;
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        if (i%2==0)s+=a[i];
    }
    ans=s;
    for(int i=1;i<n-1;i+=2){
        cur+=a[i]-a[i+1];
        ans=max(ans,s+cur);
        if (cur<0)cur=0;
    }
    cur=0;
    for(int i=0;i<n-1;i+=2){
        cur+=-a[i]+a[i+1];
        ans=max(ans,s+cur);
        if (cur<0)cur=0;
    }
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}