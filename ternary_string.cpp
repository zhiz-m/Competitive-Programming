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

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        string str;cin>>str;
        int n=SZ(str);
        int a,b,c;
        a=b=c=-INT_MAX;
        int ans=INT_MAX;
        rep(i,0,n){
            if (str[i]=='1')a=0;
            else if (str[i]=='2')b=0;
            else c=0;
            if (a>=0 && b>=0 && c>=0){
                ans=min(ans,max(c,max(a,b))+1);
            }
            a++;b++;c++;
        }
        if (a<0 || b<0 || c<0)cout<<0<<nl;
        else cout<<ans<<nl;
    }
}