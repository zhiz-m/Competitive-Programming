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
#define upgrade ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;	
typedef long long ll;

int main(){
    upgrade;
    int tc;cin>>tc;
    while(tc--){
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int mn,mx;
        mn=c-d,mx=c+d;
        if ((mn<=n*(a+b) && mx>=n*(a+b)) || (n*(a-b)>=mn && n*(a-b)<=mx) || (mn>=n*(a-b)&&mx<=n*(a+b))){
            cout<<"Yes"<<nl;
        }
        else cout<<"No"<<nl;
    }
}