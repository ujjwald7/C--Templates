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

void solve()
{
    string a,b,c; cin>>a>>b>>c;
    int n1=a.length(),n2=b.length(),n3=c.length();
    int dp[n1+1][n2+1][n3+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++)
            {
                if(a[i-1]==b[j-1] and b[j-1]==c[k-1]){
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else{
                    int op1,op2,op3;
                    op1=dp[i-1][j][k];
                    op2=dp[i][j-1][k];
                    op3=dp[i][j][k-1];
                    dp[i][j][k]=max(dp[i][j][k],max(op1,max(op2,op3)));
                }
            }
        }
    } 
    cout<<dp[n1][n2][n3]<<endl;
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