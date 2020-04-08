#include <cstdio>
using namespace std;
int N;
char board[201][201];
const int direction[][2] = {{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};
void DFS(int i, int j, char c, int &win)
{
    board[i][j] = '.';
    if (c == 'b' && i == N-1) win = 1;
    if (c == 'w' && j == N-1) win = 2;
    for (int x=0; x<6; ++x){
        int i_next = i+direction[x][0];
        int j_next = j+direction[x][1];
        if (i_next<0 || i_next>=N || j_next<0 || j_next>=N) continue;
        if (board[i_next][j_next] == c)
            DFS(i_next, j_next, c, win);
    }
}
int main()
{
    //reopen("input.txt","rt",stdin);
    int Case = 1;
    while (scanf("%d",&N)){
        if (!N) break;
        for (int i=0; i<N; ++i)
            scanf("%s",board[i]);
        int win = 0; // win=1:Black  win=2:White
        for (int i=0; i<N; ++i)
            if (board[i][0] == 'w')
                DFS(i, 0, 'w', win);
        for (int j=0; j<N; ++j)
            if (board[0][j] == 'b')
                DFS(0, j, 'b', win);
        if (win == 1) printf("%d B\n",Case++);
        else printf("%d W\n",Case++);
    }
    return 0;
}