#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

/*
 * Insertion sort sucks. O(N^2) runtime, compared to the
 * much better O(N log N) of std::sort. This is an exercise,
 * and a largely pointless one, but it's hard not to love 
 * the simplicity of this implementation.
 */
void insertionSort(std::vector<int> &nums) {
	for(auto i = nums.begin(); i!= nums.end(); i++) {
		auto const ip = std::upper_bound(nums.begin(), i, *i);
		std::rotate(ip, i, i+1);
	}
}

/*
 * We can do a bit better. Merge sort!
 * This is a classic divide and conquer algorithm.
 */
std::vector<int> mergeSort(
		std::vector<int> &nums1,
		std::vector<int> &nums2)
{
	std::vector<int> result(nums1.size() + nums2.size());

	auto r = result.begin();

	auto f1 = nums1.begin();
	auto f2 = nums2.begin();
	auto l1 = nums1.end();
	auto l2 = nums2.end();

	for(;f1 != l1;r++) {
		/*
		 * If our second array is empty, we can just return our
		 * first array since it is already sorted.
		 */
		if (f2 == l2) {
			std::copy(f1, l1, r);
			break;
		}
		/* Now we compare and move forward... */
		if (*f2 < *f1) {
			*r = *f2;
			f2++;
		} else {
			*r = *f1;
			f1++;
		}
	}

	std::copy(f2, l2, r);

	return result;

}

int main(int argc, char *argv[]) {
	std::vector<int> nums1(10);
	std::vector<int> nums2(5);

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

	for(auto num: nums1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	for(auto num: nums2) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	// And, again, we could just do std::merge() 
	std::vector<int> output = mergeSort(nums1, nums2);

	for(auto num: output) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
