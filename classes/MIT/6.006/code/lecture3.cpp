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
		std::vector<int> *nums1,
		std::vector<int> *nums2
) {
	std::vector<int> result(nums1->size() + nums2->size());

	auto r = result.begin();

	auto l1 = nums1->begin();
	auto r1 = nums2->begin();
	auto l2 = nums1->end();
	auto r2 = nums2->end();

	do {
		if (*l1 < *r1) {
			*r = *l1;
			l1++;
		} else {
			*r = *r1;
			r1++;
		}
		r++;
	} while(l1 != l2 && r1 != r2);

	if (l1 != l2) {
		std::copy(l1, l2, r);
	}
	if (r1 != r2) {
		std::copy(r1, r2, r);
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
