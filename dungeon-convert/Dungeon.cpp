#include "Dungeon.h"
#include "dungeon-convert.h"

#include <vector>
#include <string>
#include <iterator>

using namespace std;

Dungeon::Dungeon()
:levelsCnt_(0)
{
}

void Dungeon::convert() {


	output_ << "-- Converted from LoG1 using dungeon-convert " << DC_VERSION << endl;
	output_ << "-- See " << DC_LINK << " for more details." << endl << endl;

	TextIter line = input_.begin();
	while (line != input_.end()) {

		if (line->find("mapName") != string::npos) {
			line = convertMap(line);
			continue;
		}

		// Default action: just copy the crap over as comment
		output_ << "-- " << *line << endl;

		++line;
	}
}

TextIter Dungeon::convertMap(TextIter line) {
	// First line: mapName("...")
	string map_name = getQuotes(line++);

	// Second line: setWallSet("...")
	string wall_set = getQuotes(line++);

	// Third line: playStream("...")
	string audio = getQuotes(line++);

	// Let's generate the output
	output_ <<
		"newMap{" << endl <<
		"        name = \"" << map_name << "\"," << endl <<
		"        width = 32," << endl <<
		"        height = 32," << endl <<
		"        levelCoord = {0,0," << levelsCnt_++ << "}," << endl <<
		"        ambientTrack = \"" + audio + "\"," << endl <<
		"        tiles = { \"dungeon_floor\", \"dungeon_wall\" }" << endl <<
		"}" << endl;

	// the next one should be mapDesc[[
	if (*line != "mapDesc([[")
		throw runtime_error("expected mapDesc([[ in line " + std::distance(input_.begin(), line));
	line++;
	

	output_ <<
		"loadLayer(\"tiles\", {" << endl;

	for (int y = 0; y < 32; y++) {
		if (line->size() != 32) {
			stringstream tmp;
			tmp << "Map row in line " << std::distance(input_.begin(), line) << " has length "
				<< line->size() << ", expected 32.";
			throw runtime_error(tmp.str());
		}

		output_ << "        ";

		for (int x = 0; x < 32; x++) {
			if ((*line)[x] == '#') {
				output_ << "2,";
			}
			if ((*line)[x] == '.') {
				output_ << "1,";
			}
		}
		output_ << endl;

		line++;
	}

	output_ << "})" << endl;

	return ++line;
}


Dungeon::~Dungeon()
{
}
