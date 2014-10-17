// dungeon-convert.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include "dungeon-convert.h"
#include "Converter.h"

using namespace std;

void printInfo(const char* binname) {
	cout << "Dungeon Converter " << DC_VERSION << endl;
	cout << endl;
	cout << "This is a simple tool that eventually will attempt to convert dungeons generated in" << endl;
	cout << "Legend of Grimrock 1 into Legend of Grimrock 2." << endl;
	cout << endl;
	cout << "This is a VERY early version, do not expect much of it." << endl;
	cout << endl;
	cout << "Usage:" << binname << " input-directory output-directory" << endl;
	cout << "Author(s): " << DC_AUTHOR << endl;
	cout << "Homepage: " << DC_LINK << endl;
	cout << "Released under GNU GPLv3 license." << endl;
	cout << "http://github.com/grimrock/tools";
}

int main(int argc, const char* argv[])
{
	if (argc != 3) {
		printInfo(argv[0]);
		return EXIT_FAILURE;
	}

	Converter converter(argv[1], argv[2]);

	try {
		converter.createDirs();
		converter.load();
		converter.convert();
		converter.write();
	}
	catch (const std::exception& e) {
		cout << "ERROR: " << e.what() << endl;
		cout << "I told you to not expect much." << endl;
	}

	return 0;
}

