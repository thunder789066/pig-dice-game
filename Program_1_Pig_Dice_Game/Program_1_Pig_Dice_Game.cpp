
// Christina Gerstner
// clgdtf@mail.umkc.edu
// 8/26/2019
// CS201R Pig Dice Game

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
//#include <bits/stdc++.h>
using namespace std;

int user_score = 0, com_score = 0, bust = 0;
char another_game = ' ';

void get_score() {
	cout << "Score\tYou : " << user_score << "   AI : " << com_score << endl << endl;
}

int get_roll() {
	srand(time(0));
	return (rand() % 6) + 1;
}

char check_choice() {
	bool bad_choice = true;
	char choice;

	while (bad_choice) {
		cout << "     (R)oll again or (H)old? ";
		cin >> choice;

		if (choice == 'r' || choice == 'R') {
			bad_choice = false;
		}
		else if (choice == 'h' || choice == 'H') {
			bad_choice = false;
		}
		else {
			cout << "You must enter R or H";
			continue;
		}
	}
	return choice;
}

void player_turn() {
	bool turn_end = true;
	char user_choice = ' ';
	int roll = 0;

	while (turn_end) {
		roll = get_roll();

		if (roll == 1) {
			cout << "Dice Roll : " << roll << " >>> BUST!" << endl << endl;
			user_score = 0;
			bust = 1;
			turn_end = false;
		}
		else if (user_score >= 50) {
			turn_end = false;
		}
		else {
			cout << "Dice Roll : " << roll << "   Pot : " << (user_score += roll);
			user_choice = check_choice();

			if (user_choice == 'r' || user_choice == 'R') {
				continue;
			}
			else if (user_choice == 'h' || user_choice == 'H') {
				turn_end = false;
			}
		}
	}
	get_score();
	return;
}

void com_turn() {
	bool turn_end = true;
	int roll;

	while (turn_end) {
		roll = get_roll();

		if (roll == 1) {
			cout << "Dice Roll : " << roll << " >>> BUST!" << endl << endl;
			com_score = 0;
			turn_end = false;
		}
		else if (com_score >= 20) {
			turn_end = false;
		}
		else {
			cout << "Dice Roll : " << roll << "\tPot : " << (com_score += roll) << endl;
		}
	}
	get_score();
	return;
}

void winner() {
	bool replay_choice = true;
	char play_again;

	while (replay_choice) {
		if (user_score >= 50) {
			cout << "Congrats!!! You Won! Do you want to play again? (Y)es or (N)o? ";
			cin >> play_again;
			if (play_again == 'y' || play_again == 'Y') {
				replay_choice = false;
			}
			else if (play_again == 'n' || play_again == 'N') {
				replay_choice = false;
			}
			else {
				continue;
			}
		}
		else if (com_score >= 50) {
			cout << "Oops, you lost. Do you want to play again? (Y)es or (N)o? ";
			cin >> play_again;
			if (play_again == 'y' || play_again == 'Y') {
				replay_choice = false;
			}
			else if (play_again == 'n' || play_again == 'N') {
				replay_choice = false;
			}
			else {
				continue;
			}
		}
	}
	another_game = play_again;
}

int main() {
	bool gameplay = true;
	get_score();

	while (gameplay) {
		player_turn();
		if (user_score >= 50 || com_score >= 50) {
			winner();
			if (another_game == 'Y' || another_game == 'y') {
				continue;
			}
			else {
				gameplay = false;
			}
		}
		else if (bust == 1) {
			com_turn();
		}
	}

	return 0;

}