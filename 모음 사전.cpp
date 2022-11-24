/* 풀이 1 */
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int idx, cur, answer = 0;
    const int weights[] = { 781, 156, 31, 6, 1 };
    
    for (idx = 0; idx < word.size(); ++idx) 
    {
        switch (word[idx])
        {
            case 'A':
                cur = 0;
                break;
            case 'E':
                cur = 1;
                break;
            case 'I':
                cur = 2;
                break;
            case 'O':
                cur = 3;
                break;
            case 'U':
                cur = 4;
                break;
        }
        ++answer;
        answer += cur * weights[idx];
    }
    return answer;
}

/* 풀이 2 */
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
string ans;
int res;

int dfs (int cnt, string word) {
    if (word.size() == 5) return cnt;
    
    for (int i = 0; i < 5; ++i) 
    {
        switch (i)
        {
            case 0: 
                if (word+'A' == ans) 
                {
                    res = cnt+1;
                    break;   
                }
                cnt = dfs(cnt+1, word+'A');
                break;
            case 1: 
                if (word+'E' == ans) 
                {
                    res = cnt+1;
                    break;   
                }
                cnt = dfs(cnt+1, word+'E');
                break;
            case 2: 
                if (word+'I' == ans) 
                {
                    res = cnt+1;
                    break;   
                }
                cnt = dfs(cnt+1, word+'I');
                break;
            case 3: 
                if (word+'O' == ans) 
                {
                    res = cnt+1;
                    break;   
                }
                cnt = dfs(cnt+1, word+'O');
                break;
            case 4: 
                if (word+'U' == ans) 
                {
                    res = cnt+1;
                    break;   
                }
                cnt = dfs(cnt+1, word+'U');
                break;
        }
    }
    
    return cnt;
}

int solution(string word) {
    ans = word;
    
    dfs(0,"");
    return res;
}
