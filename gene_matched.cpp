#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "gene_matched.hpp"

int get_random(const int up){
	return rand() % up; 
}

Cell Gene_matched::generate_cell(int layer_num) {
	int up = 10;
	int gene_num = 2;

	Cell cell;
	for (size_t i=0; i < gene_num;++i){
		cell.genes.push_back(get_random(up));	
	}
	cell.layer_num = layer_num;

	return cell;
}

void Gene_matched::train(int lay_num, int cols){
	std::vector<std::vector<Cell> >layers;
	for(size_t i=0; i < lay_num; ++i) {
		std::vector<Cell> layer;
		for(size_t j=0; j < cols;  ++j) {
			Cell cell = generate_cell(i);
			layer.push_back(cell);
		}
		layers.push_back(layer);
	}

} 

