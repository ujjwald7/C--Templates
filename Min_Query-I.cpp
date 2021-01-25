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
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void build_tree(int *tree,int *a,int index,int s,int e)
{
    if(s>e) return;
    if(s==e){
        tree[index]=a[s];
        return;
    }
    int mid=(s+e)/2;
    build_tree(tree,a,2*index,s,mid);
    build_tree(tree,a,2*index+1,mid+1,e);
    int left,right;
    left=tree[2*index];
    right=tree[2*index+1];
    tree[index]=min(left,right);
}

int query(int *tree,int index,int s,int e,int l,int r)
{
    if(r<s || l>e) return INT_MAX;
    if(s>=l && e<=r) return tree[index];
    int mid=(s+e)/2;
    int op1=query(tree,2*index,s,mid,l,r);
    int op2=query(tree,2*index+1,mid+1,e,l,r);
    return min(op1,op2);
}

void update(int *tree,int index,int x,int y,int s,int e)
{
    if(x<s || x>e) return;
    if(s==e){
        tree[index]=y;
        return;
    }
    int mid=(s+e)/2;
    update(tree,2*index,x,y,s,mid);
    update(tree,2*index+1,x,y,mid+1,e);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

void solve()
{
    int n,q; cin>>n>>q;
    int tree[4*n+1],a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    build_tree(tree,a,1,0,n-1);
    while(q--){
        int ch; cin>>ch;
        if(ch==1){
            int l,r; cin>>l>>r;
            cout<<query(tree,1,0,n-1,l-1,r-1)<<endl;
        }
        else{
            int x,y; cin>>x>>y;
            update(tree,1,x-1,y,0,n-1);
        }
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