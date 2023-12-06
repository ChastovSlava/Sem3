#include "DSU.h"
#include <iostream>

int main() {
	int field[5][7] = {
	{1, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 0, 0},
	{0, 0, 1, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 1}
	};

	dsu disjointSet;

	// Бегит по массиву
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			// Если ячейка принадлежит острову (имеет значение 1)
			if (field[i][j] == 1) {
				int currentIndex = i * 7 + j+ 1;

				// Проверяем соседние ячейки и объединяем их, если они также принадлежат острову
				if (i > 0 && field[i - 1][j] == 1) {
					int topIndex = (i - 1) * 7 + j + 1;
					disjointSet.Union(currentIndex, topIndex);
				}
				if (j > 0 && field[i][j - 1] == 1) {
					int leftIndex = i * 7 + (j - 1) + 1;
					disjointSet.Union(currentIndex, leftIndex);
				}
			}
		}
	}

	// Подсчитываем количество уникальных островов
	int islandCount = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (field[i][j] == 1) {
				int currentIndex = i * 7 + j + 1;
				if (disjointSet.find(currentIndex) == currentIndex) {
					islandCount++;
				}
			}
		}
	}

	std::cout << "Number of islands: " << islandCount << std::endl;

	return 0;
}