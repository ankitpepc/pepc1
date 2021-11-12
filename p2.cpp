#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 

bool issafe(vector<vector<bool>> &v1,int r ,int c)
{
    vector<int> dx={0,-1,-1,-1,0,1,1,1};
    vector<int> dy={-1,-1,0,1,1,1,0,-1};
    for(int i=0;i<dx.size();++i)
    {
        int cr=r;
        int cc=c;
        while(cr>=0 and cc>=0 and cr<v1.size() and cc<v1[0].size())
        {
            if(v1[cr][cc]) return false;
            cr+=dx[i];
            cc+=dy[i];
        }
    }
    return true;
}

int fun(vector<vector<bool>> &v1,int idx,int tnq,int qpsf,string asf)
{
    // nqueens permutaions -> non optimised
    if(qpsf==tnq)
    {
        cout<<asf<<"\n";
        return 1;
    }
    int cnt=0;
    int n=v1.size(),m=v1[0].size();
    for(int i=idx;i<n*m;++i)
    {
        int r=i/m;
        int c=i%m;
        if(issafe(v1,r,c) )
            {   
                v1[r][c]=true;
                cnt+=fun(v1,0,tnq,qpsf+1,asf +" ( "+to_string(r)+to_string(c)+" ) " );
                v1[r][c]=false;
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
    vector<vector<bool>> v1(n,vector<bool>(m,false));
    int ans=fun(v1,idx,tnq,qpsf,"");
    cout<<ans<<'\n';
    return 0;
}