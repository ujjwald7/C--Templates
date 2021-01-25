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
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
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

struct point{
    int x,y;
    //overloading comparison operator for sort function
    bool operator < (point &R){
        if(R.x==x) return y<R.y;
        return x<R.x;
    }
    //overloading unique operator
    bool operator == (point &R){
        return(x==R.x and y==R.y);
    }
};

bool right_turn(point a,point b,point c){   //upper half
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool left_turn(point a,point b,point c){   //lower-half
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool collinear(point a,point b,point c){
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}

void convex_hull(vector<point>&p)
{
    if(p.size()<=2) return;
    sort(p.begin(),p.end());        //overloaded comparison
    /// now p[0] is p1, and p[n-1] is p2
    int i,n=p.size();
    point p1=p[0],p2=p[n-1];
    //p1=bottom-right
    //p2=top-right
    vector<point>up,down;
    up.pb(p1);
    down.pb(p1);
    for(int i=1;i<n;i++)
    {
        //check turns and collinear
        //check upper half or lower half
        if(i==n-1 || !left_turn(p1,p[i],p2)){
             while(up.size()>=2 && left_turn(up[up.size()-2],up[up.size()-1],p[i]))
             {
                up.pop_back();
             }
             up.pb(p[i]);
        }
        //lower half
        if(i==n-1 || !right_turn(p1,p[i],p2)){
            while(down.size()>=2 && right_turn(down[down.size()-2],down[down.size()-1],p[i]))
             {
                down.pop_back();
             }
             down.pb(p[i]);
        }
    }
    //up and down are set with p1 and p2 present in both
    p.clear();
    for(i=0;i<up.size();i++){
        p.pb(up[i]);
    }
    for(i=0;i<down.size();i++){
        p.pb(down[i]);
    }
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end())-p.begin()); //operator overloaded
}

void solve()
{
    int n; cin>>n;
    vector<point>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    // convex_hull(p);
    //now p contains all convex hull points
    int m; cin>>m;
    map<pair<int,int>,bool>vis;
    for(int i=0;i<m;i++){
        point temp;
        cin>>temp.x>>temp.y;
        p.pb(temp);
        vis[{temp.x,temp.y}]=true;
    }
    // db(m);
    convex_hull(p);
    for(auto x:p){
        // cout<<x.x<<" "<<x.y<<endl;
        if(vis[{x.x,x.y}]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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