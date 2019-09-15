#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Basestate.h"
//#include "../World/World.h"

#include "../Player.h"
#include "../Application.h"
#include "../Backends/Input.h"
#include "../../Engine/Engine.h"

class GameState : public Basestate
{
public:
    GameState(Application& app);

    bool input() override;
    void update(float dt) override;
	void lateUpdate(Camera* cam) override;
	void render(Renderer* renderer) override;

	void tryPause();

    ~GameState() override;
protected:


private:
	bool isPaused;
	bool TryPause;
	
	Input::Inputs vInput;

	Player m_player;
	//World m_world;
};

#endif // GAMESTATE_H
