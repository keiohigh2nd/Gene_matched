#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "gene_matched.hpp"

int get_random(const int up){
	return rand() % up; 
}

Cell Gene_matched::generate_cell(int layer_num) {
	int up = 5;
	int gene_num = 2;

	Cell cell;
	for (size_t i=0; i < gene_num;++i){
		cell.genes.push_back(get_random(up));	
	}
	cell.layer_num = layer_num;

	return cell;
}

std::vector<Layer> Gene_matched::train(int lay_num, int cols){
	std::cout << lay_num << "layers" << cols << "boxes" << std::endl;
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
	return rand() % 2;
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
			}
		}
	}
	return 0;
}

int add_next_layer(Layer& layer, Cell& cell){
	for(size_t i=0; i < layer.box.size(); ++i){
		///std::cout << "Next Box number" << i <<std::endl;
		find_gene_set(cell,layer.box[i]);	
	}
	return 0;
}

Layer get_result(std::vector<Layer>& layers){
	for(size_t k=0; k < layers.size()-1; ++k){
		///std::cout << "Layer number" << k << std::endl;
		for(size_t i=0; i < layers[k].box.size(); ++i) {
			///std::cout << "Box number" << i << std::endl;
			if (layers[k].box[i].val == 1) {
				add_next_layer(layers[k+1],layers[k].box[i]);
			}
		}
	}
	int tmp = layers.size()-1;
	return layers[tmp];
}

void test_end(Layer& layer){
	
        for(size_t i=0; i < layer.box.size();++i){
              std::cerr <<  layer.box[i].val;
        }
	std::cerr << "-----"<< std::endl;	
}

void show_layers(std::vector<Layer>& layers){
        for(size_t i=0; i < layers.size();++i) {
                test_end(layers[i]);
        }
}

Layer Gene_matched::ignition(std::vector<Layer>& layers, std::vector<int>& start){
	Layer end;
	if (layers[0].box.size() != start.size()){
		std::cout << "Wrong input dimension" << std::endl;
		return end;	
	}

	for(size_t i=0; i < start.size(); ++i){
		layers[0].box[i].val = start[i];
	}

	end = get_result(layers);
	show_layers(layers);
	return end;
}


