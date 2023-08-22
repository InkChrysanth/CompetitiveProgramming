#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101, mod=1e9+7;
struct matrix
{
    LL a[N][N];
    inline matrix(){memset(a, 0, sizeof a);}
    inline matrix operator +(const matrix &T)const
    {
        matrix res;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                res.a[i][j]=(a[i][j]+T.a[i][j])%mod;
        return res;
    }
    inline matrix operator -(const matrix &T)const
    {
        matrix res;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                res.a[i][j]=(a[i][j]-T.a[i][j])%mod;
        return res;
    }
    inline matrix operator *(const matrix &T)const
    {
        matrix res;
        for(int i=0; i<N; i++)
            for(int k=0; k<N; k++)
                for(int j=0; j<N; j++)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*T.a[k][j])%mod;
        return res;
    }
    inline matrix operator ^(LL x)const
    {
        matrix res, base;
        for(int i=0; i<N; i++)
            res.a[i][i]=1;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                base.a[i][j]=a[i][j]%mod;
        while(x)
        {
            if(x&1) res=res*base;
            base=base*base;
            x>>=1;
        }
        return res;
    }
};
int main()
{
    matrix A, B, ans;
    return 0;
}
