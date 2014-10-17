
#include "FileConverter.h"

#ifndef DUNGEON_H
#define DUNGEON_H

class Dungeon :
	public FileConverter
{
public:
	Dungeon();

	void convert();
	TextIter convertMap(TextIter line);

	virtual ~Dungeon();

protected:
	int levelsCnt_;
};

#endif
