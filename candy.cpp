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
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        if (n%4!=0){
            cout<<"NO"<<nl;
            continue;
        }
        cout<<"YES"<<nl;
        int cur=4;
        rep(i,0,n/2){
            cout<<cur<<' ';
            cur+=2;
        }
        cur=3;
        rep(i,0,n/4){
            cout<<cur<<' ';
            cur+=2;
        }
        cur += 2;
        rep(i,0,n/4){
            cout<<cur<<' ';
            cur+=2;
        }
        cout<<nl;
    }
}