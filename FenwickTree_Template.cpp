const int maxm=200005;
int BIT[maxm],n;

void Update(int ind,int val)
{
    while(ind<=n)
    {
        BIT[ind]+=val;
        ind+=(ind&(-ind));
    }
}

void Update_Point(int ind,int val)
{
    Update(ind,val);
}

int Sum(int ind)
{
    int ans=0;
    while(ind>0){
        ans+=BIT[ind];
        ind-=(ind&(-ind));
    }
    return ans;
}


int Range_Sum(int l,int r)
{
    int ans=Sum(r)-Sum(l-1);
    return ans;
}