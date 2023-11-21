#pragma once
#include "Core/Scene.h"
#include "Tools/Timer.h"
#include "OutPutAndInput/Camera.h"

enum class GameMode
{
	Mode_English,
	Mode_Chinese,
};

class CTitleScene : public CScene
{
public:
	void Init();
	void Update(float dt);
	void End();

	static GameMode GetGameMode();
private:
	void OnRender();

};