#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a) {
        int newbottle = (n / a) * b;
        n = (n % a) + newbottle;
        answer += newbottle;
    }
    return answer;
}