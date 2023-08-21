/*
851spfaÇó×î¶ÌÂ· 
3 3
1 2 5
2 3 -3
1 3 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int>q;
    q.push(1);
    st[1]=true;
    while(q.size()){
    	int t=q.front();
    	q.pop();
    	st[t]=false;
    	for(int i=h[t];i!=-1;i=ne[i]){
    		int j=e[i];
    		if(dist[j]>dist[t]+w[i]) {
    			dist[j]=dist[t]+w[i];
    			if(!st[j]){
    				q.push(j);
    			st[j]=true;
				} 
			}    		
		}
	}
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    spfa();
    if(dist[n]>0x3f3f3f3f/2) cout<<"impossible"<<endl;
    else cout<<dist[n]<<endl;

    return 0;
}


