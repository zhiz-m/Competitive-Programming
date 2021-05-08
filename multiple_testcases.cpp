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

VI c,m,s;
vector<VI> ans;

int main(){
    upgrade();
    int n,k,input;cin>>n>>k;
    m.assign(k+1,0);
    c.assign(k+1,0);
    rep(i,0,n){
        cin>>input;
        m[input]++;
    }
    rep(i,1,k+1){
        cin>>c[i];
    }
    //sort(all(m),greater<int>());
    per(i,1,k+1){
        if (m[i]==0) continue;
        int p = lower_bound(all(s),-c[i]+1)-s.begin();
        while(m[i]!=0){
            if (p==SZ(s)){
                s.pb(0);
                ans.pb({});
            }
            while(-s[p]<c[i] && m[i]!=0){
                s[p]--;
                m[i]--;
                ans[p].pb(i);
            }
            if (m[i]!=0)p++;
        }
    }
    cout<<SZ(ans)<<nl;
    rep(i,0,SZ(ans)){cout<<SZ(ans[i])<<' ';rep(j,0,SZ(ans[i])) cout<<ans[i][j]<<' '; cout<<nl;}
}