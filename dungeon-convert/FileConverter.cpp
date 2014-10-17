#include "FileConverter.h"

#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

FileConverter::FileConverter()
{
	input_.clear();
	output_.clear();
}

std::vector<std::string> FileConverter::load(const std::string& filename) {
	ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw runtime_error("Failed to open file " + filename);
	}

	size_t size = input_.size();
	
	string line;
	while (getline(file, line)) {
		input_.push_back(line);
	}

	cout << (input_.size() - size) << " lines read from " << filename << endl;

	file.close();

	return input_;
}

void FileConverter::write(const std::string& filename) {
	ofstream file(filename.c_str(), ios::trunc);

	if (!file.is_open()) {
		throw runtime_error("Failed to open file " + filename + " for writing");
	}

	file << output_.str();

	file.close();

	cout << "Wrote file " << filename << endl;
}

std::string FileConverter::getQuotes(TextIter x) {
	size_t opening = x->find_first_of("\"");
	if (opening == string::npos)
		return "";
	size_t closing = x->find_last_of("\"");
	if (closing == string::npos)
		return "";
	return x->substr(opening + 1, closing - opening - 1);
}

FileConverter::~FileConverter()
{
}
