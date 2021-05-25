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

const int maxm = 1e5+5;		//maximum number of nodes
set<int> graph[maxm];
vector<int>parent(maxm,0);
vector<int>subtree(maxm,0);
vector<int>res(maxm,1e9);
int n; //number of nodes

//------------------------------------Decomposition Starts Here--------------------------///

int dfs1(int node,int par)
{
	subtree[node] = 1;
	for(auto edge : graph[node])
	{
		if(edge!=par){
			subtree[node] += dfs1(edge,node);
		}
	}
	return subtree[node];
}

int dfs(int node,int par,int sz)
{
	for(auto edge : graph[node])
	{
		if(edge!=par and subtree[edge] > sz/2)
		{
			return dfs(edge,node,sz);
		}
	}
	return node;
}


void centroid_decomposition(int node,int par)
{
	int subsize = dfs1(node,-1);

	int centroid = dfs(node,par,subsize);

	// cout<<"tree rooted at "<<node<<" with size "<<subsize<<" has centroid "<<centroid<<endl;

	parent[centroid] = par;

	for(auto edge : graph[centroid]){
		graph[edge].erase(centroid);
		centroid_decomposition(edge,centroid);
	}
}

//-------------Decomposition Ends Here-----------------------------//

//dist(a , b) : returns the distance between node in LogN using LCA
//we are assuming parent of root of centroid tree is -1
 
void update(int node)				
{
	int curr = node;
	while(curr != -1)
	{
		res[curr] = min(res[curr] , dist(curr , node));		
		//dist is distance between 2 nodes using dfs for initial distances
		//dist[a]+dist[b]-2*dist[lca(a,b)] // add lca using binary-lifting
		curr = parent[curr];
	}
}
 
int query(int node)
{
	int curr = node;
	int ans = 1e9;
	while(curr != -1)
	{
		ans = min(ans , res[curr] + dist(node , curr));
		//dist is distance between 2 nodes using dfs for initial distances
		//dist[a]+dist[b]-2*dist[lca(a,b)] // add lca using binary-lifting
		curr = parent[curr];
	}
 
	return ans;
}

void solve()
{
	centroid_decomposition(1,-1);
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