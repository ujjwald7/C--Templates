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
    string s; cin>>s;
    map<int,int>lens;
    stack<int>q;
    vector<int>d(s.length(),-1);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('){
            q.push(i);
        }
        else{
            if(!q.empty()){
                int top=q.top();
                q.pop();
                d[i]=top;
                if(top>0 and d[top-1]!=-1) d[i]=d[top-1];
            }
        }
    }
    for(int i=0;i<s.length();i++)
    {
        // db(d[i]);
        if(d[i]!=-1) lens[i-d[i]+1]++;
    }
    if(lens.empty()){
        cout<<"0 1"<<endl;
        return;
    }
    auto it=lens.rbegin();
    cout<<it->F<<" "<<it->S<<endl;
}  
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
