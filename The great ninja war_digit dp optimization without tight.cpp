#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #define ld long double
// #define F first
// #define S second
// #define P pair<int,int>
// #define V vector
// #define eb emplace_back
// #define pb push_back
// #define mp make_pair
#define endl "\n"
// #define all(x) x.begin(), x.end()
// #define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// // #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 
// #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
// const int MOD=1e9+7;
// const int MOD2=998244353;
// ld PI=2*acos(0.0);

// template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
// template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
// template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
// template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}

// template <typename Arg1>
// void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
// template <typename Arg1, typename... Args>
// void __f(const char* names, Arg1&& arg1, Args&&... args) {
//     const char* comma = strchr(names + 1, ',');
//     cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
// }

const int mask = (1<<9) + 2;
int dp[13][mask][2522];
// bool used[13][2][mask][2525];		//2520 = lcm(1,........9)
string s;
vector<int>powers(10,0);

void precompute()
{
	powers[0]=0;
	for(int i=1;i<=9;i++){
		powers[i] = exp(i,i);
	}
}

int checker(int pos,int tig,int mask,int sum)
{
	if(pos >= s.length()){
		bool ok = true;
		for(int i=1;i<=9;i++){
			if(mask&(1<<(i-1))){
				// c++;
				if((sum%i)!=0){
					// p++;
					ok=false;
				}
			}
		}
		return ok;
	}
	if(!tig and dp[pos][mask][sum]!=-1) return dp[pos][mask][sum];
	// used[pos][tig][mask][sum] = true;
	int ans = 0;
	int en = 9;
	if(tig){
		en = s[pos]-'0';
	}
	for(int i=0;i<=en;i++){
		int smol = 0;
		if(i!=0){
			smol = powers[i];
		}
		int new_sum = (sum+smol)%2520;
		int new_mask = mask;
		if(i){
			new_mask = new_mask|(1<<(i-1));
		}
		ans += checker(pos+1,tig&(i==en),new_mask,new_sum);
	}
	if(!tig)
		dp[pos][mask][sum] = ans;
	return ans;
}

void solve()
{
	int a,b; cin>>a>>b;
	memset(dp,-1,sizeof dp);
	// memset(used,false,sizeof used);
	s = tostring(b);
	int ans = checker(0,1,0,0);
	memset(dp,-1,sizeof dp);
	// memset(used,false,sizeof used);
	a--;
	s = tostring(a);
	ans -= checker(0,1,0,0);
	// db(ans);
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
    // int cases=1;
    precompute();
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}

// 1LL check ?