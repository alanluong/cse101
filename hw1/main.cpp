#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	srand(time(0));
	std::vector<int> v;

	std::string num(argv[2]);
	std::stringstream ss(num);
	int n;
	ss >> n;

	if (argv[1] == "sorted") {
		for (int i = 0; i < n; ++i) {
			v.push_back(n);
		}
	} else {
		for (int i = 0; i < n; ++i) {
			v.push_back(rand() % (int)1e6);
		}
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			std::binary_search(v.begin(), v.end(), v[i] + v[j]);
		}
	}

	return 0;
}
