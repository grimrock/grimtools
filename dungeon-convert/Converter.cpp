#include "Converter.h"

/// @todo: Remove this crap and use something portable. We want to run this software on Linux and Mac.
#include <windows.h>

Converter::Converter(const std::string& inputDir, const std::string& outputDir)
:inputDir_(inputDir), outputDir_(outputDir)
{
}

void Converter::createDirs() {
	createDir(outputDir_);
	createDir(outputDir_ + "/mod_assets");
	createDir(outputDir_ + "/mod_assets/animations");
	createDir(outputDir_ + "/mod_assets/cinematics");
	createDir(outputDir_ + "/mod_assets/models");
	createDir(outputDir_ + "/mod_assets/scripts");
	createDir(outputDir_ + "/mod_assets/sounds");
	createDir(outputDir_ + "/mod_assets/textures");
}

void Converter::createDir(const std::string& path) {
	CreateDirectory(path.c_str(), NULL);
}

Converter::~Converter()
{
}


void Converter::load()
{
	dungeon_.load(inputDir_ + "/mod_assets/scripts/dungeon.lua");
}


void Converter::convert()
{
	dungeon_.convert();
}


void Converter::write()
{
	dungeon_.write(outputDir_ + "/mod_assets/scripts/dungeon.lua");
}
