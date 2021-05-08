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
        //DEBUG(tc);
        ll n,l,r;cin>>n>>l>>r;
        ll add=2*n-2,cnt=0,h=1;
        while(add!=0&&cnt+add<l){
            cnt+=add;
            add-=2;
            h++;
        }
        //DEBUG(add);
        //DEBUG(n);
        if (add==0){
            cout<<1<<nl;
            continue;
        }
        ll diff=l-cnt;
        bool f=(diff%2)==1; // odd: print out first number, even: print out trailing num
        ll st=(diff-1)/2+h+1;
        rep(i,0,r-l+1){
            //DEBUG('h');
            if (f){
                cout<<h<<' ';
            }
            else{
                cout<<st<<' ';
                if (st==n){
                    h++;st=h+1;
                    if (h==n && i!=r-l){
                        cout<<1;break;
                    }
                }
                else st++;
            }
            f=!f;
        }
        cout<<nl;
    }
}