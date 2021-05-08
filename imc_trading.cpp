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

const int N=300300, M=300;
int n,q,v[N],p[N][M];

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n+1)cin>>v[i];
    cin>>q;
    rep(i,1,M){
        per(j,1,n+1){
            int prev;
            if (j+i>n)prev=0;
            else prev=p[j+i][i];
            p[j][i]=max(v[j],prev);
        }
    }
    rep(i,0,q){
        int x,y;cin>>x>>y;
        int suc=0;
        if (y<M){
            int b=p[x][y];
            cout<<(b>v[x]?"YES":"NO")<<nl;
            continue;
        }
        for(int j=x+y; j<=n; j+=y){
            if (v[j]>v[x]){
                cout<<"YES"<<nl;
                suc=1;
                break;
            }
        }
        if (!suc)cout<<"NO"<<nl;
    }
}