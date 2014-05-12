#ifndef ROOM_H
#define ROOM_H

#include <sstream>
#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::stringstream;
using std::ostream;

class Room
{
private:
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

public:
	Room(string name, string desc, string item, string container, string containerItem, string northRoom, string northItem, string eastRoom, string eastItem, string southRoom, string southItem, string westRoom, string westItem);
	string getItem() const;
	string getContainer() const;
	string getContainerItem() const;

	string take(string input, ostream& out);
	string search(string input, ostream& out);

	friend ostream& operator<<(ostream& out, const Room& rhs);
};

Room::Room(string name, string desc, string item, string container, string containerItem, string northRoom, string northItem, string eastRoom, string eastItem, string southRoom, string southItem, string westRoom, string westItem)
{
	this->name = name;
	this->desc = desc;
	this->container = container;
	this->containerItem = containerItem;
	this->northRoom = northRoom;
	this->northItem = northItem;
	this->eastRoom = eastRoom;
	this->eastItem = eastItem;
	this->southRoom = southRoom;
	this->southItem = southItem;
	this->westRoom = westRoom;
	this->westItem = westItem;
}

string Room::getItem() const
{
	return item;
}

string Room::getContainer() const
{
	return container;
}

string Room::getContainerItem() const
{
	return containerItem;
}

string Room::take(string input, ostream& out)
{
	string temp = "0";
	input = input.substr(5, input.length()-5);

	if(item == "0")
		out << "\nThere is nothing here to take." << endl;
	else if(input == item)
	{
		temp = item;
		item = "0";

		out << "\nYou take the ";
		out << temp;
		out << " and add it to your inventory." << endl;
	}
	else
		out << "\nYou can't take that." << endl;

	return temp;
}

string Room::search(string input, ostream& out)
{
	string temp = "0";
	input = input.substr(7, input.length()-7);

	if(input == container)
	{
		if(containerItem == "0")
		{
			out << "\nThe ";
			out << container;
			out << " is empty." << endl;
		}
		else
		{
			out << "\nYou search the ";
			out << container;
			out << ". You found a ";
			out << containerItem;
			out << " and add it to your inventory." << endl;

			temp = containerItem;
			containerItem = "0";
		}
	}
	else
	{
		out << "\nThere isn't one of those to search in this room." << endl;
	}

	return temp;
}

ostream& operator<<(ostream& out, const Room& rhs)
{
	stringstream ss;

	ss << "You have entered the ";
	ss << name;
	ss << ".";
	if(item != "0")
	{
		ss << " You see a ";
		ss << item;
		ss << " on the ground.";
	}
	if(container != "0" && item != "0")
	{
		ss << " You also see a ";
		ss << container;
		ss << ".";
	}
	else if(container != "0")
	{
		ss << " You see a ";
		ss << container;
		ss << ".";
	}

	if(northRoom != "0")
	{
		ss << " To the NORTH is the ";
		ss << northRoom;
		ss << ".";

		if(northItem != "0")
		{
			ss << "You need a ";
			ss << northItem;
			ss << " to go that way.";
	}

	if(eastRoom != "0")
        {
                ss << " To the EAST is the ";
                ss << eastRoom;
                ss << ".";

                if(eastItem != "0")
                {
                        ss << "You need a ";
                        ss << eastItem;
                        ss << " to go that way.";
        }

	if(southRoom != "0")
        {
                ss << " To the SOUTH is the ";
                ss << southRoom;
                ss << ".";

                if(southItem != "0")
                {
                        ss << "You need a ";
                        ss << southItem;
                        ss << " to go that way.";
        }

	if(westRoom != "0")
        {
                ss << " To the WEST is the ";
                ss << westRoom;
                ss << ".";

                if(westItem != "0")
                {
                        ss << "You need a ";
                        ss << westItem;
                        ss << " to go that way.";
        }

	return out << ss.str();
}

#endif
