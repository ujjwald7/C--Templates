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

const int maxm = 3*1e4+5 , sz = 1e6+5;
int freq[sz] = {0};
int a[maxm],n,cnt=0,block = sqrt(maxm);

void add(int x)
{
	freq[x]++;
	if(freq[x]==1) cnt++;
}

void reduce(int x)
{
	freq[x]--;
	if(freq[x]==0) cnt--;
}

bool comp(vector<int>q1,vector<int>q2)
{
	int id1 = q1[0] / block;
	int id2 = q2[0] / block;
	if(id1!=id2){
		return id1 < id2;
	}
	return q1[1] < q2[1];
}

void solve()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int q; cin>>q;
	vector<vector<int>>query(q,vector<int>(3));
	for(int i=0;i<q;i++)
	{
		cin>>query[i][0]>>query[i][1];
		query[i][0]--;
		query[i][1]--;
		query[i][2] = i;
	}
	vector<int>ans(q);
	sort(query.begin(),query.end(),comp);
	int l=0,r=-1;
	for(int i=0;i<q;i++)
	{
		//extending range
		while(l>query[i][0]){
			l--;
			add(a[l]);
		}
		while(r<query[i][1]){
			r++;
			add(a[r]);
		}
		//reducing range
		while(l<query[i][0]){
			reduce(a[l]);
			l++;
		}
		while(r>query[i][1]){
			reduce(a[r]);
			r--;
		}
		ans[query[i][2]] = cnt;
	}
	for(auto x : ans) cout<<x<<endl;
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