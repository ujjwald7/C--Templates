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

double dist(double x,double y,double p,double q)
{
    double opx=p-x;
    double opy=q-y;
    double ans=opx*opx+opy*opy;
    return sqrt(ans);
}

double new_x(double x1,double y1,double x2,double y2,double v1,double v2,double x)
{
    double d1=dist(x1,y1,x,0);
    double d2=dist(x,0,x2,y2);
    return d1/v1+d2/v2;
}

void solve()
{  
    double x1,y1,x2,y2,v1,v2; 
    cin>>x1>>y1>>x2>>y2>>v1>>v2;
    double r=max(x1,x2),l=min(x1,x2);
    double err=1e-6;
    while(r-l>err)
    {
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        double op1=new_x(x1,y1,x2,y2,v1,v2,m1),op2=new_x(x1,y1,x2,y2,v1,v2,m2);
        if(op1<op2) r=m2;
        else l=m1;
    }
    double ans=new_x(x1,y1,x2,y2,v1,v2,r);
    cout<<fixed<<setprecision(5)<<ans<<endl;
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