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

const int N=500500, A=1e7+50;
VI d1(N,-1),d2(N,-1);
int n;
VI prime,sieve(A,1),fac;

void factor(int a){
    fac.clear();
    for(int i=0;prime[i]*prime[i]<=a;i++){
        if (a%prime[i]!=0)continue;
        while(a%prime[i]==0)a/=prime[i];
        fac.pb(prime[i]);
    }
    if (a!=1)fac.pb(a);
}

int main(){
    upgrade();
    cin>>n;
    //rep(i,0,A)sieve[i]=i;
    rep(i,2,A){
        if (sieve[i]==0)continue;
        prime.pb(i);
        for(int j=2*i;j<A;j+=i){
            sieve[j]=0;
        }
    }
    rep(zz,0,n){
        ll a;cin>>a;
        factor(a);
        if (SZ(fac)==1)continue;
        d1[zz]=fac[0];
        d2[zz]=1;
        rep(i,1,SZ(fac))d2[zz]*=fac[i];
    }
    rep(i,0,n)cout<<d1[i]<<" \n"[i==n-1];
    rep(i,0,n)cout<<d2[i]<<" \n"[i==n-1];
}