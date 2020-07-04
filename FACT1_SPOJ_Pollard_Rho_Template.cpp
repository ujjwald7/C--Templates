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

__int128 in()
{
    __int128 temp=0;
    string s;
    cin>>s;
    for(char c:s)
    {
        temp*=10;
        temp+=(c-'0');
    }
    return temp;
}

void out(__int128 x)
{
    stack<char>s;
    while(x)
    {
        s.push((x%10 +'0'));
        x/=10;
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}

__int128 fun(__int128 a, __int128 b, __int128 mod)
{
    return (a*a+b)%mod+1;
}

__int128 pollard_rho(__int128 num, __int128 comp)
{
    if(num==1) return 1;
    if(num%2 == 0) return 2;

    srand(time(0));
    __int128 y=rand()%num+1,c=rand()%num+1, x, gcd=1, sq=sqrt(num)+100;
    x=y;

    int count=0;

    while(gcd==1)
    {
        if(count >= sq) return num;
        count++;
        x=fun(x, c, num);
        y=fun( fun(y, c, num), c, num );
        if(x==y) gcd=num;
        else    gcd=__gcd(abs(x-y), num);
        if(gcd!=1)
        {
            if(gcd==num || gcd==comp)
            {
                y=rand()%num+1;
                x=y;
                gcd=1;
            }
            else
            {
                break;
            }
        }  
    }

    return gcd;
}

__int128 modexp(__int128 base, __int128 power, __int128 mod=1000000007)
{
    __int128 res=1;
    while(power)
    {
        if(power&1) res=(res*base)%mod;
        power>>=1;
        base=(base*base)%mod;
    }
    return res;
}


bool miller_rabin(__int128 num, __int128 k)
{
    __int128 s=0,d=num-1,one=1,temp;
    while(!(d&1)) d>>=1,s++;

    bool flag=true;
    temp=modexp(k,d,num);
    if(temp==1 || temp==num-1) return 1;
    for(int i=0;i<s;i++)
    {
        temp=(temp*temp)%num;
        if(temp==1) return 0;
        if(temp==num-1) return 1;
    }
    return 0;
}

bool prime(__int128 num)
{
    vector<int>A{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
    for(auto x:A) if(x==num) return 1;
    if(!(num&1)) return 0;

    bool flag=true;
    for(auto x:A) flag&=miller_rabin(num, x);
    return flag;
}

void solve()
{
    __int128 n; 
    while(n=in()){
        if(n==0) return;
        map<int,int>factors;
        while(n!=1){
            __int128 y=pollard_rho(n,0);
            int cnt=1;
            while(!prime(y)) y=pollard_rho(y,y);
            n/=y;
            while(n%y==0){
                n/=y;
                cnt++;
            }
            factors[y]=cnt;
        }
        for(auto x : factors){
            cout<<x.F<<"^"<<x.S<<" ";
        }
        cout<<endl;
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
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}