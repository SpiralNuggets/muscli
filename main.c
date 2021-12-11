#include "stdio.h"
#include "include/raylib.h"
#include "conio.h" //thats it bitch
#include "include/async.h"

/*static async musicloop(struct async *pt, Music song){
    async_begin(pt);
    while(true){
        UpdateMusicStream(song);
        if (GetMusicTimePlayed(song) == GetMusicTimeLength(song)){
        }
    }
}*/

main(int argc, char** argv){
    bool pause = false;
    InitWindow(800, 450, "thewindow");
    InitAudioDevice();
    Music song = LoadMusicStream(argv[1]);
    PlayMusicStream(song);
    char command;
    while(!WindowShouldClose()){
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
        BeginDrawing();
        EndDrawing();
    }
    UnloadMusicStream(song);
    CloseAudioDevice();
    CloseWindow();
}

