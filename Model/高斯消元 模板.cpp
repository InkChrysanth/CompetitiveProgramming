int gauss()// 1 无数组解 2 无解
{
    int c, r;
    for(c=0, r=0; c<n; c++)// r 行 c 列 
    {
        int t=r;
        for(int i=r; i<n; i++)
            if(fabs(a[i][c])>fabs(a[t][c]))
                t=i;
        if(fabs(a[t][c])<eps) continue;//最大的一行
        swap(a[t], a[r]);
        for(int i=n; i>=c; i--)
            a[r][i]/=a[r][c];
        for(int i=r+1; i<n; i++)
        {
            if(fabs(a[i][c])<eps) continue;
            for(int j=n; j>=c; j--)
                a[i][j]-=a[r][j]*a[i][c];
        }
        r++;
    }
    if(r<n)
    {
        for(int i=r; i<n; i++)
            if(fabs(a[i][n])>eps)
                return 2;
        return 1;
    }
    for(int i=n-1; i>=0; i--)
        for(int j=i+1; j<n; j++)
            a[i][n]-=a[i][j]*a[j][n];
    return 0;
}