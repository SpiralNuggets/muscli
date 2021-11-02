#include "stdio.h"
#include <stdbool.h>
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_mixer.h"

main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *bgm = Mix_LoadMUS(argv[1]);
    Mix_Chunk *effect = Mix_LoadWAV(".wav");


    Mix_PlayMusic(bgm, -1);

    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_p:
                        if(!Mix_PlayingMusic())
                            Mix_PlayMusic(bgm, -1);
                        else
                            Mix_ResumeMusic();
                    case SDLK_s:
                        Mix_HaltMusic();
                        break;
                    case SDLK_1:
                        Mix_PlayChannel(-1, effect, 0);
                        break;
                }
            }
        }

    }

    Mix_FreeMusic(bgm);
    Mix_FreeChunk(effect);

    bgm = NULL;
    effect = NULL;

    Mix_Quit();

    return 0;
}
