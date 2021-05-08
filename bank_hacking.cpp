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

const int N=300300;
int n,v[N],mx;
VI adj[N];
map<int,int> s;

int main(){
    upgrade();
    cin>>n;
    //int c=1;
    mx=-1e9;
    rep(i,1,n+1){
        cin>>v[i],s[v[i]+2]++;
        mx=max(mx,v[i]+2);
        /*if (v[i]+2==mx)c++;
        else if (v[i]+2>mx){
            c=1;
            mx=v[i]+2;
        }*/
    }
    rep(i,1,n){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans=2e9;
    rep(i,1,n+1){
        //int cnt=0;
        //if (v[i]==mx-2)cnt++;
        each(u,adj[i])/*cnt+=(v[u]==(mx-1)),*/s[v[u]+2]--,s[v[u]+1]++;
        s[v[i]+2]--,s[v[i]]++;
        //DEBUG(i),DEBUG(s[v[i]+1]),DEBUG(s[v[i]+2]);
        per(j,mx-2,mx+1){
            //DEBUG(j),DEBUG(s[j]);
            if (s[j]!=0){
                ans=min(ans,j);
                break;
            }
        }
        s[v[i]]--,s[v[i]+2]++;
        each(u,adj[i])s[v[u]+1]--,s[v[u]+2]++;
    }
    cout<<ans<<nl;
}