#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
bool visit[2][1001][1001] = { false, }; // visit[0]~ : �� �� �μ�, visit[1]~ : �� �μ�
int map[1001][1001] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N = 0, M = 0;
queue<pair<int, pair<int, int> > > q;
 
int BFS()
{
    q.push({ 0, {1, 1} }); // ���� ���ǿ� ���� (1, 1)���� ����ϰ�, ���� �翬�� �� �μ� ����(0)
    visit[0][1][1] = true; // �� �� �μ� ���� + (1, 1) �湮 ǥ��
    int ret = 1; // �����ϴ� ĭ�� �����ؾ� �ϱ� ������ 1���� ����.(���� ����)
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            int current = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if (r == N && c == M) // ���� �ߴٸ�
            {
                return ret;
            }
            for (int i = 0; i < 4; i++)
            {
                int y = r + dy[i];
                int x = c + dx[i];
                if (y <= 0 || y > N || x <= 0 || x > M || visit[current][y][x]) continue;
                if (current == 0) // ���ݱ��� ���� �� �μ����ٸ�
                {
                    if (map[y][x] == 1) // ���̶�� �μ���.
                    {
                        q.push({ 1, {y, x} }); // �μ������� 1�� �ٲ��ش�.
                        visit[1][y][x] = true;
                    }
                    else if (map[y][x] == 0) // ���� �ƴ϶�� �׳� ���
                    {
                        q.push({ 0, { y, x } });
                        visit[0][y][x] = true;
                    }
                }
                else if (current == 1) // ���� �μ� ���� �ִٸ�
                {
                    if (map[y][x] == 0) // ���� ������� �� �Ѵ�.
                    {
                        q.push({ 1, { y, x } });
                        visit[1][y][x] = true;
                    }
                }
            }
        }
 
        ++ret;
    }
 
    return -1; // ���� ����
}
 
int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    printf("%d\n", BFS());
    return 0;
}