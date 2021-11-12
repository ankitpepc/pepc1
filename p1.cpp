#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 

unordered_map<int,bool> row,col,adiag,diag;

int fun(int n,int m,int idx,int tnq,int qpsf,string asf)
{
    // nqueens permutaions
    if(qpsf==tnq)
    {
        cout<<asf<<"\n";
        return 1;
    }
    int cnt=0;
    for(int i=idx;i<n*m;++i)
    {
        int r=i/m;
        int c=i%m;
        if(!row[r] and !col[c] and !adiag[r-c] and !diag[r+c] )
            {   
                row[r]  =col[c]  =adiag[r-c] = diag[r+c]=true;
                cnt+=fun(n,m,0,tnq,qpsf+1,asf +" ( "+to_string(r)+to_string(c)+" ) " );
                row[r]  =col[c]  =adiag[r-c] = diag[r+c]=false;
            }
    }
    return cnt;

}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n=4,m=4,tnq=4,qpsf=0,idx=0;
    int ans=fun(n,m,idx,tnq,qpsf,"");
    cout<<ans<<'\n';
    return 0;
}