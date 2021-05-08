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

VI v;
vector<VI> ans;

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        int n,k;cin>>n>>k;
        v.resize(n);
        ans.assign(n,VI(3,-2));
        char c;
        rep(i,0,n){
            cin>>c;
            if (c=='R') v[i]=0;
            else if (c=='G') v[i]=1;
            else v[i]=2;
        }
        rep(i,0,3){
            int cost=0;
            int t=i;
            rep(j,0,k){
                if (v[j]!=t) cost++;
                t++;
                if (t==3)t=0;
            }
            ans[0][i]=cost;
        }
        rep(i,1,n-k+1){
            rep(j,0,3){
                int e=(j+k-1)%3;
                int f=v[i+k-1]!=e;
                int prev=(j-1)<0 ? 2:j-1;
                ans[i][j]=ans[i-1][prev]+f-(v[i-1]!=prev);
                //if (j==2){DEBUG(ans[i][j]),DEBUG(prev),DEBUG(f),DEBUG(e);}
            }
        }
        int t=INT_MAX;
        rep(i,0,n-k+1)rep(j,0,3){t=min(t,ans[i][j]);assert(ans[i][j]>=0);}
        cout<<t<<nl;
    }
}