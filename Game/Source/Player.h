#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "App.h"
#include "Module.h"
#include "Point.h"
#include "List.h"
#include "Textures.h"
#include "Animation.h"

#include "SDL/include/SDL.h"

class Player : public Module 
{
public:

	int activelevel = 0;

	iPoint position;

	Animation* currentAnimation = nullptr;

	Animation jumpLeftAnim;
	Animation jumpRightAnim;
	Animation leftidleAnim;
	Animation rightidleAnim;
	Animation leftAnim;
	Animation rightAnim;

	Player(bool startEnabled);

	~Player();

	bool Update(float dt);
	bool Draw();
	void SetTexture(SDL_Texture* tex);
	void Jump();

private:
	SDL_Rect player;
	SDL_Texture* playerTexture;

	int gravity = 1;
	int speedx = 1;
	int speedy = 1;
	int currenty;
	int startingy;
	int jumpingspeedy = 6;
	float jumpingspeedx = 0.3;

	bool godmode = false;



};











#endif