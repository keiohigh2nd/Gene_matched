#include "gene_matched.hpp"
#include "gene_matched.cpp"

int main(int argc, char *argv[]) { 
   
	Gene_matched gm;
	std::vector<Layer> nw = gm.train(10,10);

	std::vector<int> start;
	start = easy_test(10);
	Layer end;
	end = gm.ignition(nw,start);

	///test_end(end);
	std::cout << "box size" <<end.box.size() << std::endl;

	return 0;
}
