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
const ll MOD=998244353;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO
 
VLL fact;
VLL fin;
ll n;
 
ll calc(int r){
    return fact[n]*fin[n-r]%MOD;
}
 
int main(){
    upgrade();
    cin>>n;
    fact.assign(n+1,1);
    fin.assign(n+1,1);
    rep(i,1,n+1){
        fact[i]=fact[i-1]*i%MOD;
    }
    fin[n]=powmod(fact[n],MOD-2);
    per(i,1,n) {fin[i]=fin[i+1]*(i+1)%MOD;}
    ll ans=fact[n];
    rep(i,1,n){
        ans=(ans+(calc(i)*(fact[n-i]-1)%MOD))%MOD;
    }
    cout<<ans<<nl;
}