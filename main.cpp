#include <iostream>
#include <array>
#include <cstdlib>
#include <cassert>

struct Position
{
	std::size_t row{ 0 };
	std::size_t col{ 0 };
};

template <typename T, std::size_t Col, std::size_t Row>

Position findPosition(const std::array<std::array<T, Col>, Row>& array2D)
{
	Position position{};

        for(const auto& arrRow: array2D)
        {
                for(const auto& arrCol: arrRow)
                {
                       	if(arrCol == 0)
				return position;
			++position.col;
                }
		position.col = 0;
                ++position.row;
        }
}

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

template <typename T, std::size_t Col, std::size_t Row>

void moveTile(std::array<std::array<T, Col>, Row>& array2D)
{
	Position position{ findPosition(array2D) };
	//assert(position.row == 0 && position.col == 0);

	std::cout << position.row << '\t' << position.col << '\n';
}

int main()
{
	std::array<std::array<int, 3>, 3> gameBoard{{
		{8, 1, 2},
	       	{3, 4, 5},
	       	{6, 7, 0}
	}};

	printArray(gameBoard);
	moveTile(gameBoard);


	return EXIT_SUCCESS;
}
