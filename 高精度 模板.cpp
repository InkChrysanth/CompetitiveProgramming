#include<bits/stdc++.h>
using namespace std;
vector<int>A,B,C,D,E;
int cmp(vector<int>a,vector<int>b) { //比较a,b的大小 
    if(a.size()<b.size()) return -1;
    if(a.size()>b.size()) return 1;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]<b[i]) return -1;
        if(a[i]>b[i]) return 1;
    }
    return 0;
}
bool check(vector<int>a){ //判断奇偶 
    if(a[0]%2==0) return 0;
    return 1;
}
vector<int> operator+(vector<int> a,vector<int> b) //重定义高精度+ 
{
    if(cmp(a,b)==-1) swap(a,b);  
    vector<int>res;
    int t=0;
    for(int i=0;i<a.size(); i++)
    {
        t+=a[i];
        if(i<b.size()) t+=b[i];
        res.push_back(t%10);
        t/=10;
    }
    if(t) res.push_back(t);
    return res;
}
vector<int> operator-(vector<int>a,vector<int>b){ //重定义高精度 - 
    vector<int>res;
    for(int i=0,t=0;i<a.size();i++){
        t=a[i]-t;
        if(i<b.size()) t-=b[i];//模拟减
        res.push_back((t+10)%10) ;//t<0的时候向后借位，t>0的时候直接% 
        if(t<0) t=1;
        else t=0;
    }
    while(res.size()>1 && res.back()==0) res.pop_back();//去掉前导0 
    return res;
}
vector<int>operator *(vector<int>a,int b){ //重定义高精度 * int 
    vector<int>res;
    int t=0;
    for(int i=0;i<a.size() ||t!=0;i++){
        if(i<a.size())t+=a[i]*b;
        res.push_back(t%10);
        t/=10;
    }
    return res;
}
vector<int>operator * (vector<int>a,vector<int>b){ //重定义&为高精度 * 高精度 
    vector<int> res(a.size()+b.size()); //必须先确定大小 
    int t=0,w,f;//t为进位 
    for(int i=0;i<a.size();i++) 
        for(int j=0;j<b.size();j++){
            f=a[i]*b[j];t=f/10,f%=10;
            w=i+j;
            res[w]+=f;
            res[w+1]+=t+res[w]/10;
            res[w]%=10;
        }
    while(res.size() && res.back()==0) res.pop_back();
    return res;
}
vector<int>operator/(vector<int>a,int b){ //高精度/int 
    vector<int>res;
    int r=0;
    bool st=true;//st=true代表一次除法都没执行过
    for(int i=a.size()-1;i>=0;i--){ //从最高位开始算 
        r=r*10+a[i];
        if(r>=b || !st){ //避免前导0，第一次等到r大于b以后才开始除 
            res.push_back(r/b);
            r=r%b;
            st=false;
        }   
    }
    if(st) res.push_back(0);//特殊情况a<b结果为0 
    reverse(res.begin(),res.end()); //翻转，让高位在后 
    return res;
}
vector<int>operator/(vector<int>a,vector<int> b){ //高精度/高精度 
    int len=a.size()-b.size()+1; //商的最大位数 
    vector<int>res(len);
    vector<int>aa(a); //复制a到aa 
    for(int i=len-1;i>=0;i--){
        vector<int>tmp(i,0);//前面填充0  
        for(int j=0;j<b.size();++j) tmp.push_back(b[j]);//复制到后面 
        while(cmp(aa,tmp)>=0){ //模拟减 
            res[i]++;
            aa=aa-tmp;
        }
    }
    while(res.size()>0 && res.back()==0) res.pop_back(); //去前导0 
    return res;
}

vector<int>gcd(vector<int>a,vector<int>b){  //求高精度最大公约数 
    if(cmp(a,b)==-1)swap(a,b);
    if(a.size()==0)return b;
    if(b.size()==0)return a;
    while(cmp(a,b)!=0)
    {
        if((check(a)==0) && (check(b)==0)) return gcd(a/2,b/2)*2;
        if((check(a)==1) && (check(b)==0)) return gcd(a,b/2);
        if((check(a)==0) && (check(b)==1)) return gcd(a/2,b);
        if((check(a)==1) && (check(b)==1)) return gcd(b,(a-b));
    }
    return b;
}

int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');//反向存，低位在前高位在后 
    while(A.size() && A.back()==0) A.pop_back(); //去前导0 
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    while(B.size() && B.back()==0) B.pop_back();
    bool flag=1;
    if(cmp(A,B)==-1) {
        swap(A,B);
        flag=-1;
    }
    C=gcd(A,B);//最大公约数 
    for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    printf("\n");
    vector<int>ans;
    ans=(A*B)/C; //最小公倍数 
    for(int i=ans.size()-1;i>=0;i--) printf("%d",ans[i]);
    printf("\n");
    return 0;
}
