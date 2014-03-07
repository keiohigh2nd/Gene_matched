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

std::vector<Layer> Gene_matched::train(int lay_num, int cols){
	std::vector<Layer> layers;
	for(size_t i=0; i < lay_num; ++i) {
		///std::vector<Cell> layer;
		Layer layer;
		layer.label = i;
		for(size_t j=0; j < cols;  ++j) {
			Cell cell = generate_cell(i);
			layer.box.push_back(cell);
		}
		layers.push_back(layer);
	}
	return layers;
}

int get_binary(){
	return rand() % 1;
}

std::vector<int> easy_test(int box_size){
	std::vector<int> start;
	for(size_t i =0; i < box_size; ++i){
		start.push_back(get_binary());
	}
	return start;
}

int find_gene_set(Cell& cell_a, Cell& cell_b){
	for(size_t i=0; i < cell_a.genes.size(); ++i){
		for(size_t j=0; j < cell_b.genes.size(); ++j){
			if (cell_a.genes[i] == cell_b.genes[j]) {
				cell_b.val += 1;
				return 0
			}
		}
	}
}

void add_next_layer(Layer& layer, Cell& cell){
	for(size_t i=0; layer.box.size(); ++i){
		find_gene_set(layer.box[i],cell);	
	}
}

std::vector<int> get_result(std::vector<Layer>& layers){
	for(size_t k=0; k < layers.size(); ++k){
		for(size_t i=0; i < layers[0].box.size(); ++i) {
			if (layers[k].box[i].val == 1) {
				add_next_layer(layers[k+1],layers[k].box[i]);
			}
		}
	}
	return layers[layers.size()-1]
}

std::vector<int> Gene_matched::ignition(std::vector<Layer>& layers, std::vector<int> start){
	if (layers[0].box.size() != start.size()){
		std::cout << "Wrong input dimension" << std::endl;
		return 0
	}

	for(size_t i=0; i < start.size(); ++i){
		layers[0].box[i].val = start[i]	
	}

	std::vector<int> end;
	end = get_result(layers);

	return end;
}

