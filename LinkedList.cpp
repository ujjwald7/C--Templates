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

class node{
  public:   
    int data;
    node *next;
    //Constructor
    node(int d){
        data=d;
        next=NULL;
    }
};

void insertAtHead(node *&head,int data){        //pass head by reference so that no copy is created
    node *n=new node(data);
    n->next=head;
    head=n;
}

void printlist(node *&head){
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int leng(node *&head)
{
    int cnt=0;
    node *temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void insertAtTail(node *&head,int data)
{
    if(head==NULL){
        insertAtHead(head,data);
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *n=new node(data);
    temp->next=n;
    n->next=NULL;
}

void insertInMiddle(node *&head,int pos,int data)
{
    if(head==NULL||pos==0){
        insertAtHead(head,data);
    }
    else if(pos>leng(head)){
        insertAtTail(head,data);
    }
    else{
        node *temp=head;
        node *n=new node(data);
        while((pos-1)>0)
        {
            temp=temp->next;
            pos--;
        }
        n->next=temp->next;
        temp->next=n;
    }    
}

void deleteAtHead(node *&head)
{
    if(head==NULL)
        return;
    node *temp=head;
    head=head->next;
    delete temp;
}

void deleteAtTail(node *&head)
{
    node *temp=head;
    node *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
}

void deleteInMiddle(node *&head,int pos)
{
    if(pos==0){
        deleteAtHead(head);
        return;
    }
    if(pos==leng(head)){
        deleteAtTail(head);
    }
    node *temp=head;
    node *prev=NULL;
    while((pos-1)>0){
        pos--;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}

bool SearchRecursive(node *head,int element)
{
    if(head==NULL)
        return false;
    if(head->data==element)
        return true;
    return SearchRecursive(head->next,element);
}

void buildList(node *&head)
{
    int data;
    cin>>data;
    while(data!=-1){       
        insertAtTail(head,data);
        cin>>data;
    }
}

void ReverseList(node *&head)
{
    node *current=head;
    node *prev=NULL;
    node *nex=NULL;
    while(current!=NULL){
        nex=current->next;
        current->next=prev;
        prev=current;
        current=nex;
    }
    head=prev;
}

node* reverseRecursive(node*head)
{
    if(head==NULL||head->next==NULL)
        return head;
    node *smallhead=reverseRecursive(head->next);
    node *cur=head;
    cur->next->next=cur;
    cur->next=NULL;
    return smallhead;
}

node* MidPointRunnerTechnique(node*head)
{
    if(head==NULL||head->next==NULL)
        return head;
    node* slowptr=head;
    node* fastptr=head->next;
    while(fastptr!=NULL&&fastptr->next!=NULL)
    {
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }
    return slowptr;
}

node* KthNodeFromEndUsingRunnerTechnqiue(node* head,int k)
{
    node* slowptr=head;
    node* fastptr=head;
    while(k--)
        fastptr=fastptr->next;
    while(fastptr!=NULL)
    {
        slowptr=slowptr->next;
        fastptr=fastptr->next;
    }
    return slowptr;
}

node* merge(node* a,node* b)
{
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    node* c;
    if(a->data<b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

node* MergeSort(node* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    node* mid=MidPointRunnerTechnique(head);
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;
    //Recursive Case
    a=MergeSort(a);
    b=MergeSort(b);
    node* c;
    c=merge(a,b);
    return c;
}

bool DetectCycle(node* head)
{
    node* fastptr=head;
    node* slowptr=head;
    while(fastptr!=NULL&&fastptr->next!=NULL)
    {
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
        if(fastptr==slowptr){
            return true;
        }
    }
    return false;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    node *head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertInMiddle(head,1,10);
    insertInMiddle(head,2,20);
    insertAtTail(head,40); 
    //buildList(head);
    //ReverseList(head);
    head=reverseRecursive(head);
    printlist(head);
    node* m=MidPointRunnerTechnique(head);
    cout<<m->data<<endl;
    node* f=KthNodeFromEndUsingRunnerTechnqiue(head,5);
    cout<<f->data<<endl;
    node *r=MergeSort(head);
    printlist(r);
    return 0;
}