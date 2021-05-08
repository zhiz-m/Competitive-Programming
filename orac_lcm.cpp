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

const int N=200100;
int n;
VI v(N);
vector<VI> fac(N);
vector<bool> sieve(N,1);
vector<int> prime;

void factor(int num){
    if (num<2) return;
    int f=0;
    //VI temp(N);
    vector<PII> m;
    while(num!=1 && prime[f]*prime[f]<=num){
        //DEBUG(prime[f]),DEBUG(num);
        //if (!m.count(prime[f]))m[prime[f]]=0;
        if (num%prime[f]==0){
            int cnt=0;
            while(num%prime[f]==0){
                cnt++;
                num/=prime[f];
            }
            m.pb(mp(prime[f],cnt));
            //num/=prime[f];
        }
        f++;
    }
    //DEBUG(1);
    //m[num]++;
    rep(j,0,SZ(m)){
        //cout<<i.fi<<' '<<i.se<<nl;
        auto i=m[j];
        fac[i.fi].pb(i.se);
        //DEBUG(i.se);
    }
    if (num!=1)fac[num].pb(1);
    //DEBUG(1);
}

int main(){
    upgrade();
    rep(i,2,N){
        if (sieve[i]==0)continue;
        for(int j=2*i;j<N;j+=i){
            sieve[j]=0;
        }
    }
    rep(i,2,N) if (sieve[i])prime.pb(i);
    cin>>n;
    rep(i,0,n){
        cin>>v[i];
        //DEBUG(2);
        factor(v[i]);
    }
    //DEBUG(1);
    ll ans=1;
    rep(i,2,N){
        if (SZ(fac[i])<n-1)continue;
        sort(all(fac[i]));
        if (SZ(fac[i])==n-1){
            rep(j,0,fac[i][0])ans*=i;
        }
        //DEBUG(i),DEBUG(fac[i][1]);
        else if (SZ(fac[i])==n)rep(j,0,fac[i][1])ans*=i;
    }
    cout<<ans<<nl;
}