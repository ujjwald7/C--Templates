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

double n,k;
vector<pair<double,double>>v;

double race(double time)
{
    double maxm=INT_MIN,minm=INT_MAX;
    for(int i=0;i<n;i++)
    {
        double pos=v[i].F*time+v[i].S;
        maxm=max(maxm,pos);
        minm=min(minm,pos);
    }
    return maxm-minm;
}

void solve()
{  
    cin>>n>>k;
    for(int i=0,x,d;i<n;i++){
        cin>>x>>d;
        v.pb(mp(x,d));
    }
    double r=k,l=0;
    double error=1e-9;
    while(r-l>error)
    {
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        double op1=race(m1),op2=race(m2);
        if(op1>op2) l=m1;
        else if(op2>op1) r=m2;
    }
    double ans=race(l);
    cout<<fixed<<setprecision(6)<<ans<<endl;
}  
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}