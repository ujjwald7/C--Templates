class node{
public:
    char data;
    unordered_map<char,node*>hash;
    bool isTerminal;
    //constructor
    node(char d){
        data=d;
        isTerminal=false;
    }
};

class trie{
    node* root;
public:
    trie(){
        root=new node('\0');
    }
    //Insertion
    void addword(string word)
    {
        node* temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];
            if(temp->hash.count(ch)==0){
                node* child=new node(ch);
                temp->hash[ch]=child;
                temp=child;
            }
            else{
                temp=temp->hash[ch];
            }
        }
        temp->isTerminal=true;
    }
    //Lookup
    bool search(string word)
    {
        node* temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];
            if(temp->hash.count(ch)){
                temp=temp->hash[ch];
            }
            else{
                return false;
            }
        }
        return temp->isTerminal;
    }
};