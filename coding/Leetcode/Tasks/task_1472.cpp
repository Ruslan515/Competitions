// https://leetcode.com/problems/design-browser-history/
// Created by ruslan515 on 18.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
public:
    vector<string> v;
    int currentPosition;

    BrowserHistory(string homepage) {
        v.push_back(homepage);
        currentPosition = 0;
    }

    void visit(string url) {
        int n = v.size();
        if (currentPosition != n - 1) {
            int k = n - 1 - currentPosition;
            for (int i = 0; i < k; ++i) {
                v.erase(v.end() - 1);
            }
        }
        v.push_back(url);
        ++currentPosition;
    }

    string back(int steps) {
        string ans;
        if (steps > currentPosition) {
            currentPosition = 0;
        } else {
            currentPosition -= steps;
        }
        ans = v[currentPosition];
        return ans;
    }

    string forward(int steps) {
        int n = v.size();
        string ans;
        int idx = currentPosition + steps;
        if (idx >= n) {
            currentPosition = n - 1;
        } else {
            currentPosition += steps;
        }
        ans = v[currentPosition];
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
    BrowserHistory *browser = new BrowserHistory("leetcode.com");
    browser->visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browser->visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browser->visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    assert(browser->back(1) ==
           "facebook.com");                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    assert(browser->back(1) ==
           "google.com");                   // You are in "facebook.com", move back to "google.com" return "google.com"
    assert(browser->forward(1) ==
           "facebook.com");                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    browser->visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    assert(browser->forward(2) ==
           "linkedin.com");                // You are in "linkedin.com", you cannot move forward any steps.
    assert(browser->back(2) ==
           "google.com");                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    assert(browser->back(7) ==
           "leetcode.com");                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    return 0;
}