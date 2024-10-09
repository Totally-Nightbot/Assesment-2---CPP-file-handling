

#include <iostream>
#include <string>

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

	cout << "enter new score details\n";
	cin >> score;
	cout << "entered score is: " << score << endl;
	system("pause");
	
	return 0;
}
