//Sam Alkibesi

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void ShowScore(string userName, int player, int ai, int ties)// displays the score
{
	cout << userName + ": " << player << endl;
	cout << "AI: " << ai << endl;
	cout << "Ties: " << ties << endl;
}

int main()
{
	int playerScore = 0, aiScore = 0, ties = 0, playerChoice = 0, aiChoice = 0;
	
	string userName;

	cout << "Hello! Prepare yourself for a game of Rock, Paper, Scissors!" << endl << endl;

	cout << "Press the Enter key to continue...";
	cin.get(); // clear input buffer
	system("cls");

	ifstream readFile;// test if file exsits if so ask the user if they want to continue with said username
	while (true)
	{
		cout << "What is your username: ";
		cin >> userName;
		system("cls");
		
		readFile.open(userName +  ".txt");
		if (readFile >> userName)
		{
			int temp = 0;
			cout << "The username you entered exists"<< endl << endl;
			cout << "Do you wish to use the username, " << userName << "?" << endl;
			cout << "1) Yes" << endl << "2) No" << endl;
			cin >> temp;
			system("cls");
			readFile.close();

			if(temp == 1)//
			{
				readFile.open(userName + ".txt");
				readFile >> userName >> playerScore >> aiScore >> ties;
				system("cls");
				readFile.close();
				break;
			}
			else
			{
				continue;
			}
			readFile.close();
		}
		break;
	}
	
	while (true)//plays out the game until player decides to quit
	{
		srand(time(NULL));

		ShowScore(userName, playerScore, aiScore, ties);

		aiChoice = rand() % 3 + 1;

		cout << "Choose your hand gesture: ";
		cout << endl << "1) Rock" << endl << "2) Paper" << endl << "3) Scissors" << endl;
		cin >> playerChoice;
		system("cls");

		switch (playerChoice) //Outputs results based on whether the player or AI won or if there was a tie, then increments their score by 1
		{
		case 1:
			if (aiChoice == 1)
			{
				cout << "AI choice: Rock," << userName << "'s Choice: Rock, It's a Draw :O" << endl;
				ties++;
			}
			else if (aiChoice == 2)
			{
				cout << "AI choice : Paper," << userName << "'s Choice: Rock AI Wins... :(" << endl;
				aiScore++;
			}
			else
			{
				cout << "AI choice: Scissors," << userName << "'s Choice: Rock Player Wins! :)" << endl;
				playerScore++;
			}
			break;
		case 2:
			if (aiChoice == 1)
			{
				cout << "AI choice: Rock," << userName << "'s Choice: Paper Player Wins! :)" << endl;
				playerScore++;
			}
			else if (aiChoice == 2)
			{
				cout << "AI choice: Paper," << userName << "'s Choice: Paper It's a Draw :O" << endl;
				ties++;
			}
			else
			{
				cout << "AI choice: Scissors," << userName << "'s Choice: Paper AI Wins... :(" << endl;
				aiScore++;
			}
			break;
		case 3:
			if (aiChoice == 1)
			{
				cout << "AI choice: Rock," << userName << "'s Choice: Scissors AI Wins... :(" << endl;
				aiScore++;
			}
			else if (aiChoice == 2)
			{
				cout << "AI choice: Paper," << userName << "'s Choice: Scissors Player Wins! :)" << endl;
				playerScore++;
			}
			else
			{
				cout << "AI choice: Scissors," << userName << "'s Choice: Scissors It's a Draw :O" << endl;
				ties++;
			}
			break;

		default: // if the user inputs incorrectly, loops them back to input correctly
			system("cls");
			continue;
		}

		int endChoice;

		cout << endl << "Do you wish to continue playing?" << endl << "1) Yes" << endl << "2) No" << endl;
		cin >> endChoice;
		system("cls");

		switch (endChoice) //after asking user if they wish to play,based off their answer either breaks out of code and saves results or loops them back to play again
		{
		case 1:
			cout << "Go off and show the AI, humanity's resilience!" << endl;
			cin.get();
			system("cls");
			continue;
		case 2:
			cout << "We hope you enjoyed the Game! :). Hope to see you again!" << endl;
			system("cls");
			break;
		default:
			cout << "We hope you enjoyed the Game! :). Hope to see you again!" << endl;
			system("cls");
			break;
		}
		break;
	}
		ofstream scoreFile; //declares variable for the users file
		scoreFile.open(userName + ".txt", std::ofstream::out); // creates a text file using the username of the player

		if (scoreFile.is_open())//check if file was successfully opened for writing
		{
			scoreFile << userName << "\n"; //saves name and scores
			scoreFile << playerScore << "\n";
			scoreFile << aiScore << "\n";
			scoreFile << ties << "\n";
			scoreFile.close();

			cout << "Your file has been stored in Facebook Headquarters" << endl;
		}

		scoreFile.close();
		
	return 0;
}