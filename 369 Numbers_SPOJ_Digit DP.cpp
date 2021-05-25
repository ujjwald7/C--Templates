#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(x) x.begin(), x.end()
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;
const int MOD2=998244353;
ld PI=2*acos(0.0);

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

string a,b; 
int dp[51][2][2][36][36][2];

int checker(int pos,int tig1,int tig2,int diff1,int diff2,int ok)
{
	if(diff1 >= 17 or diff2>=17 or diff1<=-17 or diff2<=-17) return 0;
	if(pos>=a.length()){
		return (diff1==0 and (diff1==diff2) and ok);
	}
	if(dp[pos][tig1][tig2][diff1][diff2][ok]!=-1) return dp[pos][tig1][tig2][diff1][diff2][ok];
	int ans = 0;
	int st=0,en=9;
	if(tig1){
		st = a[pos]-'0';
	}
	if(tig2){
		en = b[pos]-'0';
	}
	for(int i=st;i<=en;i++)
	{
		int new_d1=diff1;
		int new_d2=diff2;
		if(i==3) new_d1++;
		if(i==6) new_d1--,new_d2++;
		if(i==9) new_d2--;
		ans = (ans + checker(pos+1,tig1&(i==st),tig2&(i==en),new_d1,new_d2,ok|(i==3))%MOD)%MOD;
	}
	return dp[pos][tig1][tig2][diff1][diff2][ok] = ans%MOD;
}


void solve()
{
	cin>>a>>b;
	memset(dp,-1,sizeof dp);
	while(a.length()!=51) a = '0' + a;
	while(b.length()!=51) b = '0' + b;
	int ans = checker(0,1,1,0,0,0);
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
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}

// 1LL check ?