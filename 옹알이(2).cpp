#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> word = {"aya" , "ye" , "woo", "ma"};

bool check (string data) {
    if (data.size() == 2 && (data == word[1] || data == word[3])) return true;
    if (data.size() == 3 && (data == word[0] || data == word[2])) return true;
    
    int cnt = 0, len = data.size();
    string prev_data;
    while (cnt < len) {
        if (cnt + 3 <= len) {
            string temp;
            for (int i=cnt; i<cnt+3; ++i) {
                temp += data[i];
            }
            
            if ((temp == word[0] || temp == word[2])) {
                if (!prev_data.empty() && temp == prev_data) return false;
                cnt += 3;
                prev_data = temp;
                continue;
            }
        }
        
        if (cnt + 2 <= len) {
            string temp;
            for (int i=cnt; i<cnt+2; ++i) {
                temp += data[i];
            }
            
            if ((temp == word[1] || temp == word[3])) {
                if (!prev_data.empty() && temp == prev_data) return false;
                cnt += 2;
                prev_data = temp;
                continue;
            }
        }
        
        return false;
    }
    
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (auto item : babbling) {
        if (item.size() < 1) continue;
        if (check(item)) answer++;
    }
    return answer;
}