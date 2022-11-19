/* 해답 1 */
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> copy_grid;
bool board[501][501][4];
int Row, Col;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0}; 
const int left[] = {3, 2, 0, 1};
const int right[] = {2, 3, 1, 0};

int dfs (int sr, int sc, int sd, int r, int c, int in, int len) {
    if (sc == c && sr == r && sd == in && len != 0) {
        return len;
    }
    
    board[r][c][in] = true;
    
    int out;
    
    if (copy_grid[r][c] == 'L') {
        out = left[in];
    }
    else if (copy_grid[r][c] == 'R') {
        out = right[in];
    }
    else {
        out = in;
    }
    
    int nc = c + dx[out];
    int nr = r + dy[out];
    
    if (nc >= Col) nc = 0;
    if (nr >= Row) nr = 0;
    if (nc < 0) nc = Col - 1;
    if (nr < 0) nr = Row - 1;
    
    return dfs (sr, sc, sd, nr, nc, out, len+1);
}

bool cmp (int &a, int &b) {
    return a < b;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    copy_grid = grid;
    memset(board, 0, sizeof(board));
    Row = grid.size();
    Col = grid[0].size();
    
    int i,j,k;
    for (i=0; i<Row; ++i) {
        for (j=0; j<Col; ++j) {
            for (k=0; k<4; ++k) {
                if (!board[i][j][k]) {
                    int res = dfs (i,j,k, i,j,k, 0);
                    answer.push_back(res);
                }
            }
        }
    }
    
    sort (answer.begin(), answer.end(), cmp);
    return answer;
}



/* 처음 시도했을 때 틀린 코드 */

/* 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> copy_grid;
vector<int> answer;
size_t x,y;
int maximum;
int cnt;

#define up 0
#define down 1
#define right 2
#define left 3

pair<int,int> goStraight (int i, int j, int dir) {
    switch (dir) {
        case up : 
            i = (i+1) % (y+1);
            break;
            
        case down : 
            i = i-1;
            if (i < 0) i += y;
            break;
            
        case right :
            j = (j+1) % (x+1);
            break;
            
        case left :
            j = j-1;
            if (j < 0) j += x;
            break;
    }
    
    return make_pair(i,j);
}

pair<int,int> goLeft (int i, int j, int dir) {
    switch (dir) {
        case up :
            j = j-1;
            if (j < 0) j += x;
            break;
            
        case down : 
            j = (j+1) % (x+1);
            break;
        
        case right :
            i = i-1;
            if (i < 0) i += y;
            break;
            
        case left :
            i = (i+1) % (y+1);
            break;
    }
    
    return make_pair(i,j);
}

pair<int,int> goRight (int i, int j, int dir) {
    switch (dir) {
        case down :
            j = j-1;
            if (j < 0) j += x;
            break;
            
        case up : 
            j = (j+1) % (x+1);
            break;
        
        case left :
            i = i-1;
            if (i < 0) i += y;
            break;
            
        case right :
            i = (i+1) % (y+1);
            break;
    }
    
    return make_pair(i,j);
}

void dfs (int i, int j, int dir, vector<vector<vector<bool>>> board) {
    board[i][j][dir] = true;
    cnt++;
    if (cnt == x*y*4) {
        answer.push_back(cnt);
        return;
    }

    pair<int,int> temp;
    switch (copy_grid[i][j]) {
        case  'S' : 
            temp = goStraight(i, j, dir);
            i = temp.first;
            j = temp.second;
            break;
            
        case  'L' :
            temp = goLeft(i, j, dir);
            i = temp.first;
            j = temp.second;
            if (dir == down) dir = left;
            else if (dir == right) dir = up;
            else if (dir == up) dir = right;
            else dir = down;
            break;
        case  'R' :
            temp = goRight(i, j, dir);
            i = temp.first;
            j = temp.second;
            if (dir == down) dir = right;
            else if (dir == right) dir = up;
            else if (dir == up) dir = left;
            else dir = down;
            break;
    }
    
    dfs(i,j,dir,board);
}

bool IsExit () {
    if (maximum == x*y*4) return true;
    else return false;
}

bool cmp(int &a, int &b) {
    return a < b;
}

vector<int> solution(vector<string> grid) {
    maximum = 0;
    copy_grid = grid;
    
    x = grid[0].size();
    y = grid.size();
    
    for (int i=0; i<y; ++i) {
        for (int j=0; j<x; ++j) {
            for (int k=0; k<4; ++k) {
                vector<vector<vector<bool>>> board(y, vector<vector<bool>> (x, vector<bool> (4, false)));
                cnt = 0;
                dfs(i, j, k, board);
                if (IsExit()) {
                    return answer;
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}
*/