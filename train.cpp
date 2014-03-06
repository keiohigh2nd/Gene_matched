#include "gene_matched.hpp"
#include "gene_matched.cpp"

int main(int argc, char *argv[]) { 
   
	Gene_matched gm;
	std::vector<Layer> nw = gm.train(3,2);

	gm.ignition(nw,start);

}
