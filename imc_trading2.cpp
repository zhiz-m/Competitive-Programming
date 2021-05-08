#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=b-1;i>=a;i--)
#define nl '\n'

const int N=300300, M=300;
int n,q,v[N],p[N][M];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin>>n;
    rep(i,1,n+1)cin>>v[i];
    cin>>q;
    rep(i,1,M){
        per(j,1,n+1){/*
            int prev;
            if (j+i>n)prev=0;
            else prev=p[j+i][i];*/
            if (p[j+i][i]>v[j])p[j][i]=p[j+i][i];
            else p[j][i]=v[j];

            //p[j][i]=max(v[j],p[j+i][i]);
        }
    }
    rep(i,0,q){
        int x,y;cin>>x>>y;
        int suc=0;
        if (y<M){
            int b=p[x][y];
            cout<<(b>v[x]?"YES":"NO")<<nl;
            continue;
        }
        for(int j=x+y; j<=n; j+=y){
            if (v[j]>v[x]){
                cout<<"YES"<<nl;
                suc=1;
                break;
            }
        }
        if (!suc)cout<<"NO"<<nl;
    }
}