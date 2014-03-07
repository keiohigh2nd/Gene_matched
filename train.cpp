#include "gene_matched.hpp"
#include "gene_matched.cpp"

int main(int argc, char *argv[]) { 
   
	Gene_matched gm;
	std::vector<Layer> nw = gm.train(5,6); ///(Number of Layer, Cells of one Layer)

	std::vector<int> start;
	start = easy_test(6);
	Layer end;
	end = gm.ignition(nw,start);

	///test_end(end);

	return 0;
}
