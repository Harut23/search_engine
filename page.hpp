#ifndef PAGE_HPP      //sarqum enq struct vor es tipi obyekti mej pahenq
#define PAGE_HPP

#include<string>

class Page
{
private:
	std::string body;
	int status;
	std::string Url;

public:
	int isError() const;
	page(std::string Url, std::string body , int status);
	const std::string& getBody() const;
	int getStatus()const;


};





#endif


/*

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<gumbo.h>

class Parser {
public:
	const std::vector<std::string>& getUrl(const std::string& HTMLDoc);
	const std::vector<std::string>& getContentWords(const std::string& HTMLDoc);

private:
	void searchForlinks(gumboNode* node);
	std::string searchForCleanText(gumboNode* node)
	void splitWords(const::stdstring& str);
	inline bool isLetter(char symbol) const;

private:
	std::vector<std::string> urls;
	std::vector<std::string> contentWords;
};



endif //SEARCH_ENGINE_PARSER_HPP




*/


