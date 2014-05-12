#ifndef CAVE_H
#ifndef CAVE_H

#include "Room.h"

#include <iostream>
#include <string>

class Cave
{
private:
	//Array of items
public:
	Cave();
	voin init(istream& in);
};

Cave::Cave() {}

void Cave::init(istream& in)
{
	string name;
        string desc;
        string item;
        string container;
        string containerItem;
        string northRoom;
        string northItem;
        string eastRoom;
        string eastItem;
        string southRoom;
        string southItem;
        string westRoom;
        string westItem;

	Room r;

	getline(in, name, '\n');
	while(!in.fail() && !in.eof())
	{
		getline(in, desc, '\n');
		getline(in, item, '\n');
		getline(in, container, '\n');
		getline(in, containerItem, '\n');
		getline(in, northRoom, '\n');
		getline(in, northItem, '\n');
		getline(in, eastRoom, '\n');
		getline(in, eastItem, '\n');
		getline(in, southRoom, '\n');
		getline(in, southItem, '\n');
		getline(in, westRoom, '\n');
		getline(in, westItem, '\n');

		r = Room(name, desc, item, container, containerItem, northRoom, northItem, eastRoom, eastItem, southRoom, southItem, westRoom, westItem);

		//add room to array

		getline(in, name, '\n');
	}
}

#endif
