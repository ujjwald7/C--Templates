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

void multiply(int *a,int &n,int no)
{
    int carry = 0;
    for(int i=0;i<n;i++)
    {
        int product = a[i]*no +carry;
        a[i]=product%10;
        carry=product/10;
    }
    while(carry)
    {
        a[n]=carry%10;
        carry=carry/10;
        n++;
    }
}

void big_factorial(int number)
{
    int *a = new int[10000]{0};
    a[0]=1;
    int n=1;
    for(int i=2;i<=number;i++){
        multiply(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif                                  //file end
    int num;
    cin>>num;
    big_factorial(num);
    return 0;
}  
