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

const int N=300300;
int n,k,v[N];
VI zero,pre,suf;

int main(){
    upgrade();
    cin>>n>>k;
    int one=0,mx=0;
    rep(i,0,n){
        cin>>v[i];
        if (v[i]==0)zero.pb(i);
    }
    rep(i,0,n){
        if (v[i]==1)one++;
        else pre.pb(one),one=0;
        mx=max(mx,one);
    }
    one=0;
    per(i,0,n){
        if (v[i]==1)one++;
        else suf.pb(one),one=0;
    }
    reverse(all(suf));
    if (SZ(zero)<=k){
        cout<<n<<nl;
        rep(i,0,n)cout<<1<<" \n"[i==n-1];
        return 0;
    }
    if (k==0){
        cout<<mx<<nl;
        rep(i,0,n)cout<<v[i]<<" \n"[i==n-1];
        return 0;
    }
    int best=-1,cur;
    rep(i,0,SZ(zero)-k+1){
        //DEBUG(zero[i]);
        int t=zero[i+k-1]-zero[i]+pre[i]+suf[i+k-1]+1;
        //DEBUG(pre[i]),DEBUG(suf[i]),DEBUG(t);
        if (t>best){
            cur=i,best=t;
        }
    }
    cout<<best<<nl;
    rep(i,0,n)cout<<(i>=zero[cur] && i<= zero[cur+k-1]?1:v[i])<<" \n"[i==n-1];
}