#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define MOD 1000000000
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE					//filed
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif									//file end
	unsigned int n;
	cin>>n;
	vector<unsigned int>v;
	if(n>=130){
		cout<<"Yes";
		return 0;
	}
	for(int i=0;i<n;i++){
		unsigned int num;
		cin>>num;
		v.pb(num);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int l=k+1;l<n;l++){
					if((v[i]^v[j]^v[k]^v[l])==0){
						cout<<"Yes";
						return 0;
					}
				}
			}
		}
	}
	cout<<"No";
	return 0;
}
