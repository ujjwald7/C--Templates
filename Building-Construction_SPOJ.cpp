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
const int MOD=1e9+7;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

vector<int>height,cost;
int n;

int costed(double ht)
{
    int tot=0;
    for(int i=0;i<n;i++){
        tot=tot+((abs(ht-height[i]))*cost[i]);
    }
    return tot;
}

void solve()
{  
    height.clear();
    cost.clear();
    cin>>n;
    int maxm=INT_MIN,minm=INT_MAX;
    for(int i=0,x;i<n;i++){
        cin>>x;
        minm=min(minm,x);
        maxm=max(maxm,x);
        height.pb(x);
    }
    for(int i=0,x;i<n;i++){
        cin>>x;
        cost.pb(x);
    }
    double r=maxm,l=minm;
    while(r-l>1)
    {
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        int op1=costed(m1),op2=costed(m2);
        if(op1>op2) l=m1;
        else r=m2;
    }
    int ans=min(costed(floor(l)),costed(ceil(l)));
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
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}