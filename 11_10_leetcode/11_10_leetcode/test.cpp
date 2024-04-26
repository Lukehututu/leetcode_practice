#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
using namespace std;
#include<iostream>


#define MaxSize 10
//先定义一个栈用来存放左括号
typedef struct brastack
{
    char braket[MaxSize];
    int top;
}brastack;

//初始化
void Initstack(brastack* S)
{
    S->top = -1;
}

//入栈
void push(brastack* S, char e)
{
    S->top++;
    S->braket[S->top] = e;
}

//出栈
void pop(brastack* S)
{
    S->top--;
}


bool isValid(char* s)
{
    int i = 0;
    //先创建一个栈然后初始化
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
    //最后识别完了，如果栈空那就说明全都匹配上，即匹配成功。
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