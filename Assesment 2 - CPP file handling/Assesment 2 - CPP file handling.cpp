

#include <iostream>
#include <string>
#include<fstream>

using namespace std;


class Highscore
{
private: 
	int score;
	char name[6];
	int DoA[3]; 

public:

	friend ostream& operator << (ostream& os, Highscore &score);
	friend istream& operator >> (istream& is, Highscore &score);
	
	
};
ostream& operator << (ostream& os, Highscore &score) // overides the << operator to output the players input
{
	os << "\n" << "name: " << score.name << "\n" << "score: " << score.score << "\n" << "Date of attainment: " << score.DoA[0] << "/" << score.DoA[1] << "/" << score.DoA[2];
	return os;
}
istream& operator >> (istream& is, Highscore& score) // overides the >> operator to get the input of the player
{
	cout << "\n Enter Name (Max 5 characters): ";
	is >> score.name;
	cout << "\n Enter Score: ";
	is >> score.score;
	cout << "\n Enter Day of attainment: ";
	is >> score.DoA[0];
	cout << "\n Enter Month of attainment: ";
	is >> score.DoA[1];
	cout << "\n Enter Year of attainment: ";
	is >> score.DoA[2];

	return is; 
}

int main()
{
	Highscore score;
	Highscore read;

	cout << "enter new score details\n"; //asks the user to input score details (runs the << overided input)
	cin >> score;
	cout << "entered score is: " << score << endl;
	
	cout << "saving score...";

	fstream file; // declares the file and opens it to save the score
	file.open("highscores.txt", ios::out);
	
	file << score << endl; //uses the overrided << operator, figure out how to print it properly without using that overloaded one (I'm cooked)
	file.close();
	cout << "score saved\n" << "file info:\n";

	ifstream rfile;
	rfile.open("highscores.txt");
	while (!rfile.eof()) //Reads the file until reaching the end of the file
	{
		string data;
		rfile >> data;
		cout << data << endl;
	}
	file.close();

	cout << "done\n";

	system("pause");
	
	return 0;
}
