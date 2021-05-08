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
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;	
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}

int main(){
    int a[1000][1000];
    VI across[1000];
    VI down[1000];
    upgrade();
    int n,m;cin>>n>>m;
    rep(i,0,n) rep(j,0,m) cin>>a[i][j];
    rep(i,0,n){
        VI temp(1,0);
        rep(j,0,m)temp.pb(a[i][j]);
        sort(all(temp));
        rep(j,1,m+1)if (temp[j]!=temp[j-1])across[i].pb(temp[j]);
    }
    rep(i,0,m){
        VI temp(1,0);
        rep(j,0,n)temp.pb(a[j][i]);
        sort(all(temp));
        rep(j,1,n+1)if (temp[j]!=temp[j-1])down[i].pb(temp[j]);
    }
    rep(i,0,n){ rep(j,0,m){
        int num=a[i][j];
        int p1 = lower_bound(all(across[i]),num)-across[i].begin();
        int p2 = lower_bound(all(down[j]),num)-down[j].begin();
        int mx=max(p1,p2);
        cout<<max(mx+SZ(across[i])-p1,mx+SZ(down[j])-p2)<<' ';
    }cout<<nl;}
}