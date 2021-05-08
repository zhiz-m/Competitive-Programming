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

const int N=100100;
ll n,d,m,n1,n2,v1[N],v2[N],pre1[N],pre2[N];

int main(){
    upgrade();
    cin>>n>>d>>m;
    d++;
    n1=n2=0;
    rep(i,0,n){
        int a;cin>>a;
        if (a<=m)v1[++n1]=a;
        else v2[++n2]=a;
    }
    sort(v1+1,v1+n1+1,greater<ll>());
    sort(v2+1,v2+n2+1,greater<ll>());
    pre1[0]=pre2[0]=0;
    rep(i,1,n+1)pre1[i]=i<=n1?pre1[i-1]+v1[i]:pre1[i-1];
    rep(i,1,n+1)pre2[i]=i<=n2?pre2[i-1]+v2[i]:pre2[i-1];
    ll ans=pre1[n];
    ll st=n/d;
    while(st>=0){
        ll t;
        if (st*d==n){
            t=pre2[st];
            //ans=max(ans,pre2[st]);
        }
        else{
            t=pre2[st+1]+pre1[n-st*d-1];
        }
        ans=max(ans,t);
        //DEBUG(t);
        st--;
    }
    cout<<ans<<nl;
}