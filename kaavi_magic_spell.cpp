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

const int MOD=998244353;
vector<VI> dp(3005,VI(3005,-1));
int n,m;
string s,t;

int recur(int i,int j){ //recursion after S[i] has been placed between A[j...i+j]. Considering placement of i+1
    if (dp[i][j]!=-1) return dp[i][j];
    if (j==0 && i>=m-1) return dp[i][j]=n-i; 
    if (i+j>=n) return 0;
    int ans=0;
    if (j>0&&j<=m&&s[i+1]==t[j-1])ans=(ans+recur(i+1,j-1))%MOD;
    if (j==m) {
        ans=(ans+(2*recur(i+1,j))%MOD)%MOD;
    }
    else if (i+j>=m-1){
        ans=(ans+recur(i+1,j))%MOD;
    }
    if (i+j+1<m&&s[i+1]==t[i+j+1])ans=(ans+recur(i+1,j))%MOD;
    //else if (i+j+1<n&&i+j+1>=m) ans=(ans+recur(i+1,j))%MOD;
    //DEBUG(ans);
    return dp[i][j]=ans;
}

int main(){
    cin>>s>>t;
    n=SZ(s),m=SZ(t);
    int ans=0;
    rep(j,0,min(n,m+1)){
        //recur(0,j);
        //DEBUG(dp[0][j]);
        if (j==m||s[0]==t[j])ans=(ans+recur(0,j))%MOD;
    }/*
    rep(i,m,n+1){
        //DEBUG(recur(i,0));
        if (dp[i][0]!=-1)
        ans=(ans+recur(i,0))%MOD;
    }*/
    cout<<(2*ans)%MOD<<nl;
}