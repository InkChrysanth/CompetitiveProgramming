#include<iostream>
#include<cstdio> 
#include<string> 
using namespace std; 
#define MAXN 100 
#define INF 100000000 
int g[MAXN][MAXN]; 
int n, len; 
int ans = INF; 
string s; 
void read() 
{ 
    int i, j; 
    cin >> s >> n; 
    len = s.size(); 
    for(i=1; i<=len; i++) 
        g[i][i] = s[i-1] - '0'; 
    for(i=1; i < len; i++) 
        for(j=i+1; j <= len; j++) 
        { 
            g[i][j] = g[i][j-1] * 10 + g[j][j]; 
            if(g[i][j] > INF) 
                g[i][j] = INF; 
        } 
} 
//��������iλ����һ���Ӻ���lastλ�ã��Ѿ�����p���Ӻţ����ֺ�Ϊsum 
void dfs(int i, int last, int p, int sum)   
{ 
    if(sum + g[last+1][i] > n) return;  
    if(sum + g[last+1][len] < n) return; 
          
      
    if(p > ans) return; 
          
      
    if(i == len)  //�߽� 
    { 
        sum += g[last+1][len]; 
        if(sum == n) 
            if(p < ans) 
                ans = p; 
        return ; 
    } 
    //iλ�ò��żӷ� 
    dfs(i+1, last, p, sum); 
       
    //iλ�÷żӷ� 
    int j = g[last+1][i]; 
    dfs(i+1, i, p+1, sum+j); 
} 
int main() 
{ 
    freopen("quicksum.in","r",stdin);
	freopen("quicksum.out","w",stdout);
	read(); 
    dfs(1, 0, 0, 0); 
    if(ans ==INF) 
        cout << -1; 
    else
        cout << ans << endl; 
} 
