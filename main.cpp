#include<iostream>
#include"page.hpp"
#include "pageloader.hpp"


int main() {
	std::string url("https://www.cplusplus.com/");
	std::cout << url << std::endl;
	pageloader loader;
	page cpp = loader.load(url);

	std::cout << std::endl << "status:" << cpp.getStatus() << std::endl << "data:" << cpp.getData() << std::endl;
	return 0;







}


