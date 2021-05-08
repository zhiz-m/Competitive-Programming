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

const int N=1000100;
PII v[2*N],ans[N],ret[N]; //0 is start, 1 is end;
int n,k;

int main(){
    upgrade();
    cin>>n>>k;
    rep(i,0,n){
        ans[i]=mp(-1,-1);
        int a,b;cin>>a>>b;
        v[2*i]=mp(a,0);
        v[2*i+1]=mp(b,1);
    }
    sort(v,v+2*n);
    int cur=0,p=0;
    rep(i,0,2*n){
        int prev=cur;
        if (v[i].se==0)cur++;
        else cur--;
        if (prev>=k && cur<k)ans[p].se=v[i].fi,p++;
        else if (prev<k && cur>=k)ans[p].fi=v[i].fi;
    }
    int j=0;
    rep(i,0,p){
        if (i!=p-1&&ans[i].se==ans[i+1].fi)ans[i+1].fi=ans[i].fi;
        else ret[j++]=ans[i];
    }
    cout<<j<<nl;
    rep(i,0,j){
        cout<<ret[i].fi<<' '<<ret[i].se<<nl;
    }
}