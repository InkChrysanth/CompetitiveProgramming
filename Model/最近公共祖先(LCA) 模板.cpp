void bfs()
{
    queue<int> q;
    q.push(1); depth[1]=1;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=h[t]; ~i; i=ne[i])
        {
            int j=e[i];
            if(depth[j]) continue;
            depth[j]=depth[t]+1;
            fa[j][0]=t;
            q.push(j);
            for(int k=1; k<=18; k++)
                fa[j][k]=fa[fa[j][k-1]][k-1];
        }
    }
}
int lca(int a, int b)
{
    if(depth[a]<depth[b]) swap(a, b);
    for(int k=18; k>=0; k--)
        if(depth[fa[a][k]]>=depth[b])
            a=fa[a][k];
    if(a==b) return a;
    for(int k=18; k>=0; k--)
    {
        if(fa[a][k]!=fa[b][k])
        {
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}
