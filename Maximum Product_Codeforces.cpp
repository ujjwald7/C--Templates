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

pair<int,string> dp[20][2][2][2];
string a,b; 

pair<int,string> checker(int pos,int ta,int tb,int lead)
{
    if(pos==a.size()) return {1,""};
    if(dp[pos][ta][tb][lead].F!=-1) return dp[pos][ta][tb][lead];
    string ans="";
    int ret=-1;
    int st=0,en=9;
    if(ta) st=a[pos]-'0';
    if(tb) en=b[pos]-'0';   
    for(int i=st;i<=en;i++)
    {
        int val;
        if(lead==0 and i==0)
            val=1;
        else
            val=i;
        pair<int,string>dpans=checker(pos+1,ta&(i==st),tb&(i==en),lead|(i>0));
        if(val*dpans.F>ret){
            ret=val*dpans.F;
            if(lead==0 and i==0) 
                ans=dpans.S;
            else{
                char ch=i+'0';
                ans=ch+dpans.S;
            }
        }
    }
    return dp[pos][ta][tb][lead]={ret,ans};
}

void solve()
{
    cin>>a>>b;
    for(int i=0;i<20;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++) dp[i][j][k][l].F=-1;
            }
        }
    }
    // db(a,b);
    while(a.size()!=b.size()) a='0'+a;
    cout<<checker(0,1,1,0).S<<endl;
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