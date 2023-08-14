#include "StartScene.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Core/FrameWork.h"
#include "Math/vector.h"
#include "Math/Matrix.h"
void CStartScene::Init()
{

}

void CStartScene::Run()
{
	
}

void CStartScene::End()
{
	CGameOutput::GetGameOutput()->Clear();
}
