#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

int main()
{
    stack<char> s;
    int n, i;
    char c;
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++)
    {
        while ((c = getchar()) != '\n')
        {
            if (c == '(' || c == '[')
                 s.push(c);
            else if(c == ')')
            {
                if (s.empty() == true)
                    s.push(c);
                else if (s.top() == '(')
                    s.pop();
                else
                    s.push(c);
            }
            else
            {
                if (s.empty() == true)
                    s.push(c);
                else if(s.top() == '[')
                    s.pop();
                else
                    s.push(c);
            }
        }
        if (s.empty() == true)
            printf("Yes\n");
        else
        {
            printf("No\n");
            while (s.empty() == false)
                s.pop();
        }
    }
    return 0;
}








