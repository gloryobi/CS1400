#include <iostream>
#include "life.h"
#include <stdlib.h>

using namespace std;

void rules(const bool arrays[ROWS][COLS], bool arrays2[ROWS][COLS]){
    for(int i = 0; i<ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            if(arrays[i][j]){
                if((arrays[i][j+1]+arrays[i][j-1]+arrays[i+1][j-1]+arrays[i+1][j]+arrays[i+1][j+1]+arrays[i-1][j-1]+arrays[i-1][j]+arrays[i-1][j+1])<2){
                    arrays2[i][j] = false;
                }
                else if((arrays[i][j+1]+arrays[i][j-1]+arrays[i+1][j-1]+arrays[i+1][j]+arrays[i+1][j+1]+arrays[i-1][j-1]+arrays[i-1][j]+arrays[i-1][j+1]) == 2 || (arrays[i][j+1]+arrays[i][j-1]+arrays[i+1][j-1]+arrays[i+1][j]+arrays[i+1][j+1]+arrays[i-1][j-1]+arrays[i-1][j]
                    +arrays[i-1][j+1]) == 3){
                    arrays2[i][j] = true;
                }
                else if((arrays[i][j+1]+arrays[i][j-1]+arrays[i+1][j-1]+arrays[i+1][j]+arrays[i+1][j+1]+arrays[i-1][j-1]+arrays[i-1][j]
                    +arrays[i-1][j+1])>3){
                    arrays2[i][j] = false;
                }
                else{
                    arrays2[i][j] = true;
                }
            }
            else if(!arrays[i][j]){
                if((arrays[i][j+1]+arrays[i][j-1]+arrays[i+1][j-1]+arrays[i+1][j]+arrays[i+1][j+1]+arrays[i-1][j-1]+arrays[i-1][j]
                    +arrays[i-1][j+1]) == 3){
                    arrays2[i][j] = true;
                }
                else{
                    arrays2[i][j] = false;
                }
            }
        }
    }
}
void life(const bool current[ROWS][COLS], bool next[ROWS][COLS]){
    for(int i = 0; i<ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            rules(current, next);
        }
    }
}
