#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store sorted string as key and original strings as values
        unordered_map<string, vector<string>> groups;
        
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // Sort to create the unique key
            groups[key].push_back(s);     // Add original string to its group
        }
        
        // Extract groups from the map into the result vector
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
