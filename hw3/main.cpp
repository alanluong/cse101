#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void bubbleSort(std::vector<int> &v) {
	bool done = false;
	size_t size = v.size();

	while (!done)
	{
		done = true;
		for (size_t i = 0 ; i < size - 1 ; i++)
		{
			if (v[i] > v[i+1])
			{
				done = false;
				std::swap(v[i], v[i+1]);
			}
		}
		size--;
	}
}

int main(int argc, char* argv[])
{
	bool useHeap = false;

	std::cout << argv[2] << std::endl;
	if (std::string(argv[2]) == "heap") {
		useHeap = true;
	}

	std::string num(argv[1]);
	std::stringstream ss(num);
	int n;
	ss >> n;
	int range = 2;

	for (int i = 0; i < n - 1; ++i) {
		range *= 2;
	}

	clock_t t = clock();
	for (int trials = 0; trials < 100; ++trials) {
		std::vector<int> v;

		for (int i = 0; i < range; ++i) {
			v.push_back(1 + rand());
		}

		if (useHeap) {
			std::make_heap(v.begin(), v.end());
			std::sort_heap(v.begin(), v.end());
		} else {
			bubbleSort(v);
		}
	}
	t = clock() - t;
	//std::cout << t / (float) CLOCKS_PER_SEC << std::endl;
	std::cout << range << "\t" << t / (float) CLOCKS_PER_SEC << std::endl;

	/*
	   for (int i = 0; i < v.size(); ++i) {
	   std::cout << v[i] << std::endl;
	   }
	   */

	return 0;
}
