#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
using namespace std;
#include<iostream>


#define MaxSize 10
//�ȶ���һ��ջ�������������
typedef struct brastack
{
    char braket[MaxSize];
    int top;
}brastack;

//��ʼ��
void Initstack(brastack* S)
{
    S->top = -1;
}

//��ջ
void push(brastack* S, char e)
{
    S->top++;
    S->braket[S->top] = e;
}

//��ջ
void pop(brastack* S)
{
    S->top--;
}


bool isValid(char* s)
{
    int i = 0;
    //�ȴ���һ��ջȻ���ʼ��
    brastack S;
    Initstack(&S);
    while (s[i])
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(&S, s[i]);
        else
        {
            if (S.top == -1)
                return false;
            if (S.top == -1)
                return false;
            if (s[i] == '(' && S.braket[S.top] != ')')
                return false;
            if (s[i] == '[' && S.braket[S.top] != ']')
                return false;
            if (s[i] == '{' && S.braket[S.top] != '}')
                return false;
            pop(&S);
        }
        i++;
    }
    //���ʶ�����ˣ����ջ���Ǿ�˵��ȫ��ƥ���ϣ���ƥ��ɹ���
    if (S.top == -1)
        return true;
    return false;
}


int main()
{
    char s[] = "{[]}";
    bool ret = isValid(s);
    cout << ret << endl;
}