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

int main(){
    upgrade();
    int k;cin>>k;
    int tot=1<<k;
    vector<VI> ans(tot,VI(tot,-2));
    //rep(i,0,tot) cout<<'+';
    //cout<<nl;
    ans[0][0]=1;
    rep(i,1,k+1){
        int cur=1<<i;
        int prev=cur>>1;
        rep(j,0,prev){
            rep(l,0,prev){
                ans[j+prev][l]=ans[j][l];
                ans[j][l+prev]=ans[j][l];
                ans[j+prev][l+prev]=ans[j][l]==1?-1:1;
            }
        }
    }
    rep(i,0,tot){
        rep(j,0,tot){
            cout<<(ans[i][j]==1?'+':'*');
        }
        cout<<nl;
    }
}