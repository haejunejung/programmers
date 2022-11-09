#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector <int> input;
    for (auto item : ingredient) {
        input.push_back(item);
        if (input.size() < 4) continue;
        
        if (item == 1) {
            int len = input.size();
            if (input[len-1] == 1 && input[len-2] == 3 && 
                input[len-3] == 2 && input[len-4] == 1) {
                for (int i=0; i<4; ++i) {
                    input.pop_back();
                }
                answer++;
            }
        }
    }
    
    return answer;
}