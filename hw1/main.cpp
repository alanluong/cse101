#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	srand(time(0));
	std::vector<int> v1, v2;

	std::string num(argv[1]);
	std::stringstream ss(num);
	int n;
	ss >> n;
	std::cout << n << std::endl;

	for (int i = 0; i < n; ++i) {
		v1.push_back(n);
		v2.push_back(rand() % (int)1e6);
	}

	return 0;
}
