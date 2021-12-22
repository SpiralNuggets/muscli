#include "stdio.h"
#include "include/raylib.h"
//#include "include/taglib/tag.h"
//#include "include/taglib/fileref.h"
#include <list>
#include <future>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>

void makelist(const char* filename, std::list<std::string>& lines){   
    lines.clear();
    std::ifstream file(filename);
    std::string s;
    while (std::getline(file, s))
        lines.push_back(s);
}

bool musicloop(Music song){
    while(GetMusicTimePlayed(song) != GetMusicTimeLength(song)){
        UpdateMusicStream(song);
    }
    return true;
}

void song(std::string filenamestr){
    const char * filename = filenamestr.c_str();
    bool pause = false;
    Music song = LoadMusicStream(filename);
    PlayMusicStream(song);
    std::string command;
    std::thread musicthread(musicloop,song);
    while(true){
        std::cout<<"muscli>";
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
        else std::cout<<"Invalid command"<<std::endl;
        }
    musicthread.detach();
    UnloadMusicStream(song);
}

int main(int argc, char** argv){
    if (argc == 1){
        std::cout<<"muscli: no further argument given";
        return 1;
    }
    else if (argc == 2){
        std::cout<<"muscli: no song or playlist given";
        return 1;
    }
    else if (argc == 3){
        if (strcmp(argv[1],"-s")==0){
            std::string songname(argv[2]);
            song(songname);
            CloseAudioDevice(); 
        }
        else if (strcmp(argv[1],"-p")==0){
            InitAudioDevice();
            std::list<std::string> playlist;
            makelist(argv[2],playlist);
            while (!playlist.empty()){
                song(playlist.front());
                playlist.pop_front();
            }
            CloseAudioDevice();
        }
    }
    else{
        std::cout<<"muscli: what";
        return 1;
        }
}
