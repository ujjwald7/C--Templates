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

int dp[11][11][11][11];

int checker(int ind,int x1,int x2,int x3)
{
    if(ind==-1){
        if(x1==0 and x2==0 and x3==0) return 0;
        else return -1e8;
    }
    if(dp[ind][x1][x2][x3]!=-1) return dp[ind][x1][x2][x3];

    int ret=checker(ind-1,x1,x2,x3);
    if(x1) ret=max(ret,(1<<ind) + checker(ind-1,x1-1,x2,x3));
    if(x2) ret=max(ret,(1<<ind) + checker(ind-1,x1,x2-1,x3));
    if(x3) ret=max(ret,(1<<ind) + checker(ind-1,x1,x2,x3-1));
    if(x1 and x2) ret=max(ret,checker(ind-1,x1-1,x2-1,x3));
    if(x1 and x3) ret=max(ret,checker(ind-1,x1-1,x2,x3-1));
    if(x2 and x3) ret=max(ret,checker(ind-1,x1,x2-1,x3-1));
    if(x1 and x2 and x3) ret=max(ret,(1<<ind) + checker(ind-1,x1-1,x2-1,x3-1));

    return dp[ind][x1][x2][x3]=ret;
}

void solve()
{               
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int x1=0,x2=0,x3=0;
    for(auto x:s1) if(x=='1') x1++;
    for(auto x:s2) if(x=='1') x2++;
    for(auto x:s3) if(x=='1') x3++;
    // memset(dp,0,sizeof dp);
    for(int i=0;i<11;i++){
        {
            for(int j=0;j<11;j++)
            {
                for(int k=0;k<11;k++)
                {
                    for(int l=0;l<11;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
    }
    int ans=checker(9,x1,x2,x3);
    // db(ans);
    string num;
    while(ans){
        if(ans&1) num+='1';
        else num+='0';
        ans>>=1;
    }        
    reverse(num.begin(),num.end());
    cout<<num<<endl;
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
    // sieve();
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}