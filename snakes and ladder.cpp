

class Solution {
public:
pair<int,int> getPos(int num, int n) {
int rowFromBottom = (num - 1) / n;
int col = (num - 1) % n;
if (rowFromBottom % 2 == 1)
col = n - 1 - col;
int row = n - 1 - rowFromBottom;
return {row, col};
}
int snakesAndLadders(vector<vector<int>>& board) {
int n = board.size();
queue<pair<int,int>> q;
vector<bool> visited(n * n + 1, false);
q.push({1, 0});
visited[1] = true;
while (!q.empty()) {
auto [curr, moves] = q.front();
q.pop();
if (curr == n * n)
return moves;
for (int dice = 1; dice <= 6; dice++) {
int next = curr + dice;
if (next > n * n)
break;
auto [r, c] = getPos(next, n);
if (board[r][c] != -1)
next = board[r][c];
if (!visited[next]) {
visited[next] = true;
q.push({next, moves + 1});
}
}
}
return -1;
}
};
