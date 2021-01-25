#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define mp make_pair
#define endl "\n"
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1e9+7 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void solve()
{	
	int n,m; cin>>n>>m;
	int a[n][m];
	bool ok=false;
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]>0) ok=true;
			ans=max(ans,a[i][j]);
		}
	}
	if(!ok){
		cout<<ans<<endl;
		return;
	}
	ans=INT_MIN;
	V<int>r_sum;
	int l=0,r=m-1;
	while(l<=r){
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=l;j<=r;j++){
				sum+=a[i][j];
			}
			r_sum.pb(sum);
		}
		int csum=0,tot=0;
		for(int i=0;i<r_sum.size();i++){
			csum+=r_sum[i];
			if(csum<0) csum=0;
			tot=max(tot,csum);
		}
		ans=max(ans,tot);
		r_sum.clear();
		l++; 
		r--;	
	}
	cout<<ans<<endl;
}    
	
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}