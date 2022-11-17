/*
    S = straight
    L = left
    R = right
    격자의 끝을 넘어갈 경우 반대쪽으로 넘어간다
    종료 조건 : 이미 지나간 방향으로 지나갈때 ?
*/

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