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
int n,m,q;
vector<VI> grid(N,VI(N,-1)),change=grid,ans(N,VI(N,-1));
queue<tuple<int,int,int>> qu;

bool check(int i, int j, int c){
    if (i<0 || i>=n || j<0 || j>=m)return 0;
    return grid[i][j]==c;
}

void bfs(int i, int j, int dist){
    if (i<0 || i>=n || j<0 || j>=m || ans[i][j]!=-1)return;
    ans[i][j]=dist++;
    qu.push(make_tuple(i-1,j,dist));
    qu.push(make_tuple(i+1,j,dist));
    qu.push(make_tuple(i,j+1,dist));
    qu.push(make_tuple(i,j-1,dist));
}

int main(){
    upgrade();
    cin>>n>>m>>q;
    rep(i,0,n){
        string str;cin>>str;
        rep(j,0,m){
            grid[i][j]=str[j]-'0';
        }
    }
    rep(i,0,n)rep(j,0,m){
        int t=0;
        t|=check(i-1,j,grid[i][j]);
        t|=check(i+1,j,grid[i][j]);
        t|=check(i,j-1,grid[i][j]);
        t|=check(i,j+1,grid[i][j]);
        change[i][j]=t;
        if (t==1)qu.push(make_tuple(i,j,0));
    }
    while(!qu.empty()){
        auto t=qu.front();
        bfs(get<0>(t),get<1>(t),get<2>(t));
        qu.pop();
    }
    while(q--){
        ll i,j,p;cin>>i>>j>>p;
        i--;j--;
        if (ans[i][j]==-1||p<=ans[i][j]) cout<<grid[i][j]<<nl;
        else {
            int t=grid[i][j]+(p-ans[i][j])%2;
            cout<<(t==0 || t==2?0:1)<<nl;
        }
    }
}