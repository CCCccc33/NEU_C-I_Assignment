
#include <stdio.h>
char Get[100];
char *p = Get;
int NumberGet();
int Priority();
int Sym(int a, int b, char s);
int term();

int main()
{
    printf("请输入：");
    scanf("%s", Get);  // 读取输入
    printf("计算结果：");
    printf("%d", Priority());  // 输出计算结果
    return 0;
}

int NumberGet()
{
    int result = 0;
    if (*p == '(')
    {
        p++;
        result = Priority();  // 如果是括号，递归处理
        p++;  // 跳过 ')'
    }
    else
    {
        while (*p >= '0' && *p <= '9')  // 处理数字
        {
            result = result * 10 + (*p - '0');
            p++;
        }
    }
    return result;
}

int Priority()
{
    int result, right;
    char sym;
    result = term();  // 先处理乘法和除法
    while (*p == '+' || *p == '-')  // 处理加法和减法
    {
        sym = *p;
        p++;
        right = term();  // 处理右边的项
        result = Sym(result, right, sym);  // 计算结果
    }
    return result;
}

int Sym(int a, int b, char s)
{
    switch (s)
    {
    case '*': return a * b;
    case '/': return b ? a / b : 0;
    case '+': return a + b;
    case '-': return a - b;
    default: printf("Enter data error!\n"); return 0;
    }
}

int term()
{
    int result = 0, right;
    char sym;
    result = NumberGet();  // 获取一个数
    while (*p == '*' || *p == '/')  // 处理乘法和除法
    {
        sym = *p;
        p++;
        right = NumberGet();  // 获取右边的数字
        result = Sym(result, right, sym);  // 计算结果
    }
    return result;
}
