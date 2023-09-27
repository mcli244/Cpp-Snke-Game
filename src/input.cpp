#include "input.h"
#include <iostream>

using namespace std;

SDL_Keycode Input::HandleInput(void){
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
        cout << "exit" <<endl;
        exit(0);
    } else if (e.type == SDL_KEYDOWN) {
      return e.key.keysym.sym;
      // switch (e.key.keysym.sym) {
      //   case SDLK_UP:
      //     cout << "SDLK_UP" <<endl;
      //     break;

      //   case SDLK_DOWN:
      //    cout << "SDLK_DOWN" <<endl;
      //     break;

      //   case SDLK_LEFT:
      //     cout << "SDLK_LEFT" <<endl;
      //     break;

      //   case SDLK_RIGHT:
      //     cout << "SDLK_RIGHT" <<endl;
      //     break;
      // }
    }
  }
}










