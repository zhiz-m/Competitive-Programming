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

const int N=100100;

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        int l,r;
        string v;cin>>v;
        for(l=0;l<n-1;l++){
            if (v[l]!='0')break;
        }
        for(r=n;r>0;r--){
            if (v[r-1]!='1')break;
        }
        //DEBUG(l),DEBUG(r);
        if (l>=n-1||r<=0||l==r){
            cout<<v<<nl;
            continue;
        }
        string ans;
        rep(i,0,l){
            ans+=v[i];
        }
        ans+='0';
        rep(i,r,n)ans+=v[i];
        cout<<ans<<nl;
    }
}