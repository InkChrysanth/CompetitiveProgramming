#include <cstdio>
#include <cstring>
using namespace std;
char st[100];
int main() {
    scanf("%s", st);
    int n = strlen(st);
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) { //因子 
            char c = st[i - 1];
            if (c >= 'a') //转化为大写字母 
                st[i - 1] = c - 'a' + 'A';
        }
    }
    printf("%s", st);
    return 0;
}
/*
判断题： 
1.输入的字符串只能由小写字母或大写字母组成。（ false）
2.若将第8行的“i = 1”改为“i = 0”，程序运行时会发生错误。（true）
3.若将第8行的“i <= n”改为“i * i <= n”，程序运行结果不会改变。（false）
4.若输入的字符串全部由大写字母组成，那么输出的字符串就跟输入的字符串一样。（true）
选择题:
5. 若输入的字符串长度为18,那么输入的字符串跟输出的字符串相比，至多有（6）个字符不同。
//其实就是求因子个数 
若输入的字符串长度为（A），那么输入的字符串跟输出的字符串相比，至多有36个字符不同。
A.36 B.100000 C.1 D.128
*/	
