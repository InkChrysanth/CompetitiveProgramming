#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Node
{
    int a[10]={0};
}pw[10];
int cnt[10][10][10][10][10];
int n;

int main()
{
//    freopen("lock.in", "r", stdin);
//    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=5; j++)
            cin>>pw[i].a[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=5; j++)
            for(int k=0; k<=9; k++)
            {
                if(k==pw[i].a[j]) continue;
                int num[10]={0};
                memcpy(num, pw[i].a, sizeof num);
                num[j]=k;
                cnt[num[1]][num[2]][num[3]][num[4]][num[5]]++;
            }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=4; j++)
        {
            int num[10]={0};
            memcpy(num, pw[i].a, sizeof num);
            for(int k=1; k<=9; k++)
            {
                num[j]=num[j]+1==10 ? 0 : num[j]+1;
                num[j+1]=num[j+1]+1==10 ? 0 : num[j+1]+1;
                cnt[num[1]][num[2]][num[3]][num[4]][num[5]]++;
            }
        }
    int ans=0;
    for(int aa=0; aa<=9; aa++)
        for(int bb=0; bb<=9; bb++)
            for(int cc=0; cc<=9; cc++)
                for(int dd=0; dd<=9; dd++)
                    for(int ee=0; ee<=9; ee++)
                        if(cnt[aa][bb][cc][dd][ee]==n)
                            ans++;
    cout<<ans<<endl;
    return 0;
}