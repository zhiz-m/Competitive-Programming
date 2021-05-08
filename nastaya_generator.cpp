#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define SZ(x) (int)(x).size()
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=b-1;i>=a;i--)
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define upgrade ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;	
typedef long long ll;

VI v(100009);
VI v2(100009);
void solve(){
    int p=-1;
    int n;cin>>n;
    rep(i,1,n+1){
        cin>>v2[i];
        v[v2[i]]=i;
    }
    rep(i,1,n+1){
        if (p==-1)
            p=v[i];
        else if(p!=v[i]){
            cout<<"No"<<nl;
            return;
        }
        p++;
        if(p>n||v2[p]<i+1)p=-1;
    }
    cout<<"Yes"<<nl;
}

int main(){
    upgrade;
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
}