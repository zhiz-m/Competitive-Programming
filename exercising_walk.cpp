#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
	int x,y,x1,x2,y1,y2,a,b,c,d;
	int t;cin>>t;
	while (t--){
		cin >> a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
		if (a==b && a>0&& x==x1 && x1==x2)
			puts("NO");
		else if (c==d && c>0 && y==y1 && y1==y2)
			puts("NO");
		else if (x1<=x+b-a && x2>=x+b-a && y1<=y+d-c && y2>=y+d-c)
			puts("YES");
		else
			puts("NO");
	}
}