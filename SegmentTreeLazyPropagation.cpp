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
#define MOD 1000000007  //1e9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int lazy[1000]={0};

void BuildSegmentTree(int *a,int s,int e,int *tree,int index)
{
    if(s==e){
        tree[index]=a[s];
        return;
    }
    int mid=(s+e)/2;
    //Rec Case
    BuildSegmentTree(a,s,mid,tree,2*index);     //i stores 2i and 2i+1 
    BuildSegmentTree(a,mid+1,e,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

int query(int *tree,int ss,int se,int qs,int qe,int index)
{
    //Complete Overlap
    if(ss>=qs&&se<=qe)
    {
        return tree[index];
    }
    //No Overlap
    if(qe<ss||qs>se){
        return INT_MAX;
    }
    //Partial Overlap
    int mid=(ss+se)/2;
    int LeftAns=query(tree,ss,mid,qs,qe,2*index);
    int RightAns=query(tree,mid+1,se,qs,qe,2*index+1);
    int ans=min(RightAns,LeftAns);
    return ans;
}

void UpdateNode(int *tree,int ss,int se,int i,int increment,int index)
{
    //No Overlap
    if(i>se||i<ss){
        return;
    }
    //Base-Node Found
    if(ss==se){
        tree[index]+=increment;
        return;
    }
    //D and C
    int mid=(ss+se)/2;
    UpdateNode(tree,ss,mid,i,increment,2*index);        //left call
    UpdateNode(tree,mid+1,se,i,increment,2*index+1);    //right call
    //now going up 
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

void UpdateRange(int *tree,int ss,int se,int l,int r,int increment,int index)
{
    //No Overlap
    if(l>se||r<ss)
    {
        return;
    }
    //Leaf Node Reached
    if(ss==se)
    {
        tree[index]+=increment;
        return;
    }
    //else use divide and conquer
    int mid=(ss+se)/2;
    UpdateRange(tree,ss,mid,l,r,increment,2*index);     //left call
    UpdateRange(tree,mid+1,se,l,r,increment,2*index+1); //right call
    //Bottom Up
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

void UpdateRangeLazy(int *tree,int ss,int se,int l,int r,int increment,int index)
{
    //First step- Never go down if you have lazy value at node, first resolve it
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        //if not a leaf node
        if(ss!=se){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;  //resolve karliya upar se
    }
    //Out of bounds i.e. no overlap
    if(ss>r||l>se){
        return;
    }
    //Complete Overlap
    if(ss>=l&&se<=r)
    {
        tree[index]+=increment;
        //Pass the lazy value to children
        if(ss!=se){
            lazy[2*index]+=increment;
            lazy[2*index+1]+=increment;
        }
        return;
    }

    //Call on left and right
    int mid=(ss+se)/2;
    UpdateRangeLazy(tree,ss,mid,l,r,increment,2*index);
    UpdateRangeLazy(tree,mid+1,se,l,r,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

int querylazy(int *tree,int ss,int se,int qs,int qe,int index)
{
    //First-step - resolve the lazy value
    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(ss!=se){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index]+=lazy[index];
        }
        lazy[index]=0;
    }
    //No Overlap
    if(qe<ss||qs>se){
        return INT_MAX;
    }
    //Complete Overlap
    if(ss>=qs&&se<=qe)
    {
        //lazy has already been resolved
        return tree[index];
    }
    //Partial Overlap
    int mid=(ss+se)/2;
    int LeftAns=querylazy(tree,ss,mid,qs,qe,2*index);
    int RightAns=querylazy(tree,mid+1,se,qs,qe,2*index+1);
    int ans=min(RightAns,LeftAns);
    return ans;
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
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int *tree=new int[4*n+1];
    BuildSegmentTree(a,0,n-1,tree,1);
    for(int i=1;i<=13;i++){
        //cout<<tree[i]<<" ";
    }
    int l,r;
    cin>>l>>r;
    cout<<query(tree,0,n-1,l,r,1)<<endl;
    UpdateNode(tree,0,n-1,3,2,1);       //add 2 to the 3rd node
    UpdateRange(tree,0,n-1,2,4,100,1);  //add 100 to range 2-4 index's
    for(int i=1;i<=13;i++){
        cout<<tree[i]<<" ";
    }
    return 0;
}