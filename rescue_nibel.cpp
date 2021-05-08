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
int n,k, l[N],r[N],tot[2*N];
map<int,int> m;
Fenwick fl, fr;

struct Fenwick{ // 1 based index
    const int LOG=20;
    int n;
    VLL fen;
    void init(){
        n=N*LOG;
        fen.assign(n,0);
    }
    void add(ll u, int i){
        while(i<n){
            fen[i]+=u;
            i+=i&-i;
        }
    }
    ll get(int i){
        ll ret=0;
        while(i){
            ret+=fen[i];
            i-=i&-i;
        }
        return ret;
    }
};

int main(){
    upgrade();
    cin>>n>>k;
    rep(i,0,n){
        cin>>l[i]>>r[i];
        tot[2*i]=l[i],tot[2*i+1]=r[i];
    }
    sort(tot,tot+2*n);
    tot[2*n]=-1;
    rep(i,0,2*n){
        if (tot[i]!=tot[i+1])m[tot[i]]=i+1;
    }
    rep(i,0,n){
        fl.add(l[i]);
        fr.add(r[i]+1);
    }
    ll ans=0;
}