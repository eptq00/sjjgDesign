#include "threedmaze.h"

threeDMaze::threeDMaze() {}

void threeDMaze::base() {
    layer = this->mazeLevel/7;
    for(int i=0 ; i<layer ; i++){
        threeDMap = new int**[mazeLevel];
        for (int j = 0; j < mazeLevel; j++) {
            threeDMap[j] = new int*[mazeLevel];
        }

        for (int j = 0; j < mazeLevel; j++) {
            for (int k = 0; k < mazeLevel; k++) {
                threeDMap[j][k] = 0;
            }
        }
    }
}

void threeDMaze::create3DMaze(){
    threeDMaze::base();
    for(int i=0 ; i<layer ; i++){
        this->createMaze();
        for(int x=0;x<mazeLevel;x++){
            for(int y=0;y<mazeLevel;y++){
                threeDMap[i][x][y]=this->map[x][y];
            }
        }
        if(i==0){
            threeDMap[i][this->mazeLevel-2][this->mazeLevel-1]=0;
        }
        else if(i == this->layer - 1){
            threeDMap[i][1][0]=0;
        }
        else{
            threeDMap[i][this->mazeLevel-2][this->mazeLevel-1]=0;
            threeDMap[i][1][0]=0;
        }
    }
}

