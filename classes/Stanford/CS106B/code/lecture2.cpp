#include <iostream>
#include <vector>
#include <random>
#include <functional>

const int NumScores = 10;

// Questionable forward declarations for academic purposes.
double GetScoresAndAverage(std::vector<int> scores);
std::vector<int> GenerateRandomScores(int NumScores);

int main() {
	std::cout << "This program averages " << NumScores << " scores." << std::endl;
	std::vector<int> scores = GenerateRandomScores(NumScores);
	double average = GetScoresAndAverage(scores);
	std::cout << "The average is: " << average << std::endl;
	return 0;
}

double GetScoresAndAverage(std::vector<int> scores) {
	double result = 0.0;
	int sum = 0;
	for(int i: scores) {
		sum += i;
	}
	result = double(sum) / scores.size();
	return result;
};

std::vector<int> GenerateRandomScores(int NumScores) {
	std::vector<int> result(NumScores);
	std::mt19937 rnd_eng;
	std::uniform_int_distribution<int> rnd_dst{1, 100};
	auto gen = std::bind(rnd_dst, rnd_eng);
	/*
	 * This syntax rocks.
	 * "Automatically take the address of I for each item in the result"
	 *
	 */
	for(auto &i: result) {
		i = gen();
	}
	// Yes, I do realize I could've done this in the previous loop.
	for (auto &i: result) {
		std::cout << i << std::endl;
	}
	return result;

}
