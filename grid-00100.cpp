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

const int N=330;
vector<VI> v(330,VI(330));
int n,k,cur,suc;

void rfill(int u){
    int x=n-u-1,y=0;
    while(x>=n)x--,y++;
    while(x>=0 && y<n){
        if (cur==k){
            suc=0;break;
        }
        if (v[x][y]==0)cur++;
        v[x][y]=1;
        x--;
        y++;
    }
}

void lfill(int u){ //fills diagonal from top left
    int x=u,y=0;
    while(x<0)x++,y++;
    while(x<n && y<n){
        if (cur==k){
            suc=0;break;
        }
        if (v[x][y]==0)cur++;
        v[x][y]=1;
        x++;
        y++;
    }
}

void solve(){
    cin>>n>>k;
    suc=1;
    rep(i,0,n)rep(j,0,n)v[i][j]=0;
    cur=0;
    int cnt=1,prev=0,f=0;
    lfill(0);
    while(cur!=k){
        if (f==0 && n%2==0){
            rfill(prev);
            f=1;
        }
        else{
            if (prev<=0)prev=-prev+1;
            else prev=-prev;
            lfill(prev);
            f=0;
        }
        cnt++;
    }
    int a=0,b=1e9,c=0,d=1e9;
    rep(i,0,n){
        int t=0;
        rep(j,0,n)t+=v[i][j];
        a=max(a,t);
        b=min(b,t);
    }
    rep(i,0,n){
        int t=0;
        rep(j,0,n)t+=v[j][i];
        c=max(a,t);
        d=min(b,t);
    }
    int ans=(a-b)*(a-b)+(c-d)*(c-d);
    cout<<ans<<nl;
    rep(i,0,n){
        rep(j,0,n)cout<<v[i][j];
        cout<<nl;
    }
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}