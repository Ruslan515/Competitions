// https://leetcode.com/problems/snapshot-array/
// Created by ruslan515 on 11.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
public:
    vector<unordered_map<int, int>> snaps;
    unordered_map<int, int> mp;
    int snap_id_global;

    SnapshotArray(int length) {
        snap_id_global = 0;
    }

    void set(int index, int val) {
        mp[index] = val;
    }

    int snap() {
        snaps.push_back(mp);
        ++snap_id_global;
        return snap_id_global - 1;
    }

    int get(int index, int snap_id) {
        return snaps[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */


int main() {
//    SnapshotArray *obj = new SnapshotArray(1);
//    obj->set(0, 4);
//    obj->set(0, 16);
//    obj->set(0, 13);
//    assert(0 == obj->snap());
//    assert(13 == obj->get(0, 0));
//    assert(1 == obj->snap());

    SnapshotArray *obj = new SnapshotArray(3);
    obj->set(0, 5);
    assert(0 == obj->snap());
    obj->set(0, 6);
    assert(5 == obj->get(0, 0));

    return 0;
}