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
#define MOD 1000000007  //1e9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<string,int>>v;
    string s;
    for(int i=0,x;i<n;i++)
    {
        cin>>s>>x;
        v.pb(mp(s,x));
    }
    int counting_sort[n+1]={0};
    for(int i=0;i<n;i++)
    {
        counting_sort[v[i].S]++;
    }
    //Greedy Approach
    int ans=0;
    int actual_rank=1;
    for(int i=1;i<=n;i++)
    {
        while(counting_sort[i])
        {
            ans+=abs(actual_rank-i);
            actual_rank++;
            counting_sort[i]--;
        }
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
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}