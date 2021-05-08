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
#define upgrade ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;	
typedef long long ll;

VI prefix_function(string s){ // returns lps[], where lps[i] is the longest integer j<i such that lps[0,1...j-1] = lps[i-j+1...i]
    VI lps(SZ(s),0);
    rep(i,1,SZ(s)){
        int j=lps[i-1];
        while (j>0 && s[i]!=s[j])
            j=lps[j-1];
        if (s[i]==s[j]) j++;
        lps[i]=j;
    }
    return lps;
}

void solve(){
    string t;cin>>t;
    int n=SZ(t),p=0,opp=n-1;
    while (opp-p>0&&t[p]==t[opp]){
        p++;
        opp=n-p-1;
    }
    //DEBUG(p);
    //DEBUG(opp);
    if (opp-p<=0){
        cout<<t<<nl;
        return;
    }
    int mx1,mx2;
    string st=t.substr(p,opp-p+1);
    string rt=st;
    reverse(all(rt));
    mx1=prefix_function(st+'$'+rt)[2*SZ(st)];
    mx2=prefix_function(rt+'$'+st)[2*SZ(st)];
    //DEBUG('h');
    if (mx1>=mx2){
        cout<<t.substr(0,p)<<st.substr(0,mx1)<<t.substr(opp+1,n-opp-1)<<nl;
    }
    else{
        //DEBUG(mx2);
        //DEBUG(rt);
        cout<<t.substr(0,p)<<rt.substr(0,mx2)<<t.substr(opp+1,n-opp-1)<<nl;
    }
}

int main(){
    upgrade;
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
}