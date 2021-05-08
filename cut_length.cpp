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

const int N=1010;
int n,v[N][2][2],lx1,ly1,lx2,ly2,g; //[number of edges][edge 1, edge 2][x, y]
vector<PII> sec(N);

PII calc(int x1, int y1, int x2, int y2){
    if (x2==x1){
        
    }
}

int main(){
    upgrade();
    int tc;
    cin>>n>>tc;
    rep(i,0,n){
        int opp=(i==n-1?0:i+1);
        int x,y;cin>>x>>y;
        v[i][1][0]=x;
        v[i][1][1]=y;
        v[opp][0][0]=x;
        v[opp][0][1]=y;
    }
}