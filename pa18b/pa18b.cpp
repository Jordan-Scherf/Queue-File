/// @file pa18b.cpp
/// @author Jordan Scherf <5005736913@student.csn.edu>
/// @date 07/29/2021
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This lab demonstates [The Use of a Queue] with a number inputed to sort out
/// the number of losers to one winner
/// @note Time Taken to Develop Program is about 7 hours
/// between days 07/20 and 07/29 with Assitance of
/// [TA William]

#include <cstdlib>
#include <iostream>

#include "Queue.hpp"

int main(int argc, char *argv[]) {
    int numberCandidates;  // How many Candidates in the Pool
    int rotation;  // How many times to rotate through the queue
    Queue<int> bin;  // A Queue that holds the Contenstants and Winner
    Queue<int> losers;  // A Queue to store the Losers
    int counter = 1;  // A counter to count how many times we rotated through


    if (argc != 3) {  // Checking to see if there are three arg
        std::cout << "Usage: ./pa18b CANADIDATES CYLCE" << '\n';
    } else {  // If there is 3 arg, start the program
        numberCandidates = std::atoi(argv[1]);  // Make the string int
        rotation = std::atoi(argv[2]);  // Make the string int

        for (int i = 1; i <= numberCandidates; i++) {  // Insert number for cand
            bin.push(i);
        }

        // While the bin Size isnt 1, sort out the losers into the Loser Queue
        while (bin.size() != 1) {
            if (counter % rotation == 0) {
                losers.push(bin.front());
                bin.pop();
            } else {
                bin.push(bin.front());
                bin.pop();
            }

            counter++;
        }

        // Print out the Winner, then the losers underneath
        std::cout << bin.front() << '\n';

        while (!losers.empty()) {
            if (losers.front() != losers.back()) {
                std::cout << losers.front() << " ";
            } else {
                std::cout << losers.front() << '\n';
            }

            losers.pop();
        }
    }

    return 0;
}



