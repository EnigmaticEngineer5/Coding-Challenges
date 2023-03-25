#include <iostream>
#include <vector>

int main() {
	std::string str{ "My name is Carlos" };
	std::vector<std::string> words{};

	while (!str.empty()) {
		size_t wordPos{ str.find(' ') };
		words.emplace_back(str.substr(0, wordPos));
		str.erase(0, (wordPos + 1));

		if (wordPos == -1) {
			str.erase();
		}
	}

	for (auto& it : words) {
		std::string firstLetter{ it.at(0) };
		it.append(firstLetter);
		it.erase(0, 1);
		it.append("ay");
	}

	for (const auto& it : words) {
		std::cout << it << ' ';
	}

	return 0;
}