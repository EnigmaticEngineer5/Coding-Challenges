#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string toGoatLatin(string sentence) {
		vector<string> words{};
		while (!sentence.empty()) {
			size_t wordPos{ sentence.find(' ') };
			words.emplace_back(sentence.substr(0, wordPos));
			sentence.erase(0, (wordPos + 1));

			if (wordPos == -1) {
				sentence.erase();
			}
		}

		int counter{ 1 };
		for (auto& it : words) {
			if (it[0] == 'a' || it[0] == 'A' || it[0] == 'e' ||
				it[0] == 'E' || it[0] == 'i' || it[0] == 'I' || it[0] == 'o'
				|| it[0] == 'O' || it[0] == 'u' || it[0] == 'U') {
				it.append("ma");
			}
			else {
				string firstLetter{ it[0] };
				it.erase(0, 1);
				it.append(firstLetter + "ma");
			}

			string letter{ 'a' };
			for (int i{}; i < counter; i++) {
				it.append(letter);
			}
			it.append(" ");
			counter++;
		}

		for (const auto& it : words) {
			sentence += it;
		}
		sentence.erase((sentence.size() - 1), 1);
		return sentence;
	}
};

int main() {
	Solution str;
	string goatLatin{ str.toGoatLatin("I speak Goat Latin") };
	cout << goatLatin;

	return 0;
}