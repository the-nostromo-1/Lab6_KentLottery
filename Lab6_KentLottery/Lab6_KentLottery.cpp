//
//
//  Lab6_KentLottery
//
//  Created by David Jacob Tinley on 10/4/22.
//

#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void assign(int chosen_assign[], int array_size);
bool check(int, int);
void draw(int chosen_draw[]);
int entry ();
void print_out_win(int array[]);
void print_out_loose(int array[]);

const int array_size = 10;

int main() {
    int chosen[array_size];

    assign(chosen, array_size);
    draw(chosen);
    cout << "Welcome to the Kent Lottery\n";

    for (int i = 0; i < 5; ++i) {
        int user_guess = entry();
        if (check(user_guess, chosen[i]) == true) {
            cout << "true\n";
            print_out_win(chosen);
            break;
        }
        else if (check(user_guess, chosen[i]) == false && i == 4) {
            print_out_loose(chosen);
        }
    }
    return 0;
}

void assign(int chosen_assign[], int array_size) {
    for(int i = 0; i < array_size; ++i) {
        chosen_assign[i] = -1;
    }
}

void draw(int chosen_draw[]) { // assigning random numbers to the chosen array
    srand(time(nullptr));
    for (int i = 0; i < array_size; ++i) {
        int new_lotto_numbers = rand() % 100;
        if (check(new_lotto_numbers, chosen_draw[i]) == false) {
            chosen_draw[i] = new_lotto_numbers;
        }
    }
}

bool check(int number_checked, int check_array) {
    if (number_checked == check_array) {
        return true;
    }
    else {
        return false;
    }
}

int entry () { // Define function entry() that asks the user to enter a
               // single number from 0 to 99 and returns this value
    int guess;
    cout << "Please enter a number between 0 and 99.\n";
    cin >> guess;
    return guess;
}

void print_out_win(int array[]) { // outputs the selected numbers if won
    cout << "You won the lottery\nHere are the other selected numbers....\n";
    for (int i = 0; i < array_size; ++i) {
        cout << array[i] << endl;
    }
}

void print_out_loose(int array[]) { // outputs the selected numbers if lost
    cout << "Try again next time\nHere are the winning numbers\n";
    for (int i = 0; i < array_size; ++i) {
        cout << array[i] << endl;
    }
}
