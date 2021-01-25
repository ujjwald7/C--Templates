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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;
ld PI=2*acos(0.0);

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

//order slopes in increasing order - Max Hull
//order slopes in decreasing order - Min Hull

struct line{
    int m,b;
    //y=mx+b
};

ld intersectx(line X,line Y)
{
    //X.m*x+X.b==Y.m*x+Y.b
    //x=(Y.b-X.b)/(X.m-Y.m);
    if(X.m==Y.m) return 1e12;
    else
        return (ld)(Y.b-X.b)/(ld)(X.m-Y.m);
}

int evaluate(int pt,line X){
    return ((X.m*pt) + X.b);
}

deque<line>st;
vector<ld>points;

void addline(line X)
{
    if(st.empty()){
        st.pb(X);
        return;
    }
    if(st.size()==1){
        points.pb(intersectx(X,st.back()));
        st.pb(X);
        return;
    }
    while(points.size())
    {
        // l1 -> l2 ->X
        // if intersection of l1 and X lies before the intersection of 
        // l2 and l1 then l2 is an useless line, so we remove it
        line l2=st.back();
        st.pop_back();
        line l1=st.back();
        if(intersectx(X,l1) > points.back())
        {
            st.pb(l2);
            break;
        }
        else{
            points.pop_back();
        }
    }
    points.pb(intersectx(X,st.back()));
    st.pb(X);
}

int findbest(int x)
{
    int idx=lower_bound(points.begin(),points.end(),x) - points.begin();
    return evaluate(x,st[idx]);
}

void solve()
{               

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