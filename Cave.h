#ifndef CAVE_H
#ifndef CAVE_H

#include "Room.h"
#include <iostream>
#include <string>

using std::string;
using std::endl;

class Cave
{
private:
	Room rooms[100];
	roomIndex = 0;
	Room* currentRoom, endRoom;
public:
	Cave();
	void init(istream& in);

	bool gameover();
	Room go(string input, string inventory[], int inventoryIndex, ostream& out); 
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

		rooms[roomIndex] = r;
		roomIndex++;

		getline(in, name, '\n');
	}

	currentRoom = rooms[0];
	endRoom = rooms[roomIndex-1];
}

bool Cave::gameover()
{
	return (currentRoom == endRoom);
}

Room Cave::go(string input, string inventory[], int inventoryIndex, ostream& out)
{
	input = input.substr(3, input.length()-3);

	if(input != "NORTH" && input != "SOUTH" && input != "EAST" && input != "WEST")
		out << "\nThat is not a direction you can go." << endl;
	else
	{
		bool haveItem = true;
		if(input == "NORTH" && northRoom != "0")
		{
			if(northItem != "0")
			{
				haveItem = false;
				for(int i=0; i<inventoryIndex && !haveItem; i++)
					haveItem = (northItem ==)
			}
		}
		else if(input == "EAST" && eastRoom != "0")
		{
		}
		else if(input == "SOUTH" && southRoom != "0")
		{
		}
		else if(input == "WEST" && westRoom != "0")
		{
		}
		else
			out << "\nThere is no room in that direction." << endl;
	}
}

#endif

if(input=="NORTH" && northRoom!="0")
{
	if(northItem != "0")
	{
		haveItem = false;
		for(int i=0; i<inventoryIndex && !haveItem; i++)
			haveItem = (inventory[i]==northItem);
	}
	
	if(haveItem)
	{
		currentRoom = findRoom(northRoom);
		
		out << endl;
		out << this->currentRoom;
	}
	else
		out << "\nYou can't go into that room yet." << endl;
}
