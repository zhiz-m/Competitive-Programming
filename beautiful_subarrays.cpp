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

const int N=1000100, L=30;
int n,k,v[N],trie[N*L][2],cnt=1,occ[N*L][2];

void add(int u){
    int p=0;
    per(i,0,L){
        int b=(u>>i)&1;
        occ[p][b]++;
        if (trie[p][b]==-1){
            trie[p][b]=cnt++;
        }
        p=trie[p][b];
    }
}

int recur(int p, int i, int b, int tot, int u){
    if (occ[p][b]==0)return 0;
    int ub=((u>>i)&1);
    if ((ub^b)==0&&tot+(1<<i)<=k)return 0;
    tot += (ub^b)<<i;
    if (tot>=k) return occ[p][b];
    return recur(trie[p][b],i-1,0,tot,u) + recur(trie[p][b],i-1,1,tot,u);
}

int main(){
    upgrade();
    memset(trie,-1,sizeof(trie));
    memset(occ,0,sizeof(occ));
    cin>>n>>k;
    rep(i,0,n)cin>>v[i];
    int cur=0;
    ll ans=0;
    rep(i,0,n){
        add(cur);
        cur^=v[i];
        //DEBUG(recur(0,L-1,0,0,cur));
        //DEBUG(recur(0,L-1,1,0,cur));
        //DEBUG(occ[0][0]);
        ans+=recur(0,L-1,0,0,cur)+recur(0,L-1,1,0,cur);
        //DEBUG(ans);
    }
    cout<<ans<<nl;
}