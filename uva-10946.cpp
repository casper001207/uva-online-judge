//碰到不是'.'的字元就用BFS去算該坑洞的面積，最後再sort輸出即可。
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int X, Y;
char grid[55][55];
struct hole_type {
    char ch;
    int num;
} hole[2550];
struct point_type {
    int i;
    int j;
};
hole_type BFS(char c, int i, int j);
bool cmp(hole_type a, hole_type b);
int main()
{
    int Case = 1;
    while (scanf("%d%d", &X, &Y) && (X || Y)) {
        for (int i = 0; i < X; ++i)
            scanf("%s", grid[i]);
        
        int numOfhole = 0;
        for (int i = 0; i < X; ++i)
            for (int j = 0; j < Y; ++j)
                if (grid[i][j] != '.')
                    hole[numOfhole++] = BFS(grid[i][j], i, j);
        
        sort(hole, hole + numOfhole, cmp);
        
        printf("Problem %d:\n", Case++);
        for (int i = 0; i < numOfhole; ++i)
            printf("%c %d\n", hole[i].ch, hole[i].num);
    }
}
const int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
hole_type BFS(char c, int i, int j)
{
    queue<point_type> Q;
    Q.push({i,j});
    grid[i][j] = '.';  // 把該位置變成'.'避免之後重複算到
    int num = 1;
    
    point_type cur, nxt;
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        for (int k = 0; k < 4; ++k) {
            nxt.i = cur.i + direction[k][0];
            nxt.j = cur.j + direction[k][1];
            if (nxt.i < 0 || nxt.i >= X || nxt.j < 0 || nxt.j >= Y) continue;
            
            if (grid[nxt.i][nxt.j] == c) {
                grid[nxt.i][nxt.j] = '.';
                Q.push(nxt);
                ++num;
            }
        }
    }
    return {c, num};
}
bool cmp(hole_type a, hole_type b)
{
    // 優先排數字，再排字母
    return (a.num == b.num) ? (a.ch < b.ch) : (a.num > b.num);
}