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
VI v(N,-1);
//vector<VI>d;
int n,k;

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        cin>>n>>k;
        int cnt=0;
        rep(i,2,n+2){
            cin>>v[i];
            if (v[i]==k)cnt++;
        }
        if (!cnt){
            cout<<"NO"<<nl;
            continue;
        }
        if (n==1){
            cout<<"YES"<<nl;
            continue;
        }
        //d.clear();
        //if (v[0]==k)d.pb(VI());
        //VI temp;
        bool suc=0;
        rep(i,2,n+2){
            if (v[i]>=k){
                if (v[i]==k){
                    if (v[i-1]>=k || v[i-2]>=k)suc=1;
                }
                else{
                    if (v[i-1]>=k)suc=1;
                    if (v[i-2]>=k && (v[i-1]!=k || cnt>1))suc=1;
                }
            }
        }
        cout<<(suc?"YES":"NO")<<nl;
    }
}