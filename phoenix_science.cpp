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
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        VI ans;
        int m=1;
        int num=1;
        while(true){
            int diff=n-m;
            if(diff<=num*2 && diff>=num){
                ans.pb(diff-num);
                break;
            }
            int g=min(diff/2,2*num);
            //DEBUG(g),DEBUG(num),DEBUG(m);
            assert(g>=num);
            ans.pb(g-num);
            num=g;
            m+=num;
        }
        cout<<SZ(ans)<<nl;
        rep(i,0,SZ(ans))cout<<ans[i]<<' ';
        cout<<nl;
    }
}