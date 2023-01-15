// https://leetcode.com/problems/defanging-an-ip-address/
// Created by ruslan515 on 15.01.23.
//

#include <algorithm>
#include <regex>
#include <string>

class Solution {
public:
    string defangIPaddr(string address) {
        address = std::regex_replace(address, std::regex("\\."), "[.]");
        return address;
    }
};