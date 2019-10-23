#include <iostream>

int main() {
	/*
	 * String has a default initializer.
	 * It's just empty "" by default.
	 */
	std::string s;
	/*
	 * We can use array notation to access a string.
	 * operator[] is extant on the string class.
	 */
	s = "cs106b";
	std::cout << "Our s[1] character is: " << s[1] << std::endl;
	std::cout << "Hello there, World!" << std::endl;

	return 0;
}
