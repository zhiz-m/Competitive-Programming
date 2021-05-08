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
        string s;cin>>s;
        int n=SZ(s);
        int suc=1;
        rep(i,1,n)if (s[i]!=s[i-1]) suc=0;
        if (suc){
            cout<<s<<nl;
            continue;
        }
        char st=s[0];
        rep(i,0,n){
            cout<<s[i];
            if (s[i]=='0' && ((i==n-1 && s[i]==st) || s[i+1]=='0')) cout<<1;
            if (s[i]=='1' && ((i==n-1 && s[i]==st) || s[i+1]=='1')) cout<<0;
        }
        cout<<nl;
    }
}