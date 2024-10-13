

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
	playerscore newplayer[1] = {};
	for (int i = 0; i < 1; i++)
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

		tfile.write((char*)&newplayer, sizeof(playerscore));

	}
	tfile.close();

	ifstream rfile("player.scores", ios::in | ios::binary);

	while (!rfile.eof() && rfile.peek() != EOF)
	{
		rfile.read((char*)&newplayer, sizeof(playerscore));
		cout << newplayer << endl;
	}
	rfile.close();




	system("pause");

	for (int i = 0; i < 1; i++)
	{
		cout << "Your entered scores are: \n" << "name: " << newplayer[i].name << "\n" << "score: " << newplayer[i].score << "\n" << "Date of attainment: " << newplayer[i].DoA[0] << "/" << newplayer[i].DoA[1] << "/" << newplayer[i].DoA[2] << "\n";
	}

	system("pause");
	return 0;
}

