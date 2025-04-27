// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21
// Created by omega515 on 21.03.2025.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string>
    findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = recipes.size();
        vector<string> answer;
        unordered_set<string> setSupplies{supplies.begin(), supplies.end()};
        unordered_map<string, vector<string >> mpRecIng;
        for (int i = 0; i < n; ++i) {
            mpRecIng[recipes[i]] = ingredients[i];
        }


        while (true) {
            int cnt  = 0;
            for (auto it = mpRecIng.begin(); it != mpRecIng.end();) {
                string rec = it->first;
                vector<string> subIng = it->second;
                int j = 0;

                int sizeIng = subIng.size();
                for (; j < sizeIng; ++j) {
                    if (setSupplies.find(subIng[j]) == setSupplies.end()) {
                        break;
                    }
                }
                if (j == sizeIng) {
                    answer.push_back(rec);
                    it = mpRecIng.erase(it);
                    ++cnt;
                    setSupplies.insert(rec);
                } else {
                    ++it;
                }

            }
            if (cnt == 0) {
                break;
            }

        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    vector<string> recipes, supplies;
    vector<vector<string>> ingredients;
    vector<string> answer;
    Solution solve;

    answer = {
            "b",
            "cjeqvd",
            "dtacyvphta",
            "gcmjogigi",
            "iomjmuppr",
            "jwdr",
            "jyxhmysc",
            "kfv",
            "kyhbalna",
            "lyqngrags",
            "pl",
            "qyhasfdxew",
            "sjb",
            "u",
            "w",
            "x",
            "xa"
    };
    sort(answer.begin(), answer.end());
//    for (auto s: answer) {
//        cout << '"' << s << '"' << ",";
//    }

    recipes = {"bbjdwlpb", "kfv", "w", "edb", "lyqngrags", "gecdmwk", "jyxhmysc", "jwdr", "j", "xa", "u", "kyhbalna",
               "sjb", "x", "gl", "b", "nswyye", "iomjmuppr", "cap", "dtacyvphta", "gcmjogigi", "uoujoqslw", "mkclxtme",
               "wquiic", "pl", "iabpr", "tsf", "qyhasfdxew", "nv", "cjeqvd", "m"};
    ingredients = {{"tbd",        "pl",         "gcmjogigi",  "dtacyvphta", "kyhbalna",   "m",          "jyxhmysc",   "cap",        "nv",         "uoujoqslw",  "nswyye",     "x",          "edb",        "gecdmwk",    "qyhasfdxew", "wquiic"},
                   {"cysxrnzd",   "umzo",       "baludtkhr",  "dm",         "tbd",        "obp",        "rkzugliuxp", "bm",         "oottbvyp",   "bzjzbha",    "aquezgdn",   "gcie",       "up",         "qjoynbi",    "f",          "ujgxhvnpv",  "ibld",       "ghaap",      "nacwecypkx", "nroqhuj",    "nweajike",   "cffsispcdi", "tza",        "nqbptnoajd", "mezyixgir",  "wu"},
                   {"up",         "xglquvfz",   "zxonskkj",   "bzjzbha",    "oyayhs",     "tbd",        "nacwecypkx", "ok"},
                   {"obp",        "mkmmmtcup",  "onqimxgive", "oxk",        "mkclxtme",   "j",          "xa",         "jyxhmysc",   "m",          "sjb",        "jwdr",       "bbjdwlpb",   "nv",         "cap",        "x",          "dtacyvphta", "u",          "gecdmwk",    "pl",         "gl",         "b"},
                   {"nroqhuj",    "zxonskkj",   "obp",        "xdous",      "szbekspwf",  "bm",         "rkzugliuxp", "dm",         "wu",         "likuunug",   "fkkyqrr",    "ok",         "gcie",       "ghaap",      "nacwecypkx", "ibld",       "bnsgfntzsm", "nqbptnoajd", "iavspo",     "nweajike",   "aquezgdn",   "f",          "qjoynbi",    "o",          "oottbvyp",   "tbd",      "up",         "ujgxhvnpv",  "tza"},
                   {"bzjzbha",    "aquezgdn",   "oxk",        "tbd",        "nacwecypkx", "cysxrnzd",   "zxonskkj",   "gvqjs",      "nweajike",   "hl",         "ok",         "mezyixgir",  "tza",        "qjoynbi",    "iavspo",     "cffsispcdi", "szbekspwf",  "dm",         "oyayhs",     "xdous",      "oottbvyp",   "gemczilrx",  "onqimxgive", "xglquvfz",   "f",          "vh",       "mkmmmtcup",  "nroqhuj",    "bnsgfntzsm", "ghaap",     "baludtkhr",  "zggq",      "cxb",     "umzo",       "kfv",        "lyqngrags", "w",         "gl",         "edb",        "cjeqvd",     "uoujoqslw", "pl",        "nv",  "j",          "x",  "bbjdwlpb",  "jwdr",   "b"},
                   {"umzo",       "rkzugliuxp", "ujgxhvnpv",  "tza",        "nacwecypkx", "xglquvfz",   "ok",         "wu",         "cffsispcdi", "o",          "obp",        "onqimxgive", "fe",         "iavspo",     "f",          "ghaap",      "gcie",       "dm",         "hl",         "oottbvyp",   "up",         "jwdr"},
                   {"o",          "oyayhs",     "zxonskkj",   "iavspo",     "qjoynbi",    "zggq",       "baludtkhr",  "aquezgdn",   "gemczilrx",  "likuunug",   "tza",        "rkzugliuxp", "nacwecypkx", "szbekspwf",  "gcie",       "umzo",       "hl",         "vh",         "cxb",        "mezyixgir",  "onqimxgive", "ubfijs",     "xdous",      "bm",         "oottbvyp",   "ok",       "acwutfftcs", "up",         "obp",        "mkmmmtcup", "gvqjs",      "nweajike",  "f",       "xglquvfz",   "ghaap",      "oxk"},
                   {"onqimxgive", "bzjzbha",    "fe",         "mkmmmtcup",  "nacwecypkx", "rkzugliuxp", "oottbvyp",   "gemczilrx",  "dm",         "ok",         "cffsispcdi", "likuunug",   "hl",         "ibld",       "oxk",        "aquezgdn",   "wu",         "iavspo",     "xdous",      "qjoynbi",    "cysxrnzd",   "tza",        "nroqhuj",    "bm",         "ujgxhvnpv",  "zggq",     "gvqjs",      "baludtkhr",  "mezyixgir",  "vh",        "tbd",        "gcie",      "fkkyqrr", "acwutfftcs", "nqbptnoajd", "ubfijs",    "cxb",       "up",         "o",          "lyqngrags",  "pl",        "w",         "u",   "mkclxtme"},
                   {"obp",        "gcie",       "likuunug",   "zxonskkj",   "xglquvfz",   "oottbvyp",   "acwutfftcs", "nweajike",   "nacwecypkx", "cxb",        "nqbptnoajd", "rkzugliuxp", "ibld",       "onqimxgive", "xdous",      "ok",         "ubfijs",     "wu",         "up",         "hl",         "mezyixgir",  "ujgxhvnpv",  "gemczilrx",  "nroqhuj",    "tza",        "bzjzbha",  "oyayhs",     "qjoynbi",    "gvqjs",      "fkkyqrr",   "cysxrnzd",   "dm",        "o",       "szbekspwf",  "bm",         "umzo",      "zggq",      "aquezgdn",   "bnsgfntzsm", "ghaap",      "vh",        "baludtkhr", "oxk", "cffsispcdi", "f",  "fe",        "iavspo", "sjb", "b"},
                   {"nqbptnoajd", "qjoynbi"},
                   {"oottbvyp",   "ubfijs",     "nqbptnoajd", "nroqhuj",    "mkmmmtcup",  "qjoynbi",    "fkkyqrr"},
                   {"bzjzbha",    "dm",         "fkkyqrr",    "mkmmmtcup",  "iavspo",     "nacwecypkx", "ubfijs",     "hl",         "onqimxgive", "aquezgdn",   "tbd",        "vh",         "wu",         "gcie",       "nroqhuj",    "obp",        "umzo",       "ujgxhvnpv",  "nweajike",   "mezyixgir",  "cxb",        "cysxrnzd",   "rkzugliuxp", "f"},
                   {"oottbvyp",   "wu",         "zxonskkj",   "qjoynbi",    "f",          "onqimxgive", "aquezgdn",   "bm",         "obp",        "nweajike",   "oyayhs",     "zggq",       "nqbptnoajd", "cffsispcdi", "dm",         "tbd",        "cxb",        "nroqhuj",    "umzo",       "ubfijs",     "hl",         "szbekspwf",  "likuunug",   "acwutfftcs", "bnsgfntzsm", "bzjzbha",  "rkzugliuxp", "baludtkhr",  "ujgxhvnpv",  "oxk",       "mezyixgir",  "fe",        "vh",      "nacwecypkx", "xglquvfz"},
                   {"zggq",       "nqbptnoajd", "nweajike",   "oxk",        "obp",        "ghaap",      "up",         "f",          "oottbvyp",   "qjoynbi",    "fe",         "ibld",       "szbekspwf",  "wu",         "cysxrnzd",   "fkkyqrr",    "rkzugliuxp", "cffsispcdi", "gvqjs",      "bm",         "nacwecypkx", "iavspo",     "likuunug",   "mezyixgir",  "ok",         "iabpr",    "gcmjogigi",  "iomjmuppr",  "tsf",        "u",         "uoujoqslw",  "j",         "nv",      "kyhbalna",   "bbjdwlpb",   "w",         "jyxhmysc",  "wquiic",     "cap",        "xa",         "nswyye",    "gecdmwk",   "lyqngrags"},
                   {"ibld",       "dm",         "gemczilrx",  "ghaap",      "fe",         "rkzugliuxp", "ubfijs",     "szbekspwf",  "iavspo"},
                   {"cffsispcdi", "onqimxgive", "tza",        "gcie",       "up",         "dm",         "hl",         "cxb",        "rkzugliuxp", "mkmmmtcup",  "ibld",       "gemczilrx",  "wu",         "mezyixgir",  "baludtkhr",  "nqbptnoajd", "obp",        "aquezgdn",   "zggq",       "tbd",        "vh",         "f",          "ubfijs",     "bzjzbha",    "nacwecypkx", "cysxrnzd", "likuunug",   "ok",         "nweajike",   "szbekspwf", "zxonskkj",   "gecdmwk",   "gl",      "iabpr"},
                   {"nqbptnoajd", "mkmmmtcup",  "cxb",        "wu",         "hl",         "gemczilrx",  "nacwecypkx", "fe",         "zggq",       "zxonskkj",   "oxk",        "nweajike",   "szbekspwf",  "bnsgfntzsm", "cffsispcdi", "ujgxhvnpv",  "xglquvfz",   "vh",         "qjoynbi",    "ghaap",      "tza",        "mezyixgir",  "cysxrnzd",   "iavspo",     "ibld",       "fkkyqrr",  "baludtkhr",  "nroqhuj",    "aquezgdn",   "ok",        "likuunug",   "oottbvyp"},
                   {"zxonskkj",   "baludtkhr",  "rkzugliuxp", "cffsispcdi", "acwutfftcs", "vh",         "tbd",        "nqbptnoajd", "fe",         "szbekspwf",  "up",         "oottbvyp",   "xglquvfz",   "iavspo",     "mkmmmtcup",  "ubfijs",     "onqimxgive", "cysxrnzd",   "ibld",       "oyayhs",     "ghaap",      "tza",        "uoujoqslw",  "bbjdwlpb",   "w",          "kfv",      "gecdmwk",    "sjb",        "m",          "nv"},
                   {"oottbvyp",   "umzo",       "ok",         "likuunug",   "up",         "gcie",       "xdous",      "dm",         "oyayhs",     "acwutfftcs", "nacwecypkx", "xglquvfz",   "rkzugliuxp", "obp",        "cysxrnzd",   "zxonskkj",   "cffsispcdi", "gemczilrx",  "mezyixgir",  "bm",         "tza",        "ubfijs",     "cxb",        "ghaap",      "gvqjs",      "tbd",      "fe",         "zggq",       "ujgxhvnpv"},
                   {"mkmmmtcup",  "wu",         "dm",         "xglquvfz",   "ibld",       "iavspo",     "bnsgfntzsm", "ok",         "aquezgdn",   "nweajike",   "baludtkhr",  "xdous",      "ghaap",      "oottbvyp",   "ubfijs",     "o",          "onqimxgive", "gemczilrx",  "cysxrnzd",   "fkkyqrr",    "f",          "acwutfftcs", "gvqjs",      "obp",        "ujgxhvnpv",  "tbd",      "up",         "likuunug",   "nqbptnoajd"},
                   {"hl",         "iavspo",     "xdous",      "gvqjs",      "acwutfftcs", "qjoynbi",    "oxk",        "aquezgdn",   "cxb",        "bzjzbha",    "ghaap",      "nweajike",   "baludtkhr",  "cffsispcdi", "fe",         "cysxrnzd",   "oottbvyp",   "mkmmmtcup",  "ok",         "oyayhs",     "up",         "gcie",       "gemczilrx",  "dm",         "x",          "jyxhmysc", "mkclxtme",   "w",          "pl",         "sjb",       "xa",         "iabpr",     "wquiic"},
                   {"oxk",        "hl",         "gemczilrx",  "mkmmmtcup",  "bm",         "rkzugliuxp", "oottbvyp",   "zggq",       "szbekspwf",  "gvqjs",      "wu",         "baludtkhr",  "nqbptnoajd", "cffsispcdi", "aquezgdn",   "likuunug",   "mezyixgir",  "xdous",      "iavspo",     "acwutfftcs", "ok",         "qjoynbi",    "ubfijs",     "nweajike",   "m",          "w",        "edb",        "u",          "sjb",        "lyqngrags", "dtacyvphta", "jwdr",      "gecdmwk", "tsf",        "iomjmuppr",  "gl",        "jyxhmysc",  "j",          "b",          "pl",         "nswyye",    "cap"},
                   {"rkzugliuxp", "up",         "gemczilrx",  "f",          "likuunug",   "gcie",       "tbd",        "onqimxgive", "bnsgfntzsm", "xglquvfz",   "bm",         "nacwecypkx", "umzo",       "obp",        "nqbptnoajd", "xdous",      "oxk",        "dtacyvphta", "bbjdwlpb",   "iabpr",      "edb",        "gcmjogigi",  "jyxhmysc",   "jwdr",       "x",          "kyhbalna", "cjeqvd",     "lyqngrags",  "kfv",        "mkclxtme",  "u",          "nswyye",    "sjb",     "iomjmuppr",  "gecdmwk",    "gl",        "b",         "qyhasfdxew", "xa",         "j",          "tsf",       "cap",       "m",   "w",          "nv", "uoujoqslw", "pl"},
                   {"bzjzbha",    "bnsgfntzsm", "ok",         "mezyixgir",  "nweajike",   "nqbptnoajd", "iavspo",     "xglquvfz",   "gcie",       "likuunug",   "cxb",        "wu",         "hl",         "fkkyqrr",    "cffsispcdi", "szbekspwf",  "tza",        "bm",         "ibld",       "dm",         "up",         "ghaap",      "mkmmmtcup",  "rkzugliuxp", "xdous",      "gvqjs",    "nacwecypkx"},
                   {"tbd",        "qjoynbi",    "nqbptnoajd", "fkkyqrr",    "nweajike",   "hl",         "ujgxhvnpv",  "o",          "zggq",       "oottbvyp",   "baludtkhr",  "rkzugliuxp", "vh",         "gvqjs",      "cxb",        "xdous",      "nroqhuj",    "pl",         "dtacyvphta", "jyxhmysc",   "wquiic",     "qyhasfdxew", "m",          "x",          "tsf",        "nswyye",   "b",          "mkclxtme"},
                   {"szbekspwf",  "xdous",      "likuunug",   "nacwecypkx", "gcie",       "dm",         "acwutfftcs", "oyayhs",     "up",         "nroqhuj",    "cysxrnzd",   "bzjzbha",    "gemczilrx",  "f",          "cffsispcdi", "zxonskkj",   "ok",         "mkmmmtcup",  "tbd",        "ibld",       "nqbptnoajd", "mkclxtme",   "uoujoqslw",  "xa",         "qyhasfdxew", "pl",       "m",          "w",          "nswyye",     "jyxhmysc",  "dtacyvphta", "gcmjogigi", "edb",     "bbjdwlpb",   "cjeqvd",     "sjb",       "iabpr",     "jwdr",       "x",          "iomjmuppr",  "gl",        "u",         "lyqngrags"},
                   {"likuunug",   "mkmmmtcup",  "bzjzbha",    "acwutfftcs", "vh",         "oottbvyp",   "szbekspwf",  "o",          "xglquvfz",   "oyayhs",     "cffsispcdi", "obp",        "nacwecypkx", "gemczilrx",  "dm",         "xdous",      "umzo",       "hl",         "gcie",       "nweajike",   "qjoynbi",    "fe",         "oxk",        "aquezgdn",   "f",          "bm",       "cxb",        "rkzugliuxp", "gvqjs",      "ibld",      "bnsgfntzsm", "up",        "nroqhuj", "tbd",        "mezyixgir",  "ok",        "wu",        "nqbptnoajd", "tza",        "baludtkhr",  "ubfijs"},
                   {"iabpr",      "cjeqvd",     "gcmjogigi",  "dtacyvphta", "kyhbalna",   "j",          "lyqngrags",  "mkclxtme",   "sjb",        "pl",         "iomjmuppr",  "m",          "b"},
                   {"ujgxhvnpv",  "nacwecypkx"},
                   {"bm",         "tza",        "onqimxgive", "oottbvyp",   "obp",        "o",          "likuunug",   "baludtkhr",  "bnsgfntzsm", "szbekspwf",  "aquezgdn",   "gvqjs",      "zxonskkj",   "nqbptnoajd", "gcie",       "gemczilrx",  "kyhbalna",   "cap",        "edb",        "wquiic",     "nswyye",     "kfv",        "qyhasfdxew", "xa",         "jyxhmysc",   "w",        "b",          "x",          "iabpr",      "pl",        "gl",         "u",         "cjeqvd",  "iomjmuppr",  "jwdr",       "bbjdwlpb",  "uoujoqslw", "gcmjogigi",  "gecdmwk",    "dtacyvphta", "nv",        "lyqngrags"}};
    supplies = {"bm", "tza", "onqimxgive", "oottbvyp", "obp", "o", "likuunug", "baludtkhr", "bnsgfntzsm", "szbekspwf",
                "aquezgdn", "gvqjs", "zxonskkj", "nqbptnoajd", "gcie", "gemczilrx", "fe", "f", "xglquvfz", "cysxrnzd",
                "xdous", "fkkyqrr", "up", "ujgxhvnpv", "tbd", "acwutfftcs", "mkmmmtcup", "oxk", "umzo", "rkzugliuxp",
                "vh", "bzjzbha", "cxb", "iavspo", "dm", "nacwecypkx", "ibld", "qjoynbi", "nroqhuj", "nweajike", "ok",
                "ghaap", "oyayhs", "cffsispcdi", "mezyixgir", "zggq", "hl", "wu", "ubfijs"};
    vector<string> respons = solve.findAllRecipes(recipes, ingredients, supplies);
    unordered_set<string > resSet{respons.begin(), respons.end()};
    unordered_set<string> trueAnswer{answer.begin(), answer.end()};

    unordered_set<string> difference;

    // Проходим по trueAnswer и проверяем наличие в resSet
    for (const auto& elem : trueAnswer) {
        if (resSet.find(elem) == resSet.end()) {
            difference.insert(elem); // Если элемента нет в resSet, добавляем в difference
        }
    }

    // Вывод результата
    for (const auto& elem : difference) {
        std::cout << elem << " ";
    }

//    for (int i = 0; i < answer.size(); ++i) {
//        if (respons[i] != answer[i]) {
//            cout << respons[i] << ". " << answer[i] << "\n";
//            break;
//        }
//    }

//    assert(answer == solve.findAllRecipes(recipes, ingredients, supplies));
//
//    recipes = {"bread"}, ingredients = {{"yeast", "flour"}}, supplies = {"yeast", "flour", "corn"};
//    answer = {"bread"};
//    assert(answer == solve.findAllRecipes(recipes, ingredients, supplies));
//
//    recipes = {"bread", "sandwich"}, ingredients = {{"yeast", "flour"},
//                                                    {"bread", "meat"}}, supplies = {"yeast", "flour", "meat"};
//    answer = {"bread", "sandwich"};
//    assert(answer == solve.findAllRecipes(recipes, ingredients, supplies));
//
//    recipes = {"bread", "sandwich", "burger"}, ingredients = {{"yeast",    "flour"},
//                                                              {"bread",    "meat"},
//                                                              {"sandwich", "meat", "bread"}}, supplies = {"yeast",
//                                                                                                          "flour",
//                                                                                                          "meat"};
//    answer = {"bread", "sandwich", "burger"};
//    sort(answer.begin(), answer.end());
//    assert(answer == solve.findAllRecipes(recipes, ingredients, supplies));

    return 0;
}

