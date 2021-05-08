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

const int N=110;
int n,m,k, ans;
ll v[N][N], a[N][N], cost;

ll get(int i, int j, int l, int r){
    ll ret = a[j][r] - a[i-1][r] - a[j][l-1] + a[i-1][l-1];
    //DEBUG(i),DEBUG(j),DEBUG(l),DEBUG(r),DEBUG(ret);
    return ret;
}

void solve(){
    cin>>n>>m>>k;
    ans=0;
    cost=0;
    rep(i,1,n+1)rep(j,1,m+1)cin>>v[i][j];
    rep(i,0,n+1)a[i][0]=0;
    rep(j,0,m+1)a[0][j]=0;
    rep(i,1,n+1) rep(j,1,m+1){
        a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+v[i][j];
        //DEBUG(i),DEBUG(j),DEBUG(a[i][j]);
    }
    rep(i,1,n+1)rep(j,i,n+1){
        ll cur=0;
        int l=1,r=0,area=0;
        while(l<=m){
            //if (i==2 && j==4)DEBUG(r+1),DEBUG(get(i,j,r+1,r+1));
            while(r<m&&cur+get(i,j,r+1,r+1)<=k){
                area+=j-i+1;
                cur+=get(i,j,r+1,r+1);
                //if (i==2 && j==4)DEBUG(area);
                if (area>ans || (area==ans && cur<cost)){
                    ans = area;
                    cost=cur;
                    //DEBUG(i),DEBUG(j),DEBUG(l),DEBUG(r);
                }
                r++;
            }
            if (l<=r){
                l++;
                area-=j-i+1;
                assert(l<m+2);
                cur-=get(i,j,l-1,l-1);
            }
            else{
                l++;r++;
                //if (i==2 && j==4)DEBUG(l),DEBUG(r);
                area=0;
                cur=0;
            }
        }
    }
    cout<<ans<<" "<<cost<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    rep(i,1,tc+1){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}