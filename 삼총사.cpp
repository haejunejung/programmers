#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    size_t length = number.size();
    for (size_t i=0; i<length-2; ++i) {
        for (size_t j=i+1; j<length-1; ++j) {
            for (size_t k=j+1; k<length; ++k) {
                if (number[i] + number[j] + number[k] == 0) answer++;
            }
        }
    }
    return answer;
}