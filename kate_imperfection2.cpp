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

const int N = 500500;
VI prime,suf,pre,ans;

int main(){
    upgrade();
    int n;cin>>n;
    prime.assign(n+1,1);
    ans.assign(n+1,0);
    suf.assign(n+2,0);
    pre.assign(n+2,0);
    rep(i,2,n+1){
        for(int j=i+i;j<=n;j+=i)prime[j]=0;
    }
    rep(i,1,n+1){
        pre[i]=prime[i]+pre[i-1];
        ans[1]+=prime[i];
    }
    per(i,1,n+1)suf[i]=prime[i]+suf[i+1];
    rep(i,2,n+1){
        int l=n/i+1;
        ans[i]=n/i + i-1 + suf[max(i+1,l)];
        //DEBUG(i),DEBUG(ans[i]);
    }
    int cur=1;
    rep(i,2,n+1){
        while(i>ans[cur])cur++;
        cout<<cur<<' ';
    }
    cout<<nl;
}  