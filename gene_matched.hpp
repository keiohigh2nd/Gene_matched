#pragma once

#include <vector>

struct Cell {
	std::vector<int> genes;
	int val;
	int layer_num;
};

struct Layer {
	int label;
	std::vector<Cell> box;
};

class Gene_matched {
	public:
		Gene_matched() {};
		~Gene_matched() {};

		std::vector<Layer> train(int lay_num,int cols);
		Cell generate_cell(int layer_num);

		Layer ignition(std::vector<Layer>& layers, std::vector<int>& start);
};
