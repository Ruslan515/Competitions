// https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2023-12-17
// Created by omega515 on 17.12.23.
//
#include <bits/stdc++.h>

using namespace std;

class FoodRatings {
private:
    struct myComparator {
        int operator()(
                const tuple<int, string> &tuple1,
                const tuple<int, string> &tuple2
        ) {
            if (get<0>(tuple1) == get<0>(tuple2)) {
                if (get<1>(tuple1) >= get<1>(tuple2)) {
                    return true;
                }
                return false;
            }
            return get<0>(tuple1) <= get<0>(tuple2);

        }
    };

    unordered_map<
            string,
            priority_queue<
                    tuple<int, string>,
                    vector<tuple<int, string>>,
                    myComparator
            >
    > mp_cuisines;

    unordered_map<string, string> mp_food_cuisine;
public:
    FoodRatings(vector<string> &foods,
                vector<string> &cuisines,
                vector<int> &ratings) {
        int n = foods.size();
        string food, cuisine;
        int rat;
        for (int i = 0; i < n; ++i) {
            food = foods[i];
            cuisine = cuisines[i];
            rat = ratings[i];
            tuple<int, string> tp = make_tuple(rat, food);
            mp_cuisines[cuisine].push(tp);

            mp_food_cuisine[food] = cuisine;
        }

//        cout << get<1>(mp_cuisines["japanese"].top()) << "\n";
//        mp_cuisines["japanese"].pop();
//        cout << get<1>(mp_cuisines["japanese"].top()) << "\n";
//        mp_cuisines["japanese"].pop();
//        cout << "hello";
    }

    void changeRating(string food, int newRating) {
        string cuisine = mp_food_cuisine[food];
        priority_queue<tuple<int, string>, vector<tuple<int, string >>, myComparator> local_pq;
        tuple<int, string> t;
        string localFood;
        while (!mp_cuisines[cuisine].empty()) {
            t = mp_cuisines[cuisine].top();
            mp_cuisines[cuisine].pop();
            localFood = get<1>(t);
            if (localFood == food) {
                tuple<int, string> newT = make_tuple(newRating, food);
                local_pq.push(newT);
            } else {
                local_pq.push(t);
            }
        }
        mp_cuisines[cuisine] = local_pq;
    }

    string highestRated(string cuisine) {
        string answer = get<1>(mp_cuisines[cuisine].top());
        return answer;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
int main() {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};
    FoodRatings *obj = new FoodRatings(
            foods,
            cuisines,
            ratings
    );
    assert(obj->highestRated("korean") == "kimchi");
    assert(obj->highestRated("japanese") == "ramen");
    obj->changeRating("sushi", 16);
    assert(obj->highestRated("japanese") == "sushi");
    obj->changeRating("ramen", 16);
    assert(obj->highestRated("japanese") == "ramen");


    return 0;
}