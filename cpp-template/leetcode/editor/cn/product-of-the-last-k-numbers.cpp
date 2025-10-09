/*
 * @lc app=leetcode.cn id=1352 lang=cpp
 * @lcpr version=
 *
 * [1352] 最后 K 个数的乘积
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class ProductOfNumbers {
vector<int> preProduct;
public:
    ProductOfNumbers() {
        preProduct.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            preProduct.clear();
            preProduct.push_back(1);
            return;
        }

        int p = preProduct.back();
        preProduct.push_back(p * num);
    }
    
    int getProduct(int k) {
        int n = preProduct.size();
        if (k >= n) return 0;
        // preProduct[i] 0..i
        return preProduct[n - 1] / preProduct[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

int main() {
    ProductOfNumbers p;
    p.add(3);
    p.add(0);
    p.add(2);
    p.add(5);
    p.add(4);
    p.getProduct(2);
    // your test code here
}



/*
// @lcpr case=start
// ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]\n[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]\n
// @lcpr case=end

 */

