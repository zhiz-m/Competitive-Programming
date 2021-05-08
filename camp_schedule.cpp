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

VI prefix_function(string s){ // returns lps[], where lps[i] is the longest integer j<i such that lps[0,1...j] = lps[i-j+1...i]
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

int main(){
    upgrade();
    string s,t;cin>>s>>t;
    int mx=prefix_function(t)[SZ(t)-1];
    int cnt1=0,cnt2=0;
    rep(i,0,SZ(s)){
        if (s[i]-'0'==1) cnt2++;
        else cnt1++;
    }
    int t1=0,t2=0;
    rep(i,0,SZ(t)){
        if (t[i]-'0'==1) {cnt2--;}
        else cnt1--;
    }
    rep(i,mx,SZ(t)){
        if (t[i]-'0'==1) t2++;
        else t1++;
    }
    int ans=1;
    if (t1==0)ans+=cnt2/t2;
    else if (t2==0)ans+=cnt1/t1;
    else ans+=min(cnt2/t2,cnt1/t1);
    if (cnt2<0||cnt1<0)cout<<s<<nl;
    else{
        cout<<t;
        rep(i,1,ans)rep(j,mx,SZ(t))cout<<t[j];
        rep(i,0,cnt2-(ans-1)*t2)cout<<'1';
        rep(i,0,cnt1-(ans-1)*t1)cout<<'0';
        cout<<nl;
    }
}