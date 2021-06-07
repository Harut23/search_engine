#ifndef PAGE_LOADER_CPP
#define PAGE_LOADER_CPP //toxuma define anel constanty  1 angam u include anel file y 1 angam

#include <string>
#include "page.hpp"

class Pageloader
{
private:

public:
	pageLoader();

	Page load(const std::string &url);

};
#endif


/*

#include "pageloader.hpp"


page pageloader::load(const std::string url) {
	curlpp::Easy request;
	curlpp::cleanup cleaner;

	request.setOpt(curlpp::options::Url(url));
	request.setOpt(curlpp::options::Header(true));

	request.setOpt(curlpp::options::followLocation(true));

	
	std::ostringstream os;
	curlpp::options::writeStream ws(&os);
	
	request.setOpt(ws);
	request.perform();

	std::string data = os.str();
	
	std::cout << std::endl << "effectiveurl"<<effUrl<<std::endl;
	return page(os.str(), curlpp::infos::ResponseCode::get(request));

}
*/