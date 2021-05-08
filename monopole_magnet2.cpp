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

const int N=1010;
int a[N][N];
bool done[N][N];
int down[N],across[N];
int n,m;

void dfs(int i, int j){
    if (i<0 || i>=n ||j<0||j>=m || a[i][j]==0 || done[i][j])return;
    done[i][j]=1;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,0,n)across[i]=1;
    rep(j,0,m)down[j]=1;
    rep(i,0,n)rep(j,0,m){
        char c;cin>>c;
        if (c=='.')a[i][j]=0;
        else {a[i][j]=1;}
        done[i][j]=0;
    }
    bool suc=true;
    rep(i,0,n){
        int l=-1;
        int r=-1;
        rep(j,0,m){
            if (a[i][j]==1){
                l=j;break;
            }
        }
        per(j,0,m){
            if (a[i][j]==1){
                r=j;break;
            }
        }
        if(l==-1 && r==-1){
            across[i]=0;
            //DEBUG(i);
        }
        rep(j,l,r){
            if (a[i][j]==0){
                suc=0;break;
            }
        }
    }
    rep(j,0,m){
        int l=-1;
        int r=-1;
        rep(i,0,n){
            if (a[i][j]==1){
                l=i;break;
            }
        }
        per(i,0,n){
            if (a[i][j]==1){
                r=i;break;
            }
        }
        if(l==-1 && r==-1){
            down[j]=0;
            //DEBUG(j);
        }
        rep(i,l,r){
            if (a[i][j]==0){
                suc=0;break;
            }
        }
        //DEBUG(l),DEBUG(r);

    }
    int ac=0,dn=0;
    rep(i,0,n) if (across[i]==0) ac=1;
    rep(j,0,m) if (down[j]==0) dn=1;
    if (dn+ac==1)suc=0;
    if(!suc){
        cout<<-1<<nl;
        return 0;
    }
    int ans=0;
    rep(i,0,n)rep(j,0,m){
        if(a[i][j]==1 && !done[i][j]){
            ans++;
            dfs(i,j);/*
            rep(ii,0,n){
                rep(jj,0,m){
                    cout<<done[ii][jj]<<' ';
                }
                cout<<nl;
            }*/
        }
    }
    cout<<ans<<nl;
}