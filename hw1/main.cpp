#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<long long> dis;

	std::vector<int> v;

	std::string num(argv[2]);
	std::stringstream ss(num);
	long long n, range;
	ss >> n;

	if (std::string(argv[1]) == "small") {
		range = n;
	} else {
		range = n * n * n;
	}

	for (int i = 0; i < n; ++i) {
		v.push_back(1 + dis(gen) % range);
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			if (i == j) continue;
			std::binary_search(v.begin(), v.end(), v[i] + v[j]);
		}
	}

	return 0;
}
