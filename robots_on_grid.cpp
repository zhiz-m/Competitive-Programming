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

int n,m,ans,black,cycle;
PII st;
VI mod;
vector<VI> grid,colour,vis;
vector<vector<PII>> up;
vector<vector<vector<PII>>> down;
set<PII> s;
void dfs2(int x, int y, int u){
    if (vis[x][y])return;
    vis[x][y]=1;
    if (u<0)u+=cycle;
    if (colour[x][y]==0 && mod[u]==0)mod[u]=1,black++;
    each(i,down[x][y]){
        //if (vis[i.fi][i.se])continue;
        dfs2(i.fi,i.se,u-1);
    }
}

void dfs1(int x, int y){
    if (s.count(mp(x,y))){
        st=mp(x,y);
        return;
    }
    else {
        s.insert(mp(x,y));
        dfs1(up[x][y].fi,up[x][y].se);
    }
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        cin>>n>>m;
        ans=black=0;
        grid.assign(n,VI(m,0));
        colour = vis = grid;
        up.assign(n,vector<PII>(m,mp(-1,-1)));
        down.assign(n,vector<vector<PII>>(m));
        rep(i,0,n){
            string str;cin>>str;
            rep(j,0,m){
                colour[i][j]=str[j]-'0';
            }
        }
        rep(i,0,n){
            string str;cin>>str;
            rep(j,0,m){
                grid[i][j]=str[j];
            }
        }
        rep(i,0,n)rep(j,0,m){
            int x=i,y=j;
            if (grid[i][j]=='U')x--;
            else if (grid[i][j]=='D')x++;
            else if (grid[i][j]=='L')y--;
            else if (grid[i][j]=='R')y++;
            else assert(0);
            assert(x<n);assert(y<m);
            up[i][j]=mp(x,y);
            down[x][y].pb(mp(i,j));
        }
        //DEBUG(2);
        rep(i,0,n)rep(j,0,m)if (!vis[i][j]){
            s.clear();
            //DEBUG(1);
            dfs1(i,j);
            //DEBUG(1);
            cycle=0;
            int x=st.fi,y=st.se;
            do{
                //vis[x][y]=1;
                int t1=x,t2=y;
                x=up[t1][t2].fi,y=up[t1][t2].se;
                cycle++;
                //DEBUG(cycle);
            }while(x!=st.fi || y!=st.se);
            
            mod.assign(cycle,0);
            //DEBUG(3);
            dfs2(st.fi,st.se,0);
            ans+=cycle;
            //DEBUG(1);
        }
        cout<<ans<<' '<<black<<nl;
    }
}