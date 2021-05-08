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
void upgrade(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);}

int main(){
    upgrade();
    int n;cin>>n;
    int a[100002];
    a[0]=0;
    rep(i,1,n+1){
        cin>>a[i];
    }
    a[n+1]=0;
    int ans=-INT_MAX;
    int cnt=1;
    int prev=0;
    rep(i,1,n+2){
        if (a[i]==a[i-1]){
            cnt++;
        }
        else{
            ans=max(ans,min(prev,cnt));
            prev=cnt;
            cnt=1;
        }
    }
    cout<<2*ans<<nl;
}