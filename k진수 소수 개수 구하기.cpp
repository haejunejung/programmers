// k 진수로 바꿨을 때, 조건에 맞는 PN이 몇 개인지 찾기
// 0P0 처럼 소수 양쪽에 0이 있는 경우
// P0 소수 오른쪽에만 0이 있고 왼쪽에 아무것도 없는 경우
// 0P 소수 왼쪽에만 0이 있고 오른쪽에 아무것도 없는 경우
// P처럼 소수 양쪽에 아무것도 없는 경우

/* 
    1. n을 k진수로 바꾼다
    2. 바꾼 수에서 PN이 되는 부분을 찾는다
    3. PN이 되는 부분에서 조건에 맞는 경우를 찾는다
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define MAX 1000000

/* n을 k진수로 표현한다 */
string NtoK (int n, int k) {
    string ans = "";
    while (n>0) {
        ans += to_string(n%k);
        n /= k;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

/* n이 소수인지 확인한다 */
bool IsPrime (unsigned long long n) {
    if (n == 0 || n == 1) return false;
    
    for (size_t i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    /* K진수로 바꾸기 */
    string newNum = NtoK (n, k);
    size_t len = newNum.size();
    
    for (size_t i = 0; i < len; ++i) {    
        for (size_t j = 1; j <= len - i; ++j) {
            string num = newNum.substr(i, j);
            
            /* P에는 각 자릿수에 0이 들어가면 안된다 => break를 통해 다음으로 넘어가게끔 했다 */
            if (num[num.size()-1] == '0') break; 
            unsigned long long cmpNum;
            
            stringstream ss;
            ss << num;
            ss >> cmpNum;
            
            ss.str("");
            ss.clear();
            
            if (IsPrime(cmpNum)) {
                if (i > 0 && i+j <= len && newNum[i-1] == '0' && newNum[i+j] == '0') /* condition 1 */
                {
                    answer++;
                }
                else if (i == 0 && i+j <= len && newNum[i+j] == '0') /* condition 2 */
                {
                    answer++;
                }
                else if (i > 0 && i+j == len && newNum[i-1] == '0') /* condition 3 */
                {
                    answer++;
                }
                else if (i == 0 && i+j == len) /* condition 4 */
                {
                    answer++;
                }
            }
        }
    }    
    
    return answer;
}