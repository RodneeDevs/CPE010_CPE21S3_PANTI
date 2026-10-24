#include <iostream>
#include <algorithm>

const int MAX = 1000;
int memo[MAX];

int getMinimumSteps(int n) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n]; 
    int r = 1 + getMinimumSteps(n - 1); 
    if (n % 2 == 0) {
        r = std::min(r, 1 + getMinimumSteps(n / 2)); 
    }
    if (n % 3 == 0) {
        r = std::min(r, 1 + getMinimumSteps(n / 3));
    }

    memo[n] = r; 
    return r;
}

int getMinSteps(int n) {
    int* dp = new int[n + 1];
    dp[1] = 0; 

    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) {
            dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        }
        if (i % 3 == 0) {
            dp[i] = std::min(dp[i], 1 + dp[i / 3]);
        }
    }

    int result = dp[n];
    delete[] dp; 
    return result;
}

int main() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }

    int n = 10;
    std::cout << getMinimumSteps(n) << std::endl; 

    int j = 20;
    std::cout << getMinSteps(j) << std::endl;        

    
    return 0;
}