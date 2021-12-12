#include "stdio.h"
#include "include/raylib.h"
#include "include/taglib/taglib.h"
#include <future>
#include <iostream>
#include <string>
#include <chrono>
bool musicloop(Music song){
    while(GetMusicTimePlayed(song) != GetMusicTimeLength(song)){
        UpdateMusicStream(song);
    }
    return true;
}

int main(int argc, char** argv){
    bool pause = false;
    InitAudioDevice();
    Music song = LoadMusicStream(argv[1]);
    PlayMusicStream(song);
    std::string command;
    std::future<bool> musended = std::async(musicloop,song);
    while(true){
        std::getline(std::cin,command);
        if (command == "pause"){
            if (pause){
                ResumeMusicStream(song);
                pause = false;
            }
            else{
            PauseMusicStream(song);
            pause = true;
            }
        }
        else if (command == "volume"){
            
        }
        else if (command == "stop"){
            StopMusicStream(song);
            break;
        }
        /*if (command == "nowplaying"){
            TagLib::FileRef::FileRef file(argv[1]); 
        }*/
        else std::cout<<"Invalid command";
        }
    
    UnloadMusicStream(song);
    CloseAudioDevice();
}