// Q) A circus is designing a tower routine consisting of people standing atop one another’s shoulders.
// For practical and aesthetic reasons, each person must be both shorter and lighter than the person
// below him or her. Given the heights and weight of each circus, write a method to compute the largest
// possible number of people in such tower.
// EXAMPLE:
// Input(ht,wt): (65, 100) (70, 150) (56, 90) (75,190) (60, 95) (68, 110).
// Output: The longest tower is length 6 and includes from top to bottom:
// (56, 90) (60, 95) (65, 100) (68, 110) (70, 150) (75, 190)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a struct for person
struct Person
{
    int height;
    int weight;

    Person(int h, int w) : height(h), weight(w) {}
};

// Custom comparison: sort by height, and if equal, by weight
bool compare(const Person &a, const Person &b)
{
    if (a.height == b.height)
        return a.weight < b.weight;
    return a.height < b.height;
}

// Function to find longest tower
vector<Person> longestTower(vector<Person> &people)
{
    // Step 1: Sort by height and weight
    sort(people.begin(), people.end(), compare);

    // Step 2: Apply LIS on weight
    int n = people.size();
    vector<int> dp(n, 1);    // dp[i] = length of LIS ending at i
    vector<int> prev(n, -1); // To reconstruct path

    int maxLen = 1, maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (people[j].weight < people[i].weight && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            maxIndex = i;
        }
    }

    // Reconstruct the longest sequence
    vector<Person> result;
    for (int i = maxIndex; i != -1; i = prev[i])
        result.push_back(people[i]);

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<Person> people = {
        {65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95}, {68, 110},{100,200}};

    vector<Person> tower = longestTower(people);

    cout << "Longest tower length: " << tower.size() << endl;
    cout << "Tower from top to bottom:" << endl;
    for (const auto &p : tower)
        cout << "(" << p.height << ", " << p.weight << ")" << endl;

    return 0;
}
