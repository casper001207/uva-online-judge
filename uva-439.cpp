#include <cstdio>
#include <queue>
using namespace std;
struct point_type{
    int i;
    int j;
};
const int direction[][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
int BFS(point_type Start, point_type End)
{
    int step[9][9] = {0};
    queue<point_type> Q;
    Q.push(Start);
    
    point_type cur, nxt;
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        
        if (cur.i == End.i && cur.j == End.j)
            return step[cur.i][cur.j];
        
        for (int i = 0; i < 8; ++i) {
            nxt.i = cur.i + direction[i][0];
            nxt.j = cur.j + direction[i][1];
            if (nxt.i < 1 || nxt.i > 8 || nxt.j < 1 || nxt.j > 8) continue;
            
            if (step[nxt.i][nxt.j] == 0) {
                step[nxt.i][nxt.j] = step[cur.i][cur.j] + 1;
                Q.push(nxt);
            }
        }
    }
    return step[cur.i][cur.j];
}
int main()
{
    char s1[3], s2[3];
    while (scanf("%s%s", s1, s2) != EOF) {
        point_type Start, End;
        Start.i = s1[0] - 'a' + 1;
        Start.j = s1[1] - '0';
        End.i = s2[0] - 'a' + 1;
        End.j = s2[1] - '0';
        int moves = BFS(Start, End);
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, moves);
    }
    return 0;
}