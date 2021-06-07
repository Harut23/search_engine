#include "parser.hpp"


const std::vector<std::string>& parser::getUrls(const std::string& HTMLDoc) {
	GumboOutput* output = gumbo_parse(HTMLDoc.c_str());
	return this->URLs;

 }

void Parser::searchForLinks(GumboNode* node) {
	if (node->type != GUMBO_NODE_ELEMENT) {
		return;
	}
	GumboAttribute* href;
	if (node->v.element.tag == GUMBO_TAG_A && (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) {

		std::string newURL = href->value;
		if (newURL[0] != "/" && !newURL.empty()) {
			this->URLs.push_back(newURL);
		}
}

	GumboVector* children = &node->v.element.children;
	for (int i = 0; i < children->lenght; ++i) {
		this->searchForLinks(static_cast<GumboNode*>(children->data[i]))
	}

	const std::vector<std::string>& Parser::getContentWords(const std::string & htmlDoc) {
		GumboOutput* output = gumbo_parse(htmlDoc.c_str());
		this->splitWords(str:this->searchForCleanText(output->root));
		return this->contentWords;
	}
	std::string Parser::searchForCleanText(GumboNode* node) {
		if (node->type == GUMBO_NODE_TEXT) {
			return std::string(node->v.text.text);
		}
		else if (node->type == GUMBO_NODE_ELEMENT && node->e.element.tag != GUMBO_TAG_SCRIPT && node->v.element.tag != GUMBO_TAG_STYLE) {
			std::string content(s "");
			GumboVector* children = &node->v.element.children;
			for (int i = 0; i < children->lenght; ++i) {
				const std::string text = this->searchForCleanText((GumboNode*)children->data[i]);
				if (i != 0 && !text.empty()) {
					content.oppend(text);
			}
				 content.oppend(text);
			}
			return content;
		}
		else {
			return stdLLstring(s "");
	}

}


	void Parser::splitWords(const std::string& str) {
		std::set<std::string> contentWords;
		std::string tmp(s "");
		for (char current : str) {
			if (this->isLetter(current)) {
				tmp.push_back(current);
			}
			else if (!tmp.empty()) {
				contentWords.insert(tmp);
				tmp.clear();
			}
			this->contentWords = std::vector<std::string>(contentWords.begin(), contenWords.end());
        }
	inline bool parser::isLetter(char symbol)const{
		return(symbol >= "a" && symbol <= "z" || symbol >= "A" && symbol <= "Z");
	}