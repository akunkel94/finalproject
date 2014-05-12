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

commands switchCommand

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

int main()
{
	ifstream inRooms("rooms.txt");
	ifstream inIntro("intro.txt");
	ifstream inOutro("outro.txt");
	ifstream inHelp("help.txt");

	Cave cave;
	Room* room;
	string input, command;
	stringstream ss;
	bool gameover = false;

	cave.init(inRooms);

	introText(inIntro, cout);

	cout << "\n\>\>\> ";
	cin >> input;
	ss.str(input);
	ss >> command;
	while(!cin.fail() && !gameover)
	{
		switch(switchCommand(command))
		{
		case help:
		break;
		case search:
		break;
		case take:
		break;
		case go:
		break;
		default:
		break;
		}

		cout << "\n\>\>\> ";
		cin >> input;
		ss.str(input);
		ss >> command;
	}

	outroText(inOutro, cout);

	return 0;
}
