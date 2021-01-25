//0-based indexing

const int maxm=1e5+2;
int n;
int a[maxm],tabs[maxm][17];
int log_tabs[maxm+1];

void sparse()
{
    for(int i=0;i<n;i++) tabs[i][0]=a[i];
    for(int j=1;j<=17;j++){
        for(int i=0;i+(1<<j)<=n;i++)
            tabs[i][j]  = min(tabs[i][j-1],tabs[i+(1<<(j-1))][j-1]);
    }

    // log_tabs table 
    log_tabs[1] = 0;
    for (int i = 2; i <=maxm; i++)
        log_tabs[i] = log_tabs[i/2] + 1;
}

int query(int l,int r)
{
    int k=log_tabs[r-l+1];
    int ans=min(tabs[l][k],tabs[r-(1<<k)+1][k]);
    return ans;
}