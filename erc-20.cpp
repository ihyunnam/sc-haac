#include <cstdint>
#include <iostream>

// Simulate uint256 using a 256-bit unsigned integer type.
// If your system doesn't have builtins, use a big-int library (Boost.Multiprecision, etc.)

using uint256 = unsigned __int128;  // For demo. Replace with 256-bit type in real experiments.

// CPU-native ERC20 transfer check
uint256 erc20_transfer(uint256 balance, uint256 amount) {
    if (balance >= amount) {
        return balance - amount;
    } else {
        return balance; // unchanged
    }
}

int main() {
    uint256 bal = 1000;
    uint256 amt = 300;

    uint256 new_bal = erc20_transfer(bal, amt);
    std::cout << (unsigned long long)new_bal << std::endl;
}
