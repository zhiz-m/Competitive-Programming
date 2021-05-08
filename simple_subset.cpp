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

const int N=1500;
int n,v[N],sieve[N*N];
set<int> prime;

int main(){
    upgrade();
    cin>>n;
    int one=0, sec=-1;
    rep(i,2,N*N)sieve[i]=1;
    rep(i,2,N*N){
        if (sieve[i]){
            for(int j=i+i;j<N*N;j+=i)sieve[j]=0;
            prime.insert(i);
        }
    }
    rep(i,0,n){
        cin>>v[i];
        one+=v[i]==1;
        if (v[i]!=1&&prime.count(v[i]+1))sec=v[i];
    }
    rep(i,0,n)rep(j,i+1,n){
        if (prime.count(v[i]+v[j])){
            if ((one+(sec!=-1))<2){
                cout<<2<<nl;
                cout<< v[i]<<" " << v[j]<<nl;
                return 0;
            }
        }
    }
    if (one == 0){
        cout<<1<<nl;
        cout<<v[0]<<nl;
        return 0;
    }
    cout<<(one+(sec!=-1))<<nl;
    rep(i,0,one)cout<<1<<" ";
    if (sec==-1)cout<<nl;
    else cout<<sec<<nl;
}