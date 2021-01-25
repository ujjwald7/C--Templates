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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void solve()
{   
    int n,q; cin>>n>>q;
    int a[n];
    int dp[n+1]={0};
    for(int i=0;i<n;i++) cin>>a[i];
    while(q--)
    {
        int d; cin>>d;
        if(dp[d]!=0){
            cout<<dp[d]<<endl;
            continue;
        }
        int ans=INT_MAX;
        deque<int>q;
        int i;
        for(i=0;i<d;i++)
        {
            while(!q.empty() and a[i]>a[q.back()]) q.pop_back();
            q.pb(i);
        }
        ans=min(ans,a[q.front()]);
        for( ;i<n;i++)
        {
            while(!q.empty() and q.front()<=i-d) q.pop_front();
            while(!q.empty() and a[i]>a[q.back()]) q.pop_back();
            q.pb(i);
            ans=min(ans,a[q.front()]);
        }
        dp[d]=ans;
        cout<<ans<<endl;
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
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
