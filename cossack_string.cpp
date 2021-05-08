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

vector<int> pre;
vector<int> eq;

int main(){
    string a,b;
    cin>>a>>b;
    pre.assign(SZ(a),0);
    eq.assign(SZ(a),0);
    rep(i,1,SZ(a)){
        pre[i]=(a[i-1]==a[i]);
        eq[i-1]=pre[i];
        pre[i]+=pre[i-1];
    }
    int cnt=0;
    rep(i,0,SZ(b)){
        cnt+=(a[i]!=b[i]);
    }
    bool f=(cnt%2==0);
    //DEBUG(f);
    int ans=f;
    rep(i,SZ(b),SZ(a)){
        //int t=SZ(b)-(pre[i+1]-pre[i-SZ(b)+1]);
        //DEBUG(t);
        int t=eq[i]+eq[i-SZ(b)];
        DEBUG(t);
        if (abs(t)%2==1) f=!f;
        if (f) ans++;
    }
    cout<<ans<<nl;
}