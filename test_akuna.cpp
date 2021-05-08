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
/*
int get_ind(vector<string> &grid, int x, int y){
    return x*SZ(grid)+y;
}

void connect(vector<vector<int>> &adj, vector<string> &grid, int a1, int a2, int b1, int b2){
    if (b1<0 || b1>=SZ(grid) || b2 <0 || b2>=SZ(grid[0])) return;
    if (grid[b1][b2]=='#') return;
    int ind1=get_ind(grid,a1,a2), ind2=get_ind(grid,b1,b2);
    adj[ind1].push_back(ind2);
}

string reachTheEnd2(vector<string> grid, int maxTime) {
    vector<vector<int>> adj(SZ(grid)*SZ(grid[0]));
    vector<pair<int,int>> deltas = {{1,1},{1,-1},{-1,-1},{-1,1}};
    for(int i=0; i<SZ(grid);i++){
        for(int j=0; j<SZ(grid[0]); j++){
            for(pair<int,int> d:deltas){
                connect(adj,grid,i,j,i+d.first,j+d.second);
            }
        }
    }
    priority_queue<int> pq;
    
}
*/

int main(){
    string ans;
    ans=ans+('a'+1);
    cout<<ans<<nl;
}