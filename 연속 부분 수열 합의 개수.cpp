#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map <int ,int> m; /* 맵은 중복을 허용하지 않으므로 유용한 STL일 것이라 생각했다 */
vector <int> copy_elements; /* elements copy */

void solve (int n, int sum, int idx) {
    m.insert ({sum, 1}); /* sum이 중복이 안된다면, insert */
    if (n == copy_elements.size()) { /* elements 크기 만큼 돌았다면 종료 */
        return;
    }
    
    idx = (idx + 1) % (copy_elements.size()); /* 원형 배열을 만드는 방법 */
    solve (n+1, sum+copy_elements[idx], idx); /* recursion */
}

int solution(vector<int> elements) {
    int answer = 0;
    copy_elements = elements;
    
    for (int i=0; i<elements.size(); ++i) {
        solve (1, elements[i], i);
    }
    
    answer = m.size(); /* 중복되지 않은 map의 크기 => 결과값 */
    
    return answer;
}