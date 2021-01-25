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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007  //10^9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif                                  //file end
    int n;
    cin>>n;
    int a,b,c;
    if(n==1||n==0){
        a=-1;
        cout<<a<<endl;
        return 0;
    }
    if(n%2==0)
    {
        a=((n*n)/4)-1;
        b=n;
        c=((n*n)/4)+1;     
    }
    else
    {
        a=(((n+1)*(n+1))/4)-(((n-1)*(n-1))/4);
        c=a=(((n+1)*(n+1))/4)+(((n-1)*(n-1))/4);
        b=((n+1)*(n-1))/2;
    }
    if(a==n)
    {
        cout<<min(b,c)<<" "<<max(b,c)<<endl;
    }
    else if(b==n)
    {
        cout<<min(a,c)<<" "<<max(a,c)<<endl;
    }
    else
        cout<<min(a,b)<<" "<<max(a,b)<<endl;
    return 0;
}  
