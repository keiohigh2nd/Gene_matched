#include "gene_matched.hpp"
#include "gene_matched.cpp"

int main(int argc, char *argv[]) { 
   
	Gene_matched gm;
	std::vector<Layer> nw = gm.train(3,2);

	std::vector<int> start;
	start = easy_test(2);
	Layer end;
	end = gm.ignition(nw,start);

	std::cout << end.box.size() << std::endl;

	return 0;
}
