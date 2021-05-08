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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

int n,k,inc=200009;
VI v,v2;

bool check(){
    rep(i,0,n){
        if (v2[i]>v[i]) return true;
        if (v2[i]<v[i]) return false;
    }
    return true;
}

int main(){
    upgrade();
    cin>>n>>k;
    v.resize(n);
    //VI c(n,0);
    char c;
    rep(i,0,n){ 
        cin>>c;
        v[i]=c-'0';
    }
    //int suc=1;
    v2=v;
    rep(i,k,n){
        v2[i]=v2[i-k];
    }
    if (!check()){
        per(i,0,k){
            if (v2[i]!=9){
                v2[i]++;
                rep(j,i+1,k){
                    v2[j]=0;
                }
                break;
            }
        }
        rep(i,k,n){
            v2[i]=v2[i-k];
        }
    }
    cout<<n<<nl;
    rep(i,0,n)cout<<v2[i];
    cout<<nl;
}