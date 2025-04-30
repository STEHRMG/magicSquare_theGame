#include <iostream>
#include <array>
#include <cstdlib>
#include <cassert>
#include <limits>

struct Position
{
	std::size_t row{ 0 };
	std::size_t col{ 0 };
	int value{ 0 };
};

template <typename T, std::size_t Col, std::size_t Row>

Position findPosition(const std::array<std::array<T, Col>, Row>& array2D)
{
	Position position{};
	position.value = 0;

        for(const auto& arrRow: array2D)
        {
                for(const auto& arrCol: arrRow)
                {
                       	if(arrCol == 0)
			{
				return position;
			}
			++position.col;
                }
		position.col = 0;
                ++position.row;
        }
	assert(false);
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
	
	char move{};
	std::cout << "Enter your move('w', 'a', 's', 'd'): ";

	while(true)
	{
		std::cin >> move;

		if(!std::cin || (!std::cin.eof() && std::cin.peek() != '\n'))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again: ";
			continue;
		}

		if(move == 'a')
		{
			if((position.col - 1) > 2)
			{
				std::cout << "Invalid input, try again: ";
				continue;
			}

			int val{array2D[position.row][position.col - 1]};
			array2D[position.row][position.col - 1] = position.value;
			array2D[position.row][position.col] = val;

			return;
		}
		else if(move == 'd')
		{
			if((position.col + 1) > 2)
			{
				std::cout << "Invalid input, try again: ";
				continue;
			}
			
			int val{array2D[position.row][position.col + 1]};
			array2D[position.row][position.col + 1] = position.value;
			array2D[position.row][position.col] = val;

			return;
		}
		else if(move == 'w')
		{
			if((position.row - 1) > 2)
			{
				std::cout << "Invalid input, try again: ";
				continue;
			}
		
			int val{array2D[position.row - 1][position.col]};
			array2D[position.row - 1][position.col] = position.value;
			array2D[position.row][position.col] = val;

			return;
		}
		else if(move == 's')
		{
			if((position.row + 1) > 2)
			{
				std::cout << "Invalid input, try again: ";
				continue;
			}
			
			int val{array2D[position.row + 1][position.col]};
			array2D[position.row + 1][position.col] = position.value;
			array2D[position.row][position.col] = val;

			return;
		}

		std::cout << "Invalid input, try again: ";
	}
}

template <typename T, std::size_t Col, std::size_t Row>

bool isSolved(std::array<std::array<T, Col>, Row>& array2D)
{
	T comp{ 1 };
	for(auto& arr: array2D)
	{
		for(auto& el: arr)
		{
			if(comp != el)
			{
				return false;
			}
			if(comp == 8)
			{
				comp -= 8;
				continue;	
			}
			++comp;
		}
	}

	return true;
}

int main()
{
	std::array<std::array<int, 3>, 3> gameBoard{{
		{1, 2, 3},
	       	{4, 5, 6},
	       	{0, 7, 8}
	}};
	
	printArray(gameBoard);
	while(!isSolved(gameBoard))
	{
		moveTile(gameBoard);
		std::system("clear");
		printArray(gameBoard);
	}

	std::cout << "Congratulation, you solved it!\n";

	return EXIT_SUCCESS;
}
