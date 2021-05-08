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
    int n;cin>>n;
    string sa,sc;
    cin>>sa>>sc;
    int ma=0,mb=0,mc=0,md=0;
    rep(i,0,n){
        if (sa[i]=='0'){
            if (sc[i]=='1')mc++;
            else ma++;
        }
        else{
            if (sc[i]=='1')md++;
            else mb++;
        }
    }
    //DEBUG(ma);
    //DEBUG(mb);
    //DEBUG(mc);
    //DEBUG(md);
    bool suc=0;
    int a,b,c,d;
    rep(i,0,n/2+1){
        a=i,d=a-n/2+mc+md;
        if(a<0||d<0)continue;
        if (a<=ma&&d<=md&&a-d==n/2-mc-md){
            //DEBUG('h');
            if (mb+mc>=n/2-a-d){
                b=min(mb,n/2-a-d);
                c=n/2-a-d-b;
                if (b<0||c<0)continue;
                suc=1;
                //DEBUG(a);
        //DEBUG(b);
       // DEBUG(c);
        //DEBUG(d);
                break;
            }
        }
    }
    if(!suc)cout<<-1<<nl;
    else{
    rep(i,0,n){
        if (sa[i]=='0'){
            if (sc[i]=='1'){
                if (c>0){
                    cout<<i+1<<' ';
                    c--;
                }
            }
            else if (a>0){
                    cout<<i+1<<' ';
                    a--;
                }
        }
        else{
            if (sc[i]=='1'){
                if (d>0){
                    cout<<i+1<<' ';
                    d--;
                }
            }
            else if (b>0){
                    cout<<i+1<<' ';
                    b--;
                }
        }
    }}
    cout<<nl;
}