#include <bits/stdc++.h>

using namespace std;

int n, c[200001], a[200001], d[200001], bk=INT_MAX, l[200001],cnt=0;

//int factors[200001]={};

//int f_done[200001]={};
vector<int> fcts[200001]={};
vector<int> v;

/*
int get_factors(int num){
	//if (num<0)return -1;
	//fill_n(factors,n+1,0);
	
	if (f_done[num]){
		v=fcts[num];
		return 1;
	}
	v.clear();
	int r = sqrt(num);
	for (int i=1;i<=r;i++){
		if (num%i==0){
			//fcts[num].push_back(i);
			//fcts[num].push_back(num/i);
			//if (i < 0 || num/i < 0) cout << "hi";
			
			//factors[i]=1;
			//factors[num/i]=1;
			v.push_back(i);
			v.push_back(num/i);
		}
	}
	sort(v.begin(),v.end());
	fcts[num]=v;
	f_done[num]=1;
	return 1;
}

int next_factor(int num, int cur=0){
	for (int i=cur+1;i<=num;i++){
		if (num%i==0)
			return i;
	}
	return -1;
}
*/
void p_cycle(int node, int len){
	//int f=get_factors(len);
	int start=node;
	//for (int i=1;i<200001;i++){ if (factors[i]==1) cout << i << " ";}
	//cout << len << " ";
	//cout << '\n';
	//while (f < bk && f<=len)
	for (int f : fcts[len])
	{
		for (int i=0;i<f;i++){
			node = start;
			int done=1;
			/*
			for (int j=0;j<i;j++){
				node=a[node];
			}
			*/
			int color=c[v[i]];
			int w=len/f;
			//cout << "hi" << w;
			for (int j=i;j<len;j+=f){
				if (c[v[j]]!=color){
					done=0;break;
				}
			}
			if (done) {
				bk = min(bk,f);
				//cout << bk;
			}
			//cout << "hi";
		}
	}
}

void dfs(int cur){
	d[cur]=1;
	v.push_back(cur);
	cnt++;
	if (!d[a[cur]]){
		l[cur]=cnt;
		dfs(a[cur]);
	}
	else{
		p_cycle(cur, cnt-l[cur]);
		v.clear();
	}
	cnt--;
	//l[cur]=cnt;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for (int i=1;i<200001;i++){
		for (int j=i;j<200001;j+=i){
			fcts[j].push_back(i);
		}
	}
	int t; cin >> t;
	while(t--){
		bk=INT_MAX;
		cnt=0;
		cin >> n;
		fill_n(d,n+1,0);
		fill_n(l,n+1,0);
		//fill_n(a,n+1,0);
		//fill_n(c,n+1,0);
		for (int i=1;i<=n;i++){
			cin >> a[i];
		}
		for (int i=1;i<=n;i++){
			cin >> c[i];
		}
		for (int i=1;i<=n;i++){
			if (d[i]==0)
				dfs(i);
		}
		cout << bk <<'\n';
	}
}