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

ll n,q,h,cur,p;
stack<ll> sk;

void get(ll u){
    if (u==cur || cur%2==1) return;
    sk.push(cur);
    if (u<cur) cur-=p, p>>=1;
    else cur+=p, p>>=1;
    get(u);
}

int main(){
    upgrade();
    h=0;
    cin>>n>>q;
    if (n==1){
        rep(i,0,q){
            ll u;string s;
            cin>>u>>s;
            cout<<1<<nl;
        }
        return 0;
    }
    n++;
    while(n>1) h++, n>>=1;
    rep(zz,0,q){
        ll u; string s;
        cin>>u>>s;
        cur = 1ll<<(h-1);
        p = 1ll<<(h-2);
        while(!sk.empty())sk.pop();
        //DEBUG(u),DEBUG(cur);
        get(u);
        each(i,s){
            if (cur == 1ll<<(h-1) && i=='U')continue;
            if (i!='U' && cur%2==1) continue;
            if (i=='U') cur=sk.top(),sk.pop(),p=(p==0)?1:p<<1;
            else if (i=='R') sk.push(cur),cur+=p,p>>=1;
            else if (i=='L') sk.push(cur),cur-=p,p>>=1;
        }
        cout<<cur<<nl;
    }
}