

#include <iostream>
#include <string>
#include<fstream>

using namespace std;
int main()
{
	struct playerscore
	{
		char score[4];
		char name[6];
		int  DoA[3];
	};
	playerscore newplayer[3] = {};
	for (int i = 0; i < 3; i++)
	{
		cout << "enter new score details\n"; //asks the user to input score details (runs the << overided input)
		cout << "\n Enter Name (Max 5 characters): ";
		cin >> newplayer[i].name;
		cout << "\n Enter Score (max score 999): ";
		cin >> newplayer[i].score;
		cout << "\n Enter Day of attainment: ";
		cin >> newplayer[i].DoA[0];
		cout << "\n Enter Month of attainment: ";
		cin >> newplayer[i].DoA[1];
		cout << "\n Enter Year of attainment: ";
		cin >> newplayer[i].DoA[2];
		cout << "\n";
	}

	ofstream tfile("player.scores", ios::out | ios::binary);

	if (tfile.good())
	{
		cout << "file opened\n";

		for (size_t i = 0; i < 3; i++)
		{
			tfile.write((char*)&newplayer[i].name, sizeof(char)*6);
			tfile.write((char*)&newplayer[i].score, sizeof(char)*4);
			tfile.write((char*)&newplayer[i].DoA[0], sizeof(newplayer[i].DoA[0]));
			tfile.write((char*)&newplayer[i].DoA[1], sizeof(newplayer[i].DoA[1]));
			tfile.write((char*)&newplayer[i].DoA[2], sizeof(newplayer[i].DoA[2]));
		}
	}
	tfile.close();


	ifstream rfile("player.scores", ios::in | ios::binary);
	
	while (!rfile.eof() && rfile.peek() != EOF)
	{
		rfile.read((char*)&newplayer->name, sizeof(char) * 6);
		cout << newplayer->name << endl;
		rfile.read((char*)&newplayer->score, sizeof(char) * 4);
		cout << newplayer->score << endl;
		rfile.read((char*)&newplayer->DoA[0], sizeof(newplayer->DoA[0]));
		cout << newplayer->DoA[0] << "/";
		rfile.read((char*)&newplayer->DoA[0], sizeof(newplayer->DoA[1]));
		cout << newplayer->DoA[1] << "/";
		rfile.read((char*)&newplayer->DoA[0], sizeof(newplayer->DoA[2]));
		cout << newplayer->DoA[2] << endl << endl;

	
	}
	rfile.close();




	system("pause");

	for (int i = 0; i < 3; i++)
	{
		cout << "Your entered scores are: \n" << "name: " << newplayer[i].name << "\n" << "score: " << newplayer[i].score << "\n" << "Date of attainment: " << newplayer[i].DoA[0] << "/" << newplayer[i].DoA[1] << "/" << newplayer[i].DoA[2] << "\n";
	}

	system("pause");
	return 0;
}

