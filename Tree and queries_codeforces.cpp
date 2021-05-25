#include<bits/stdc++.h>
using namespace std;
// #define int long long int
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
int a[maxm],freq[maxm]={0};
int n;
vector<vector<int>>tree;
int cnt = 0,timer = 1;
int enter[maxm],leave[maxm],flat_tree[2*maxm],ffreq[maxm]={0};
int vis[maxm]={0},prefs[maxm]={0};
int blocks = 600;

void dfs(int src,int par)
{
	enter[src] = timer;
	flat_tree[timer] = src;
	timer++;
	for(auto edge : tree[src])
	{
		if(edge!=par){
			dfs(edge,src);
		}
	}
	leave[src] = timer;
	flat_tree[timer] = src;
	timer++;
}

int checker_id(int x){
	return (x + blocks - 1) / blocks;
}

bool comp(vector<int>q1,vector<int>q2)
{
	int id1 = enter[q1[0]] / blocks;
	int id2 = enter[q2[0]] / blocks;
	if(id1!=id2){
		return id1 < id2;
	}
	if(id1&1)
		return leave[q1[0]] < leave[q2[0]];
	else
		return leave[q1[0]] > leave[q2[0]];
}

void add(int x)
{
	vis[x]++;
	if(vis[x]==2)	//lies in subtree
	{	
		freq[a[x]]++;
		ffreq[freq[a[x]]]++;
		prefs[checker_id(freq[a[x]])]++;
		ffreq[freq[a[x]]-1]--;
		prefs[checker_id(freq[a[x]]-1)]--;
	}
}

void reduce(int x)
{
	vis[x]--;
	if(vis[x]==1)
	{
		freq[a[x]]--;
		ffreq[freq[a[x]]]++;
		prefs[checker_id(freq[a[x]])]++;
		ffreq[freq[a[x]]+1]--;
		prefs[checker_id(freq[a[x]]+1)]--;
	}
}

int dp_checker(int ind)
{
	int lb = checker_id(ind);
	int rb = checker_id(n);
	int ans = 0;
	if(lb==rb){
		for(int i=ind;i<=n;i++){
			ans += ffreq[i];
		}
	}
	else
	{
		for(int i=ind;i<=blocks*lb;i++){
			ans += ffreq[i];
		}
		for(int i=lb+1;i<rb;i++){
			ans += prefs[i];
		}
		for(int i=rb*blocks+1;i<=n;i++){
			ans += ffreq[i];
		}
	}
	return ans;
}

void solve()
{	
	int q;
	cin>>n>>q;
	tree.resize(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++){
		int x,y; cin>>x>>y;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	dfs(1,0);
	vector<vector<int>>query(q+1,vector<int>(3));
	for(int i=1;i<=q;i++){
		cin>>query[i][0]>>query[i][1];
		query[i][2] = i;
	}
	// for(int i=0;i<timer;i++) cout<<flat_tree[i]<<" ";
	// cout<<endl;
	sort(query.begin() + 1,query.end(),comp);
	int l=1,r=0;
	vector<int>ans(q+1);
	for(int i=1;i<=q;i++)
	{
		// db(query[i][2]); 
		// new_k = 2*query[i][1];
		// cnt = 0;
		//reduction
		while(l < enter[query[i][0]]){
			reduce(flat_tree[l]);
			l++;
		}
		while(r > leave[query[i][0]]){
			reduce(flat_tree[r]);
			r--;
		}
		//expansion
		while(l > enter[query[i][0]]){
			l--;
			add(flat_tree[l]);
		}
		while(r < leave[query[i][0]]){
			r++;
			add(flat_tree[r]);
		}
		// db(l,r,query[i][2],enter[query[i][0]],leave[query[i][0]]);
		// for(int i=1;i<=3;i++) cout<<freq[i]<<" ";
		// cout<<endl;
		// for(int j=query[i][1];j<=n;j++){
		// 	cnt += ffreq[j];
		// }
		ans[query[i][2]] = dp_checker(query[i][1]);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
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