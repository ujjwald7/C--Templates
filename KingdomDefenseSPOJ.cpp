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
    int w,h,n;
    cin>>w>>h>>n;
    vector<int>x;
    vector<int>y;
    if(n==0){
        cout<<w*h<<endl;
        return;
    }
    for(int i=0,f,g;i<n;i++)
    {
        cin>>f>>g;
        x.pb(f);
        y.pb(g);
    }
    sort(x.begin(),x.end());        
    sort(y.begin(),y.end());
    int max_x=INT_MIN,max_y=INT_MIN;
    //Greedy Approach
    for(int i=1;i<n;i++)     
    {
        max_x=max(max_x,x[i]-x[i-1]-1);
        max_y=max(max_y,y[i]-y[i-1]-1);
    }
    //Corner Cases
    max_x=max(max_x,x[0]-1);        //origin
    max_y=max(max_y,y[0]-1);
    max_x=max(max_x,w-x[n-1]);        //corner
    max_y=max(max_y,h-y[n-1]);
    int ans=max_x*max_y;
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