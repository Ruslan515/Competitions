// https://leetcode.com/contest/weekly-contest-444/problems/implement-router/description/?slug=minimum-pair-removal-to-sort-array-i&region=global_v2
// Created by omega515 on 06.04.25.
//

#include <bits/stdc++.h>

using namespace std;

#include <unordered_map>
#include <queue>
#include <map>
#include <string>

using namespace std;

#include <unordered_map>
#include <queue>
#include <map>
#include <string>

using namespace std;

class Router {
    struct Packet {
        int source;
        int destination;
        int timestamp;
        string key;
    };

    int capacity;
    queue<Packet> q;
    unordered_map<string, bool> packetExists;
    unordered_map<int, map<int, int>> destTimeCount;

public:
    Router(int memoryLimit) : capacity(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "," + to_string(destination) + "," + to_string(timestamp);

        if (packetExists.find(key) != packetExists.end()) {
            return false;
        }

        if (q.size() >= capacity) {
            const Packet &p = q.front();
            packetExists.erase(p.key);
            auto &timeMap = destTimeCount[p.destination];
            if (--timeMap[p.timestamp] == 0) {
                timeMap.erase(p.timestamp);
                if (timeMap.empty()) {
                    destTimeCount.erase(p.destination);
                }
            }
            q.pop();
        }

        Packet p = {source, destination, timestamp, key};
        q.push(p);
        packetExists[key] = true;
        destTimeCount[destination][timestamp]++;
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }

        const Packet &p = q.front();
        vector<int> result = {p.source, p.destination, p.timestamp};
        packetExists.erase(p.key);
        auto &timeMap = destTimeCount[p.destination];
        if (--timeMap[p.timestamp] == 0) {
            timeMap.erase(p.timestamp);
            if (timeMap.empty()) {
                destTimeCount.erase(p.destination);
            }
        }
        q.pop();
        return result;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimeCount.find(destination);
        if (it == destTimeCount.end()) return 0;

        const auto &timeMap = it->second;
        auto low = timeMap.lower_bound(startTime);
        auto high = timeMap.upper_bound(endTime);

        int count = 0;
        for (auto it = low; it != high; ++it) {
            count += it->second;
        }
        return count;
    }
};


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