#include "stdio.h"
#include "include/raylib.h"
#include "conio.h" //thats it bitch
main(int argc, char** argv){
    bool pause = false;
    InitAudioDevice();
    Music song = LoadMusicStream(argv[1]);
    PlayMusicStream(song);
    char command;
    for(;;){
        UpdateMusicStream(song);
        if (IsKeyPressed(KEY_SPACE)){
            pause = !pause;
            if (pause){
                PauseMusicStream(song);
            }
            else{
                ResumeMusicStream(song);
            }
        }
    }
    UnloadMusicStream(song);
    CloseAudioDevice;
}

