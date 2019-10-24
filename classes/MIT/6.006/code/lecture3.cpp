#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>

/*
 * Insertion sort sucks. O(N^2) runtime, compared to the
 * much better O(N log N) of std::sort. This is an exercise,
 * and a largely pointless one, but it's hard not to love 
 * the simplicity of this implementation.
 */
void insertionSort(std::vector<int> &nums) {
	for(auto i = nums.begin(); i != nums.end(); i++) {
		auto const ip = std::upper_bound(nums.begin(), i, *i);
		std::rotate(ip, i, i+1);
	}
}

/*
 * We can do a bit better. Merge sort!
 * This is a classic divide and conquer algorithm.
 */
std::vector<int> mergeSort(
		std::vector<int> *left,
		std::vector<int> *right
) {
	std::vector<int> result(left->size() + right->size());

	auto result_index = result.begin();

	auto left_front = left->begin();
	auto left_back = right->end();
	auto right_front = right->begin();
	auto right_back = right->end();

	do {
		if (*left_front < *right_front) {
			*result_index = *left_front;
			left_front++;
		} else {
			*result_index = *right_front;
			right_front++;
		}
		result_index++;
	} while(left_front != left_back && right_front != right_back);

	if (left_front != left_back) {
		std::copy(left_front, left_back, result_index);
	}
	if (right_front != right_back) {
		std::copy(right_front, right_back, result_index);
	}

	return result;
}

int main(int argc, char *argv[]) {
	std::vector<int> nums1 = std::vector<int>(10);
	std::vector<int> nums2 = std::vector<int>(5);

	std::random_device rnd_dev;
	std::default_random_engine rnd_eng;
	std::uniform_int_distribution<int> rnd_dst{1, 52};
	auto gen = [&rnd_dst, &rnd_eng]() {
		return rnd_dst(rnd_eng);
	};
	

	std::generate(nums1.begin(), nums1.end(), gen);
	std::generate(nums2.begin(), nums2.end(), gen);

	/*
	 * The easy way to do this:
	 *
	 * std::sort(nums1.begin(), nums1.end());
	 * std::sort(nums2.begin(), nums2.end());
	 *
	 * But we'll use insertion sort here!
	 * It's quite a bit slower, but that's not the point.
	 *
	 */

	insertionSort(nums1);
	insertionSort(nums2);

	for(int num: nums1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	for(int num: nums2) {
		std::cout << num << " ";
	}
	std::cout << std::endl;


	// And, again, we could just do std::merge() 
	std::vector<int> output = mergeSort(&nums1, &nums2);

	for(int num: output) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
