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

const int N=100100;
int n, v[N];
vector<PII> ans;
VI two;

void fail(){
    cout<<-1<<nl;
    exit(0);
}

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n+1)cin>>v[i];
    if (v[n]>1)fail();
    int one=0;
    per(i,1,n+1){
        if (v[i]==1)one++;
        if (v[i]==2)one--;
        if (one<0)fail();
    }  
    int cur=1, f=0, fcur;
    rep(i,1,n+1){
        if (v[i]==0)continue;
        if (f && !(v[i]==1 && !two.empty()))f=0, ans.pb(mp(fcur,i));
        if (v[i]==3) f=1, fcur=cur,ans.pb(mp(cur,i)),cur++;
        if (v[i]==2) two.pb(cur),ans.pb(mp(cur,i)),cur++;
        if (v[i]==1){
            if(two.empty()){
                ans.pb(mp(cur,i));
                cur++;
            }
            else{
                ans.pb(mp(two.back(),i));
                two.pop_back();
            }
        } 
    }
    if (SZ(two)!=0 || f)fail();
    cout<<SZ(ans)<<nl;
    each(i,ans)cout<<i.fi<<" "<<i.se<<nl;
}