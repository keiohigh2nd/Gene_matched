#pragma once

#include <vector>

struct Cell {
	std::vector<int> genes;
	int from_num;
	int to_num;
	int layer_num;
}

struct Layer {
	int label;
}

class Gene_matched {
	public:
		Gene_matched() {};
		~Gene_matched() {};

		void init(int lay_num,int gene_type);

};
