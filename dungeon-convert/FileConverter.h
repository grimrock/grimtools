
#ifndef FILE_CONVERTER_H
#define FILE_CONVERTER_H

#include <string>
#include <vector>
#include <sstream>

typedef std::vector<std::string> Text;
typedef Text::iterator TextIter;

class FileConverter
{
public:
	FileConverter();
	std::vector<std::string> load(const std::string& file);
	void write(const std::string& file);
	std::string getQuotes(TextIter x);
	virtual ~FileConverter();

	Text input_;
	std::stringstream output_;
};

#endif
