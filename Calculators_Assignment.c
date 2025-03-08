
#include <stdio.h>
char Get[100];
char *p = Get;
int NumberGet();
int Priority();
int Sym(int a, int b, char s);
int term();

int main()
{
    printf("�����룺");
    scanf("%s", Get);  // ��ȡ����
    printf("��������");
    printf("%d", Priority());  // ���������
    return 0;
}

int NumberGet()
{
    int result = 0;
    if (*p == '(')
    {
        p++;
        result = Priority();  // ��������ţ��ݹ鴦��
        p++;  // ���� ')'
    }
    else
    {
        while (*p >= '0' && *p <= '9')  // ��������
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
    result = term();  // �ȴ���˷��ͳ���
    while (*p == '+' || *p == '-')  // ����ӷ��ͼ���
    {
        sym = *p;
        p++;
        right = term();  // �����ұߵ���
        result = Sym(result, right, sym);  // ������
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
    result = NumberGet();  // ��ȡһ����
    while (*p == '*' || *p == '/')  // ����˷��ͳ���
    {
        sym = *p;
        p++;
        right = NumberGet();  // ��ȡ�ұߵ�����
        result = Sym(result, right, sym);  // ������
    }
    return result;
}
