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

const int maxm = 1e5+5;
vector<vector<int>>tree(maxm),vec(maxm);
vector<int>freq(maxm,0),ff(maxm,0);
vector<int>a(maxm);
vector<int>sizes(maxm,0);
vector<int>ans(maxm);
int n;

void dfs_precalc(int src,int par)
{
	sizes[src] = 1;
	for(auto edge : tree[src]){
		if(edge!=par){
			dfs_precalc(edge,src);
			sizes[src] += sizes[edge];
		}
	}
}

void update(int &mx,int src,int x)
{
	ff[freq[a[src]]] -= a[src];
	freq[a[src]]+=x;
	ff[freq[a[src]]] += a[src];
	mx = max(mx,freq[a[src]]);
}

int dfs(int src,int par,bool keep)		//keep = false - > smol child, keep=1 - > big child
{
	int val=-1,bigchild = -1;
	for(auto edge : tree[src]){
		if(edge!=par and sizes[edge] > val)
		{
			bigchild = edge;
			val = sizes[edge];
		}
	}

	int mx = -1;		// mx stores answer for src vertex 
	for(auto edge : tree[src])
	{
		if(edge!=par and edge!=bigchild){
			dfs(edge,src,0);
		}
	}

	if(bigchild!=-1)
	{
		mx = max(mx,dfs(bigchild,src,1));
		swap(vec[src],vec[bigchild]);  //O(1) time
	}

	vec[src].pb(src);
	update(mx,src,1);

	for(auto edge : tree[src])
	{
		if(edge!=par and edge!=bigchild)
		{
			for(auto x: vec[edge]){
				update(mx,x,1);
				vec[src].pb(x);
			}
		}
	}
	ans[src] = ff[mx];
	// db(src,ans[src],ff[mx],mx);
	if(keep==0){		//erase smol kids
		for(auto x : vec[src]){
			update(mx,x,-1);
		}
	}

	return mx;
}
 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		int x,y; cin>>x>>y;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	dfs_precalc(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;i++){
		// cout<<sizes[i]<<endl;
		cout<<ans[i]<<" ";
	}
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
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
 
// 1LL check ?