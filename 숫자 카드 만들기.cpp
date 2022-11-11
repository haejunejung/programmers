// 두 조건 중 하나를 만족하는 가장 큰 양의 정수 a 구하기
// 철수가 가진 카드들을 모든 숫자의 약수 중 하나이면서 영희가 가진 카드들의 약수가 아닌 정수 
// 철수의 모든 카드들의 GCD이 영희의 모든 수와 GCD가 1일 때?

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD (int a, int b) {
    if (b == 0) return a;
    else return GCD (b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0, answer_A, answer_B;
    
    int gcd_A = arrayA[0], gcd_B = arrayB[0], length = arrayA.size();
    for (int i = 1; i < length; ++i) {
        gcd_A = GCD (gcd_A, arrayA[i]); // arrayA의 gcd 구하기 
        gcd_B = GCD (gcd_B, arrayB[i]); // arrayB의 gcd 구하기
    }
    
    for (int i = 0; i < length; ++i) {
        if (arrayB[i] % gcd_A == 0) {
            answer_A = 0;
            break;
        }
        else answer_A = gcd_A;
    }
    
    for (int i = 0; i < length; ++i) {
        if (arrayA[i] % gcd_B == 0) {
            answer_B = 0;
            break;
        }
        else answer_B = gcd_B;
    }
    
    answer = max (answer_A, answer_B);
    return answer;
}