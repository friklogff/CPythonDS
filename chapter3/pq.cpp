//
// Created by admin on 9/10/2024.
//
#include <iostream>
#include <vector>
#include <queue>

int findKthLargest(std::vector<int>& nums, int k) {
    // ʹ��һ������
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int num : nums) {
        // ��ÿ��Ԫ����ӵ�������
        pq.push(num);
        // ����ѵĴ�С������ k�������Ѷ�Ԫ��
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // �Ѷ�Ԫ�ؼ�Ϊ�� k �����Ԫ��
    return pq.top();
}

int main() {
    std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    std::cout << findKthLargest(nums1, k1) << std::endl; // ���: 5

    std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    std::cout << findKthLargest(nums2, k2) << std::endl; // ���: 4

    return 0;
}
