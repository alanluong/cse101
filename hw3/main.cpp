#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

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
	std::vector<int> v;
	bool useHeap = false;

	std::string num(argv[1]);
	std::stringstream ss(num);
	int n;
	ss >> n;
	int range = 2;

	for (int i = 0; i < n - 1; ++i) {
		 range *= 2;
	}
	std::cout << range << std::endl;
	
	std::cout << argv[2] << std::endl;
	if (std::string(argv[2]) == "heap") {
		useHeap = true;
	}

	for (int i = 0; i < range; ++i) {
		v.push_back(1 + rand());
	}

	if (useHeap) {
		std::cout << "heapSort" << std::endl;
		std::make_heap(v.begin(), v.end());
		std::sort_heap(v.begin(), v.end());
	} else {
		std::cout << "bubbleSort" << std::endl;
		bubbleSort(v);
	}

	/*
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;
	}
	*/

	return 0;
}
