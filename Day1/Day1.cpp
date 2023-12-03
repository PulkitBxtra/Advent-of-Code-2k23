#include <iostream>
#include <unordered_map>
using namespace std;

int sum = 0;

string preprocessLR(string str) {
    unordered_map<string, int> map;

    map.insert({"one", 1});
    map.insert({"two", 2});
    map.insert({"three", 3});
    map.insert({"four", 4});
    map.insert({"five", 5});
    map.insert({"six", 6});
    map.insert({"seven", 7});
    map.insert({"eight", 8});
    map.insert({"nine", 9});
    map.insert({"zero", 0});

    int n = str.size();
    string result = "";
    int i = 0;

    while (i < n) {
        bool found = false;
        for (const auto& entry : map) {
            const string& word = entry.first;
            const int value = entry.second;

            if (str.substr(i, word.size()) == word) {
                result += to_string(value);
                i += word.size();
                found = true;
                break;
            }
        }

        if (!found) {
            if (isdigit(str[i])) {
                result += str[i];
            }
            i++;
        }
    }

    return result;
}

string preprocessRL(string str) {
    unordered_map<string, int> map;

    map.insert({"one", 1});
    map.insert({"two", 2});
    map.insert({"three", 3});
    map.insert({"four", 4});
    map.insert({"five", 5});
    map.insert({"six", 6});
    map.insert({"seven", 7});
    map.insert({"eight", 8});
    map.insert({"nine", 9});
    map.insert({"zero", 0});

    int n = str.size();
    string result = "";
    int i = n - 1;

    while (i >= 0) {
        bool found = false;
        for (const auto& entry : map) {
            const string& word = entry.first;
            const int value = entry.second;

            if (i + 1 >= word.size() && str.substr(i - word.size() + 1, word.size()) == word) {
                result = to_string(value) + result;
                i -= word.size();
                found = true;
                break;
            }
        }

        if (!found) {
            if (isdigit(str[i])) {
                while (i >= 0 && isdigit(str[i])) {
                    result = str[i] + result;
                    i--;
                }
            } else {
                i--;
            }
        }
    }

    return result;
}

int main() {
    string str;

    while (cin >> str) {
        int left_a, right_a;
        bool left = false;
        bool right = false;

        string newStr = preprocessLR(str);
        string newStr2 = preprocessRL(str);
        int n = newStr.size();

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (!left) {
                if (newStr[l] >= '0' && newStr[l] <= '9') {
                    left_a = newStr[l] - '0';
                    left = true;
                }
                l++;
            }

            if (!right) {
                if (newStr2[r] >= '0' && newStr2[r] <= '9') {
                    right_a = newStr2[r] - '0';
                    right = true;
                }
                r--;
            }

            if (right && left) {
                break;
            }
        }

        if (left && right) {
            int ans = left_a * 10 + right_a;
            cout << ans << endl;
            sum += ans;
        } else if (left && !right) {
            int ans = left_a * 10 + left_a;
            cout << ans << endl;
            sum += ans;
        } else if (right && !left) {
            int ans = right_a * 10 + right_a;
            cout << ans << endl;
            sum += ans;
        } else {
            cout << "Digits not found" << endl;
        }
    }

    cout << sum << endl;

    return 0;
}
