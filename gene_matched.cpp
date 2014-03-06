#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "Gene_matched.hpp"

int get_random(const int up){
	return rand() % up 
}

Cell generate_cell(int layer_num) const{
	int up;

	Cell cell;
	for (size_t i=0; i < gene;++i){
		cell.genes.push_back(get_random(up));	
	}
	cell.layer_num = layer_num;

	return cell;
}

void train(int lay_num, int cols){
	for(size_t i=0; i < lay_num; ++i) {
		for(size_t j=0; j < cols;  ++j) {
			Cell cell = generate_cell(i);	
		}
	}

} 

