#include <cstdio>
#include <queue>
using namespace std;

bool checkIfOkToPrint(queue<int> q, int job, int priority[]);
int main()
{
    int Case, n, m;
    int priority[105];
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", &priority[i]);
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            q.push(i);
        
        int time = 0;
        bool isover = false;
        while (!isover) {
            int job = q.front();
            q.pop();
            
            bool check = checkIfOkToPrint(q, job, priority);
            if (check == true) {
                ++time;
                if (job == m) isover = true;
            } else {
                q.push(job);
            }
        }
        printf("%d\n", time);
    }
}
bool checkIfOkToPrint(queue<int> q, int job, int priority[])
{
    while (!q.empty()) {
        if (priority[q.front()] > priority[job])
            return false;
        else
            q.pop();
    }
    return true;
}
