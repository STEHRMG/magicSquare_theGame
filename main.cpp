#include <iostream>
#include <array>
#include <cstdlib>

template <typename T, std::size_t Col, std::size_t Row>

void printArray(const std::array<std::array<T, Col>, Row>& array2D)
{
	for(const auto& arrRow: array2D)
	{
		for(const auto& arrCol: arrRow)
		{
			std::cout << arrCol << '\t';
		}
		std::cout << '\n';
	}
}

int main()
{
	std::array<std::array<int, 3>, 3> gameBoard{{
		{0, 1, 2},
	       	{3, 4, 5},
	       	{6, 7, 8}
	}};

	printArray(gameBoard);

	return EXIT_SUCCESS;
}
