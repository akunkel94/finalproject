#ifndef CAVE_H
#define CAVE_H

#include "Room.h"
#include <istream>
#include <iostream>
#include <string>
#include <stdio.h>

using std::istream;
using std::string;
using std::endl;

class Cave
{
private:
	Room* rooms[100];
	int roomIndex;
	Room* currentRoom;
	Room* endRoom;
public:
	Cave();
	void init(istream& in);

	bool gameover();
	Room* getCurrentRoom();
	Room* findRoom(string name);
	Room* go(string input, string inventory[], int inventoryIndex, ostream& out);
	void destruct();
};

Cave::Cave() {}

void Cave::init(istream& in)
{
	roomIndex = 0;

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

	Room* r;

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

		r = new Room(name, desc, item, container, containerItem, northRoom, northItem, eastRoom, eastItem, southRoom, southItem, westRoom, westItem);

		rooms[roomIndex] = r;
		roomIndex++;

		getline(in, name, '\n');
	}

	currentRoom = rooms[0];
	endRoom = rooms[roomIndex-1];
}

bool Cave::gameover()
{
	return (currentRoom->getName() == endRoom->getName());
}

Room* Cave::getCurrentRoom()
{
	return currentRoom;
}

Room* Cave::findRoom(string name)
{
	for(int i=0; i<roomIndex; i++)
		if(rooms[i]->getName() == name)
			currentRoom = rooms[i];

	return currentRoom;
}

Room* Cave::go(string input, string inventory[], int inventoryIndex, ostream& out)
{
	input = input.substr(3, input.length()-3);
	string northRoom, northItem, southRoom, southItem, eastRoom, eastItem, westRoom, westItem;
	northRoom = currentRoom->getRoom("NORTH");
	southRoom = currentRoom->getRoom("SOUTH");
	eastRoom = currentRoom->getRoom("EAST");
	westRoom = currentRoom->getRoom("WEST");
	northItem = currentRoom->getRoomItem("NORTH");
	southItem = currentRoom->getRoomItem("SOUTH");
	eastItem = currentRoom->getRoomItem("EAST");
	westItem = currentRoom->getRoomItem("WEST");

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
					haveItem = (northItem == inventory[i]);
			}
			if(haveItem)
			{
				currentRoom = findRoom(northRoom);
				out << endl;
				out << currentRoom->getDescription();
			}
			else
				out << "\nYou can't go into that room yet." << endl;
		}
		else if(input == "EAST" && eastRoom != "0")
		{
			if(eastItem != "0")
                        {
                                haveItem = false;
                                for(int i=0; i<inventoryIndex && !haveItem; i++)
                                        haveItem = (eastItem == inventory[i]);
                        }
                        if(haveItem)
                        {
                                currentRoom = findRoom(eastRoom);
                                out << endl;
                                out << currentRoom->getDescription();
                        }
                        else
                                out << "\nYou can't go into that room yet." << endl;	
		}
		else if(input == "SOUTH" && southRoom != "0")
		{
			if(southItem != "0")
                        {
                                haveItem = false;
                                for(int i=0; i<inventoryIndex && !haveItem; i++)
                                        haveItem = (southItem == inventory[i]);
                        }
                        if(haveItem)
                        {
                                currentRoom = findRoom(southRoom);
                                out << endl;
                                out << currentRoom->getDescription();
                        }
                        else
                                out << "\nYou can't go into that room yet." << endl;
		}
		else if(input == "WEST" && westRoom != "0")
		{
			if(westItem != "0")
                        {
                                haveItem = false;
                                for(int i=0; i<inventoryIndex && !haveItem; i++)
                                        haveItem = (westItem == inventory[i]);
                        }
                        if(haveItem)
                        {
                                currentRoom = findRoom(westRoom);
                                out << endl;
                                out << currentRoom->getDescription();
                        }
                        else
                                out << "\nYou can't go into that room yet." << endl;
		}
		else
			out << "\nThere is no room in that direction." << endl;
	}

	return currentRoom;
}

void Cave::destruct()
{
	Room* temp;

	for(int i=0; i<roomIndex; i++)
	{
		temp = rooms[i];
		delete temp;
	}
}

#endif
