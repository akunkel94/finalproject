#include "Cave.h"
#include "Room.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

enum commands {help, search, take,  go};

commands switchCommand(string command);
void dispText(istream& in, ostream& out);

int main()
{
	ifstream inRooms("rooms.txt");
	ifstream inIntro("intro.txt");
	ifstream inOutro("outro.txt");
	ifstream inHelp("help.txt");

	Cave cave;
	Room* room;
	string input, command, temp;
	stringstream ss;
	bool gameover = false;
	string inventory[100];
	int inventoryIndex = 0;

	cave.init(inRooms);

	dispText(inIntro, cout);

	room = cave.getCurrentRoom();

	cout << endl;
	cout << room->getDescription() << endl;

	cout << "\n>>> ";
	getline(cin, input);
	ss.str(input);
	ss >> command;
	while(!cin.fail() && !gameover)
	{

		switch(switchCommand(command))
		{
		case help:
			dispText(inHelp, cout);
		break;
		case search:
			temp = room->search(input, cout);
			if(temp != "0")
			{
				inventory[inventoryIndex] = temp;
				inventoryIndex++;
			}
		break;
		case take:
			temp = room->take(input, cout);
			if(temp != "0")
			{
				inventory[inventoryIndex] = temp;
				inventoryIndex++;
			}
		break;
		case go:
			room = cave.go(input, inventory, inventoryIndex, cout);
		break;
		default:
			dispText(inHelp, cout);
		break;
		}

		gameover = cave.gameover();

		if(!gameover)
		{
			cout << "\n>>> ";
			getline(cin, input);
			ss.str(input);
			ss >> command;
		}
	}

	cout << endl;
	dispText(inOutro, cout);

	cave.destruct();

	return 0;
}

commands switchCommand(string command)
{
	commands com;
	if(command == "help")
	{
		com = help;
	}
	else if(command == "search")
	{
		com = search;
	}
	else if(command == "take")
	{
		com = take;
	}
	else if(command == "go")
	{
		com = go;
	}
	else
	{
		com = help;
	}

	return com;
}

void dispText(istream& in, ostream& out)
{
	string line;

	out << endl;

	getline(in, line, '\n');
	while(!in.fail() && !in.eof())
	{
		out << line << endl;

		getline(in, line, '\n');
	}
}
