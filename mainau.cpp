#include <iostream>
#include <Windows.h>
#pragma comment(licomment(lib, "winmm.lib")


using namespace std;

int main(int argc, char** argv){
    bool pause = false;
    char command;
    PlaySound(TEXT(argv[1]),NULL,SND_SYNC);
    for(;;){
        cout << "||";
        command = getchar();
        if(command == 'p'){
            pause = !pause;
            if (pause == 1){
                waveOutPause();
            }
            else
            {
                waveOutRestart();
            }
        }
    }
}
/*
 cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
link_libraries("winmm.lib")

add_executable(untitled2 main.cpp)

 */