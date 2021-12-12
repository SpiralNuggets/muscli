#include "stdio.h"
#include "include/raylib.h"
//#include "include/taglib/tag.h"
//#include "include/taglib/fileref.h"
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
    if (argc == 1){
        std::cout<<"muscli: no song given.";
        return 0;
    }
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
        //--- FILEREF CONFLICTS WITH RAYLIB---
       /*else if (command == "nowplaying"){
            TagLib::FileRef file(argv[1]);
            std::cout<<"Now Playing:\n"<<file.tag()->title()<<std::endl<<file.tag()->artist()<<std::endl<<file.tag()->album()<<std::endl;
        }*/
        else std::cout<<"Invalid command";
        }
    
    UnloadMusicStream(song);
    CloseAudioDevice();
}