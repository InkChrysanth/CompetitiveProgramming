/*
两个元素都在左边；
两个元素都在右边；
两个元素一个在左一个在右；
计算逆序对的数量（序列）：
1. 递归算左边的；
2. 递归算右边的；
3. 算一个左一个右的；
4. 把他们加到一起。
*/
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
long long res=0; //保存逆序对数量 

int a[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if(l>=r) return ;
    int mid=l+r>>1;
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid && j<=r)
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else {
        	tmp[k++]=q[j++];
        	res+=mid-i+1;//逆序对数量 
		}
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    cout<<res<<endl;

    return 0;
}

