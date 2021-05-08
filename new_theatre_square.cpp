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

const int N = 1010;
vector<VI> grid(N,VI(N)); // 1 is black, 0 is white, pave white squares black;

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        int n,m,x,y;cin>>n>>m>>x>>y;
        //DEBUG(x),DEBUG(y);
        y=min(y,2*x);
        rep(i,0,n)rep(j,0,m){
            char c;cin>>c;
            grid[i][j]=c=='*';
        }
        ll cost =0;
        rep(i,0,n)rep(j,0,m){
            if (grid[i][j]==1)continue;
            if (j!=m-1 && grid[i][j+1]==0){
                cost+=y;j++;
            }
            else {
                cost+=x;
                //DEBUG(x);
            }
        }
        cout<<cost<<nl;
    }
    
}