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

const int N=24;
int n;
ld v[N][N],w[N],pr[N][N];

int key(ld a[], ld b[]){
    return a[0]<b[0];
}

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n){
        rep(j,0,n)cin>>v[i][j];
    }
    rep(i,1,n)v[i][0]=v[0][i];
    sort(v,v+n,key);
    rep(i,1,n){
        pr[i][i]=1;
        rep(j,i+1,n)pr[i][j]=pr[i][j-1]*v[i][j];
    }
    w[1]=1;
    rep(i,2,n){
        w[i]=1;
        rep(j,1,i){
            w[i]-=w[j]*pr[j][i];
        }
    }
    ld ans=1;
    rep(i,1,n){
        ans-=w[i]*pr[i][n-1];
    }
}