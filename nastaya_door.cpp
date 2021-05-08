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
    VI v;
    VI peak;
    VI pref;
    while(tc--){
        int n,k;cin>>n>>k;
        v.assign(n+1,0);
        peak.assign(n+1,0);
        pref.assign(n+1,0);
        rep(i,1,n+1)cin>>v[i];
        rep(i,2,n){
            if (v[i-1]<v[i]&&v[i]>v[i+1])peak[i]=1;
            //DEBUG(i);
            //DEBUG(peak[i]);
        }
        rep (i,1,n+1){
            pref[i]=pref[i-1]+peak[i];
        }
        int mx=INT_MIN;
        int best;
        rep(i,2,n-k+3){
            int temp=pref[i+k-3]-pref[i-1];
            //DEBUG(temp);
            if (temp>mx){
                best=i-1; // i+1
                mx=temp;
            }   
        }
        cout<<mx+1<<' '<<best<<nl;
    }
}