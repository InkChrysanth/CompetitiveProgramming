/*
852.spfa判断负环 
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
int dist[N],cnt[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
int spfa()
{
//    memset(dist,0x3f,sizeof dist);
    queue<int>q;
    for(int i=1;i<=n;i++){ //所有边存入队列 
    	st[i]=true;q.push(i);
	}    
    while(q.size()){
    	int t=q.front();
    	q.pop();
    	st[t]=false;
    	for(int i=h[t];i!=-1;i=ne[i]){
    		int j=e[i];
    		if(dist[j]>dist[t]+w[i]) {
    			dist[j]=dist[t]+w[i];
    			cnt[j]=cnt[t]+1; //累计边数 
    			if(cnt[j]>=n) return true; //出现负环的条件 
    			if(!st[j]){
    				q.push(j);
    			st[j]=true;
				} 
			}    		
		}
	}
    return false;
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
    if(spfa()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;    
    return 0;
}


