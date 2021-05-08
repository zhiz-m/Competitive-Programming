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
const int N=500100;

VLL pre(2*N,-1);
int main(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll ans=0;
    rep(s,a+b,b+c+1){
        int x=a;
        int y=s-x;
        if (y>c)x+=y-c,y=c;
        //DEBUG(s);
        pre[s]=min(b-x+1,y-b+1);
    }
    per(s,d+2,b+c+1){
        if (pre[s]<0)break;
        ans+=(d-c+1)*pre[s];
    }
    //DEBUG(ans);
    ll prev=0;
    per(z,c,d+1){
        //DEBUG(z),DEBUG(pre[z+1]);
        if (pre[z+1]>0)prev+=pre[z+1];
        ans+=prev;
    }
    cout<<ans<<nl;
}