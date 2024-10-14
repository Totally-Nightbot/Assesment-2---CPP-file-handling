#include <iostream>
#include<fstream>
#include <conio.h>
using namespace std;

struct playerscore // creates the playerscore structure (holds the score name and DOA)
{
	int score;
	char name[6];
	int  DoA[3];
};

//decleration of variables needed

playerscore newplayer[32]; //creates the array for the scores to first be entered into
int lines;
playerscore* sorting = new playerscore[lines]; // creates a dynamic array for sorting

//functions needed for the main function to function
void FillArray()
{
	ifstream sfile("player.scores", ios::in | ios::binary); //reads out the current data and adds it to the array
	int i = 0;
	while (!sfile.eof() && sfile.peek() != EOF)
	{
		sfile.read((char*)&newplayer->name, sizeof(char) * 6);

		sfile.read((char*)&newplayer->score, sizeof(char) * 4);

		sfile.read((char*)&newplayer->DoA[0], sizeof(newplayer->DoA[0]));

		sfile.read((char*)&newplayer->DoA[1], sizeof(newplayer->DoA[1]));

		sfile.read((char*)&newplayer->DoA[2], sizeof(newplayer->DoA[2]));

		sorting[i] = newplayer[0];

		i++;
	}
	sfile.close();
}

void bubbleSort(playerscore sorting[]) { //runs the bubble sort system (if the number that is next is smaller than the current then it moves it to the left)
	int swaps;
	playerscore temp;

	FillArray();

	do //conducts the bubble sorting 
	{
		swaps = 0;
		for (int i = 0; i < lines - 1; i++)
		{
			if (sorting[i].score > sorting[i + 1].score)
			{
				temp = sorting[i];
				sorting[i] = sorting[i + 1];
				sorting[i + 1] = temp;
				swaps++;
			}
		}
	} while (swaps > 0);

}

void AddPlayerScores()
{
	int numOfScores;
	cout << "how many players are you inputting?\n\n"; //asks the player for amount of players they are inputting
	cin >> numOfScores;

	for (int i = 0; i < numOfScores; i++)
	{
		cout << "enter new score details\n"; //asks the user to input score details 
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

	ofstream tfile("player.scores", ios::out | ios::binary | ios::app);

	if (tfile.good())
	{
		cout << "saving scores...\n";
		for (size_t i = 0; i < numOfScores; i++) // writes the entered data into the file 
		{
			tfile.write((char*)&newplayer[i].name, sizeof(char) * 6);
			tfile.write((char*)&newplayer[i].score, sizeof(char) * 4);
			tfile.write((char*)&newplayer[i].DoA[0], sizeof(newplayer[i].DoA[0]));
			tfile.write((char*)&newplayer[i].DoA[1], sizeof(newplayer[i].DoA[1]));
			tfile.write((char*)&newplayer[i].DoA[2], sizeof(newplayer[i].DoA[2]));
		}
		cout << "\nscores saved.\n";

		system("pause");
	}
	tfile.close();
	

}

int ReadFile()
{
	ifstream rfile("player.scores", ios::in | ios::binary); //reads out the current data in the file and reads the amount of lines 
	int lines = 0;
	while (!rfile.eof() && rfile.peek() != EOF)
	{
		rfile.read((char*)&newplayer->name, sizeof(char) * 6);
		//cout << newplayer->name << endl;
		rfile.read((char*)&newplayer->score, sizeof(char) * 4);
		//cout << newplayer->score << endl;
		rfile.read((char*)&newplayer->DoA[0], sizeof(newplayer->DoA[0]));
		//cout << newplayer->DoA[0] << "/";
		rfile.read((char*)&newplayer->DoA[1], sizeof(newplayer->DoA[1]));
		//cout << newplayer->DoA[1] << "/";
		rfile.read((char*)&newplayer->DoA[2], sizeof(newplayer->DoA[2]));
		//cout << newplayer->DoA[2] << endl << endl;

		lines++;
		
	}
	
	rfile.close();
	return lines;
}

void FindByName() //finds a players data by name
{
	FillArray();
	char playerName[6];
	bool foundname = false;
	lines = ReadFile();

	cout << "\nEnter player name: ";
	cin >> playerName;

	for (int i = 0; i < lines; i++)
	{
		if ( strcmp(playerName, sorting[i].name) == 0)
		{
			foundname = true;
			cout << "\nentered players data: ";
			cout << "\nname: " << sorting[i].name << "\n"
				<< "score: " << sorting[i].score << "\n"
				<< "Date of attainment: " << sorting[i].DoA[0] << "/" << sorting[i].DoA[1] << "/" << sorting[i].DoA[2] << "\n";
			cout << endl;
		}
	}
	if (foundname == false)
	{
		cout << "\n\nError!entered name not found!!\n\n";
	}
	system("pause");
}

//main function (The main console) 
int main() //runs the console application to make navigation easier
{
	bool exit = false;
	int choice = 0;
	cout << "Welcome!pick a choice: \n\n";
	cout << "1: Add player scores\n\n";
	cout << "2: Sort and read file\n\n";
	cout << "3: Find player by name\n\n";
	cout << "4: exit application\n\n";
	cin >> choice;

	while (true)
	{
		switch (choice)
		{
		case 0:
			system("cls");
			cout << "Welcome!pick a choice: \n\n";
			cout << "1: Add player scores\n\n";
			cout << "2: Sort and read file\n\n";
			cout << "3: Find player by name\n\n";
			cout << "4: exit application\n\n";
			cin >> choice;
			break;

		case 1: //add scores to the data file 
			AddPlayerScores();

			choice = 0;
			break;

		case 2: // sort and read the file
			lines = ReadFile(); //reads out the entered players
			cout << "sorting...";

			bubbleSort(sorting); //sorts using bubble sort
			cout << "sorting complete!\n\n";

			for (size_t i = 0; i < lines; i++) //prints the sorted array 
			{

				cout << "name: " << sorting[i].name << "\n"
					<< "score: " << sorting[i].score << "\n"
					<< "Date of attainment: " << sorting[i].DoA[0] << "/" << sorting[i].DoA[1] << "/" << sorting[i].DoA[2] << "\n";
				cout << endl;
			}

			system("pause");
			choice = 0;
			break;

		case 3: //finds a player by name
			FindByName();

			choice = 0;
			break;

		case 4: //exits on entry 

			return 0;
			break;

		default:
			cout << "error! incorrect number selected, please pick another option from the above \n\n";
			system("pause");
			choice = 0;
			break;
		}
	}
	return 0;
}


