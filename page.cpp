#include "page.hpp"


int page::isError() const
{
	if (status >= 200 && status < 400) {

		return 0;
	}
		return 1;
}

int page::getStatus() const
{
	return status;
}

const std::string& page::getBody() const {
	return std::string body;
}

Page::Page(std::string effUrl, std::string data, long status)
	:effUrl{ std::move(effUrl) }, data{ std::move(data) }, status{ status }
{
}











