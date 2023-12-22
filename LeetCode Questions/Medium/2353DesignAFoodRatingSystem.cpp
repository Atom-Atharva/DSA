// https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2023-12-17

#include <set>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Info
{
    string name;
    string cuisine;
    int rating{};

    Info() = default;
    Info(string name, string cuisine, int rating) : name{name}, cuisine{cuisine}, rating{rating} {}

    bool operator<(const Info &first) const
    {
        if (rating == first.rating)
        {
            return name < first.name;
        }
        return rating > first.rating;
    }
};

class FoodRatings
{

    unordered_map<string, Info> foodNameToInfo;
    unordered_map<string, set<Info>> cuisineNameToSortedInfo;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (size_t i = 0; i < foods.size(); ++i)
        {
            foodNameToInfo.emplace(foods[i], Info(foods[i], cuisines[i], ratings[i]));
            cuisineNameToSortedInfo[cuisines[i]].emplace(foods[i], cuisines[i], ratings[i]);
        }
    }

    void changeRating(const string &food, int newRating)
    {
        Info &toUpdate = foodNameToInfo[food];
        cuisineNameToSortedInfo[toUpdate.cuisine].erase(toUpdate);
        toUpdate.rating = newRating;
        cuisineNameToSortedInfo[toUpdate.cuisine].insert(toUpdate);
    }

    string highestRated(const string &cuisine) const
    {
        return cuisineNameToSortedInfo.at(cuisine).begin()->name;
    }
};

// #include <iostream>
// using namespace std;
// #include <vector>
// #include <tuple>
// #include <algorithm>

// class FoodRatings
// {
//     // Vector of Tuples--
//     vector<tuple<string, int, string>> food;

//     bool customCompare(tuple<string, int, string> t1, tuple<string, int, string> t2)
//     {
//         // Same Cuisine Higher Rating First--
//         if (get<0>(t1) == get<0>(t2))
//         {
//             // Lexicographically smaller first--
//             if (get<1>(t1) == get<1>(t2))
//             {
//                 return (get<2>(t1) < get<2>(t2));
//             }

//             return (get<1>(t1) >= get<1>(t2));
//         }

//         // According to Cuisine--
//         return (get<0>(t1) < get<0>(t2));
//     }

// public:
//     FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
//     {
//         // Push in Vector--
//         for (int i = 0; i < foods.size(); i++)
//         {
//             food.push_back(make_tuple(cuisines[i], ratings[i], foods[i]));
//         }

//         // Sort Vector--
//         sort(this->food.begin(), this->food.end(), [this](const auto &t1, const auto &t2)
//              { return customCompare(t1, t2); });
//     }

//     void changeRating(string food, int newRating)
//     {
//         for (int i = 0; i < this->food.size(); i++)
//         {
//             if (get<2>(this->food[i]) == food)
//             {
//                 get<1>(this->food[i]) = newRating;
//                 break;
//             }
//         }
//         // Sort Vector--
//         sort(this->food.begin(), this->food.end(), [this](const auto &t1, const auto &t2)
//              { return customCompare(t1, t2); });
//     }

//     string highestRated(string cuisine)
//     {
//         for (int i = 0; i < food.size(); i++)
//         {
//             if (get<0>(food[i]) == cuisine)
//             {
//                 return get<2>(food[i]);
//             }
//         }
//         return "";
//     }
// };

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */