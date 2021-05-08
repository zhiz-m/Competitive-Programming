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

const int N=55;
int r,c, v[N][N], vis[N][N][2];

void calc(int i, int j, int f){
    if (i < 0 || i >=r || j == c || vis[i][j][f])return;
    //DEBUG(i),DEBUG(j),DEBUG(f);
    vis[i][j][f]=1;
    if (v[i][j] == 'o'){
        if (f==1)return;
        calc(i-1,j-1,1),calc(i-1,j+1,1);
        return;
    }
    v[i][j] = '*';
    calc(i+1,j,0);
}

int main(){
    upgrade();
    cin>>r>>c;
    memset(vis,0,sizeof(vis));
    rep(i,0,r){
        string s;cin>>s;
        rep(j,0,c){
            v[i][j]=s[j];
        }
    }
    rep(i,0,r)rep(j,0,c){
        if (v[i][j]=='*')calc(i,j,0);
    }
    rep(i,0,r){
        rep(j,0,c){
            cout<<(char)v[i][j];
        }
        cout<<nl;
    }
}