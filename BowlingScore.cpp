// Jackson Fuller
//4.10.23
//Bowling Score Calculator
//User inputs bowling scores then calculates and outputs score

#include <iostream>

int main() {
  // TODO
  int rollOne;
  int rollTwo;
  int rollThree;
  int scorebook[3][10] = {};
  int calcScore[10] = {};

  for (int frame = 0; frame < 10; frame++) {
    int pins = 10;

    // enter roll 1 of frame x
    std::cout << "Enter pins scored in the first roll of frame " << frame + 1
              << ": ";
    std::cin >> rollOne;

    // saves roll in scorebook
    scorebook[0][frame] = rollOne;

    // calculate pins left
    pins = pins - rollOne;

    // if strike
    if (pins == 0) {
      std::cout << "STRIKE!" << std::endl;

      // if last frame and strike scored
    }

    if (frame == 9 && pins == 0) {
      // sets pins to 10
      pins = 10;

      // input score
      std::cout << "Enter pins scored in the second roll of frame 10: ";
      std::cin >> rollTwo;

      // saves score
      scorebook[1][frame] = rollTwo;

      // calculate pins
      pins = pins - rollOne;

      // if strike scored
      if (pins == 0) {
        std::cout << "STRIKE!" << std::endl;

        // reset pins
        pins = 10;

        // input roll 3
        std::cout << "Enter pins scored in the third roll of frame 10: ";
        std::cin >> rollThree;

        // saves roll 3 in scorebooks
        scorebook[2][9] = rollThree;

        // if strike scored
        if (pins == 0) {
          std::cout << "STRIKE!" << std::endl;
        }
      }

      // if not a strike
    } else if (pins > 0) {
      std::cout << "Enter pins scored in the second roll of frame " << frame + 1
                << ": ";
      std::cin >> rollTwo;

      // saves roll in scorebook
      scorebook[1][frame] = rollTwo;

      // calculate pins left
      pins = 10 - (rollOne + rollTwo);

      // if spare
      if (pins == 0) {
        std::cout << "SPARE!" << std::endl;
      }
      // if spare on last frame
      if (pins == 0 && frame == 9) {

        // reset pins
        pins = 10;

        // input roll 3
        std::cout << "Enter pins scored in the third roll of frame 10: ";
        std::cin >> rollThree;

        // saves roll 3 in scorebooks
        scorebook[2][9] = rollThree;

        pins = pins - rollThree;

        if (pins == 0) {
          std::cout << "STRIKE!" << std::endl;
        }
      }
    }
  }


  //Score Calculations
  for (int i = 0; i < 10; i++) {

      // if two strikes on last frame
    if (scorebook[0][i] == 10 && scorebook[1][i] == 10) {
      calcScore[i] = scorebook[0][i] + scorebook[1][i] + scorebook[2][i] + calcScore[i-1];

      // if spare on last frame
    } else if (scorebook[0][i] + scorebook[1][i] == 10 && i == 9) {
      calcScore[i] = scorebook[0][i] + scorebook[1][i] + scorebook[2][i] + calcScore[i-1];

      //if two strikes in a row on second to last frame
    } else if (scorebook[0][i] == 10 && scorebook[0][i+1] == 10 && i == 8) {
      calcScore[i] = scorebook[0][i] + scorebook[0][i + 1] + scorebook[2][i + 1] + calcScore[i-1];
      
      //if two strikes in a row on first frame
    } else if (scorebook[0][i] == 10 && scorebook[0][i + 1] == 10 && i == 0) {
      calcScore[i] = scorebook[0][i] + scorebook[0][i + 1] + scorebook[0][i + 2];
      
      //if strike on first frame
    } else if (scorebook[0][i] == 10 && i == 0) {
      calcScore[i] = scorebook[0][i] + scorebook[0][i + 1] + scorebook[1][i + 1];
      
      //if spare on first frame
    } else if (scorebook[0][i] + scorebook[1][i] == 10 && i == 0){
      calcScore[i] = scorebook[0][i] + scorebook[1][i] + scorebook[0][i + 1];

      // if two strikes in a row
    } else if (scorebook[0][i] == 10 && scorebook[0][i + 1] == 10) {
      calcScore[i] = scorebook[0][i] + scorebook[0][i + 1] + scorebook[0][i + 2] + calcScore[i-1];

      // if strike
    } else if (scorebook[0][i] == 10) {
      calcScore[i] = scorebook[0][i] + scorebook[0][i + 1] + scorebook[1][i + 1] + calcScore[i-1];

      // if spare
    } else if (scorebook[0][i] + scorebook[1][i] == 10) {
      calcScore[i] = scorebook[0][i] + scorebook[1][i] + scorebook[0][i + 1] + calcScore[i-1];

    } else if (i == 0) {
      calcScore[i] = scorebook[0][i] + scorebook[1][i];
      
      //normal
    } else {
      calcScore[i] = scorebook[0][i] + scorebook[1][i] + calcScore[i-1];
    }
  }

  //outputs score
  for (int i = 0; i < 10; i++) {
    std::cout << calcScore[i] << " ";
  }

  return 0;
}