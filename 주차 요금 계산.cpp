#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
int CalTimes (string in_time, string out_time) {
    int in_hour  = stoi(in_time.substr(0, 2));
    int out_hour = stoi(out_time.substr(0, 2));
    int in_min  = stoi(in_time.substr(3, 2));
    int out_min = stoi(out_time.substr(3, 2));
    
    int time = (out_hour - in_hour) * 60 + (out_min - in_min);    
    return time;
}

int Calfee (vector <int> fees, int times) {
    
    int fee = fees[1];
    if ((times - fees[0]) <= 0) return fee;
    
    if ((times - fees[0]) % fees[2] == 0) fee += ((times - fees[0]) / fees[2]) * fees[3];
    else fee += ((times - fees[0]) / fees[2] + 1) * fees[3];
    return fee;
}

bool cmp (pair <string, int> &a, pair <string, int> &b) {
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map <string, int> Cars;
    map <string, string> Car_info;
    
    for (auto data : records) {
        string time = data.substr(0, 5);
        string car_num = data.substr(6, 4);
        string info = data.substr(11);
        
        if (info == "IN") Car_info.insert({car_num, time});
        else 
        {
            auto car = Car_info.find(car_num);
            string in_time  = car->second;
            string out_time = time;
            int times = CalTimes (in_time, out_time);

            auto data = Cars.find(car_num);
            if (data == Cars.end()) Cars.insert({car_num, times});
            else data->second += times;
            
            Car_info.erase(car_num);
        }
    }
    
    while (!Car_info.empty()) {
        string car_num = Car_info.begin()->first;
        string in_time = Car_info.begin()->second;
        string out_time = "23:59";
        
        int times = CalTimes (in_time, out_time);
        
        auto data = Cars.find(car_num);
        if (data == Cars.end()) Cars.insert({car_num, times});
        else data->second += times;
        
        Car_info.erase(car_num);
    }
    
    for (auto data : Cars) {
        cout << data.second << endl;
        int fee = Calfee (fees, data.second);
        answer.push_back(fee);
    }
    
    return answer;
}