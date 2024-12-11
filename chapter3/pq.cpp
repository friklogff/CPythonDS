//
// Created by admin on 9/10/2024.
//
#include <iostream>
#include <vector>
#include <queue>

int findKthLargest(std::vector<int>& nums, int k) {
    // 使用一个最大堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int num : nums) {
        // 将每个元素添加到最大堆中
        pq.push(num);
        // 如果堆的大小超过了 k，弹出堆顶元素
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // 堆顶元素即为第 k 个最大元素
    return pq.top();
}

int main() {
    std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    std::cout << findKthLargest(nums1, k1) << std::endl; // 输出: 5

    std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    std::cout << findKthLargest(nums2, k2) << std::endl; // 输出: 4

    return 0;
}
