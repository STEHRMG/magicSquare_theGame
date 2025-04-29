#include <iostream>
#include <array>
#include <cstdlib>

int main()
{
	[[maybe_unused]] std::array<std::array<int, 3>, 3> gameBoard{{
		{0, 1, 2},
	       	{3, 4, 5},
	       	{6, 7, 8}
	}};

	return EXIT_SUCCESS;
}
