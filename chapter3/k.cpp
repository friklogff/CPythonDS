#include <iostream>
#include <vector>
#include "PriorityQueue.h"

int findKthLargest(std::vector<int> &nums, int k) {
	PriorityQueue<int> pq;

	for (int num : nums) {
		pq.Push(num, num);
		if (pq.Size() > k) {
			pq.Pop();
		}
	}

	return pq.Top();
}

int main() {
	std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
	int k1 = 2;
	std::cout << "输入: [3, 2, 1, 5, 6, 4], k = 2" << std::endl;
	std::cout << "输出: " << findKthLargest(nums1, k1) << std::endl;

	std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
	int k2 = 4;
	std::cout << "输入: [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4" << std::endl;
	std::cout << "输出: " << findKthLargest(nums2, k2) << std::endl;

	return 0;
}
