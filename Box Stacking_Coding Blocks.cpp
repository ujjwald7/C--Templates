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
ld pi=2*acos(0.0);

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

int dp[105][3];

struct box{
    int l,b,h;
    box(){};
    box(int h,int b,int l){
        this->l=l;
        this->b=b;
        this->h=h;
    }
};

int checker(vector<box>v,int prev_box,int orient)
{
    if(dp[prev_box][orient]!=0) return dp[prev_box][orient];
    int ans=0;
    int prev_l,prev_b,prev_h;
    if(orient==0){                                      //l*b
        prev_l=v[prev_box].l;
        prev_b=v[prev_box].b;
        prev_h=v[prev_box].h;
    }
    else if(orient==1)
    {                                                   //l*h        
        prev_l=v[prev_box].l;
        prev_b=v[prev_box].h;
        prev_h=v[prev_box].b;
    }
    else
    {                                                  //b*h
        prev_l=v[prev_box].b;
        prev_b=v[prev_box].h;
        prev_h=v[prev_box].l;
    }
    for(int i=1;i<v.size();i++)
    {
        //check for all 3 orientations
        if((v[i].l < prev_l and v[i].b < prev_b) or (v[i].b < prev_l and v[i].l < prev_b))
        {
            ans=max(ans,v[i].h+checker(v,i,0));
        }
        if((v[i].l < prev_l and v[i].h < prev_b) or (v[i].h < prev_l and v[i].l < prev_b))
        {
            ans=max(ans,v[i].b+checker(v,i,1));
        }
        if((v[i].h < prev_l and v[i].b < prev_b) or (v[i].b < prev_l and v[i].h < prev_b))
        {
            ans=max(ans,v[i].l+checker(v,i,2));
        }
    }
    return dp[prev_box][orient] = ans;
}

void solve()
{       
    int n; cin>>n;
    vector<box>v(n+1);
    v[0]={100000000,100000000,100000000};
    for(int i=1;i<=n;i++){
        cin>>v[i].h>>v[i].b>>v[i].l;
    }
    memset(dp,0,sizeof dp);
    cout<<checker(v,0,0)<<endl;
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
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}