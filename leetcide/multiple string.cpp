class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        // Result can be at most n + m digits long
        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }

        string result = "";
        for (int digit : res) {
            // Skip leading zeros
            if (!(result.empty() && digit == 0)) {
                result += to_string(digit);
            }
        }

        return result.empty() ? "0" : result;
    }
};
