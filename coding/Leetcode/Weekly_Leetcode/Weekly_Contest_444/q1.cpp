//
// Created by omega515 on 06.04.25.
//

#include <bits/stdc++.h>

using namespace std;

class Router {
public:
    int capacity, count;
    deque<vector<int>> dq;
    unordered_set<int> sources, dests, tms;
    unordered_map<int, unordered_map<int, int>> mp;

    Router(int memoryLimit) {
        this->capacity = memoryLimit;
        this->count = 0;
    }

    bool addPacket(int source, int destination, int timestamp) {
        bool answer = false;
        bool check_source = this->sources.find(source) != this->sources.end();
        bool check_dest = this->dests.find(destination) != this->dests.end();
        bool check_tms = this->tms.find(timestamp) != this->tms.end();
        bool check = check_source && check_dest && check_tms;
        if (!check) {
            answer = true;
            if (this->count >= this->capacity) {
                vector<int> v = this->dq.front();
                int t_curr = v[2];
                --this->mp[destination][t_curr];
                this->dq.pop_front();
            }
            this->dq.push_back({source, destination, timestamp});
            ++this->mp[destination][timestamp];
        }
        return answer;
    }

    vector<int> forwardPacket() {
        if (this->count == 0) {
            return {};
        }
        vector<int> answer = this->dq.front();
        this->dq.pop_front();
        return answer;
    }

    int getCount(int destination, int startTime, int endTime) {
        unordered_map<int, int> destMap = this->mp[destination];
        int answer = 0;
        for (auto item: destMap) {
            int t = item.first;
            if (t >= startTime && t <= endTime) {
                answer += item.second;
            }
        }

        return answer;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main() {

    Router *router = new Router(3); // Initialize Router with memoryLimit of 3.
    assert(true == router->addPacket(1, 4, 90)); // Packet is added. Return True.
    assert(true == router->addPacket(2, 5, 90)); // Packet is added. Return True.
    assert(false == router->addPacket(1, 4, 90)); // This is a duplicate packet. Return False.
    assert(true == router->addPacket(3, 5, 95)); // Packet is added. Return True
    assert(true == router->addPacket(4, 5,
                                     105)); // Packet is added, [1, 4, 90] is removed as number of packets exceeds memoryLimit. Return True.
    vector<int> nums{2, 5, 90};
    assert(nums == router->forwardPacket()); // Return [2, 5, 90] and remove it from router->
    assert(true == router->addPacket(5, 2, 110)); // Packet is added. Return True.
    assert(1 == router->getCount(5, 100,
                                 110)); // The only packet with destination 5 and timestamp in the inclusive range [100, 110] is [4, 5, 105]. Return 1.©leetcode

//    Router *router = new Router(2); // Initialize Router with memoryLimit of 2.
//    assert(true == router->addPacket(7, 4, 90)); // Return True.
//    vector<int> nums{7, 4, 90};
//    assert(nums == router->forwardPacket()); // Return [7, 4, 90].
//    nums = {};
//    assert(nums == router->forwardPacket()); // There are no packets left, return [].©leetcode

    return 0;
}
