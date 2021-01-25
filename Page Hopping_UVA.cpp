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
    int t=1;
    while(1)
    {
        int a,b;
        set<int>uni;
        int floyd[101][101];
        bool flag=false;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                floyd[i][j]=INT_MAX;
            }
        }
        int maxm=-1;
        while(cin>>a>>b)
        {
            if(a==0 and b==0) break;
            flag=true;
            floyd[a][b]=1;
            uni.insert(a);
            uni.insert(b);
            maxm=max(maxm,max(a,b));
        }
        if(!flag) return;
        for(int k=1;k<=maxm;k++){
            for(int i=1;i<=maxm;i++){
                for(int j=1;j<=maxm;j++){
                    if(uni.count(i) and uni.count(j) and uni.count(k)){
                        floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
                    }
                }
            }
        }
        int r=uni.size();
        float ans=0,pairs=r*(r-1);
        for(int i=1;i<=maxm;i++){
            for(int j=1;j<=maxm;j++){
                if(i==j) continue;
                if(uni.count(i) and uni.count(j)) ans+=floyd[i][j];
            }
        }
        // db(ans);
        ans/=pairs;
        cout<<"Case "<<t<<": average length between pages = ";
        cout<<fixed<<setprecision(3)<<ans;
        cout<<" clicks"<<endl;
        t++;
    }
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