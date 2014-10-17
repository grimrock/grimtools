
#include <string>
#include "Dungeon.h"

class Converter
{
public:
	Converter(const std::string& inputDir, const std::string& outputDir);
	virtual ~Converter();
	void createDirs();
	void load();
	void convert();
	void write();
protected:
	void createDir(const std::string& path);

	Dungeon dungeon_;

	std::string inputDir_;
	std::string outputDir_;
};

