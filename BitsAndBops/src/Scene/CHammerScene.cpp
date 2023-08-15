#include "CHammerScene.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Math/Matrix.h"

void CHammerScene::Init()
{
	//加载开始图片与音效
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	gameoutput->AddImg("hammer_title_screen", "Assets / Textures/FristRound /Pic/hammer_time_title_screen.png");
	gameoutput->AddPic("hammer_title", "hammer_title_screen", 0, 0, 1920, 1080);

	//运行环节图片与音效
	//手
	gameoutput->AddImg("hand1", "Assets / Textures/FristRound /Pic/hand_1.png");
	gameoutput->AddPic("hand1", "hand1", 0, 0, 1068, 1305);
	gameoutput->AddImg("hand2", "Assets / Textures/FristRound /Pic/hand_2.png");
	gameoutput->AddPic("hand2", "hand2", 0, 0, 1079, 1305);
	gameoutput->AddImg("hand3", "Assets / Textures/FristRound /Pic/hand_3.png");
	gameoutput->AddPic("hand3", "hand3", 0, 0, 1084, 1305);
	//锤子
	gameoutput->AddImg("hammer", "Assets / Textures/FristRound /Pic/hammer.png");
	gameoutput->AddPic("hammer", "hammer", 0, 0, 1479, 1001);
	//锤子效果
	gameoutput->AddImg("hammer_effect_almost_1", "Assets / Textures/FristRound /Pic/hammer_effect_almost_1.png");
	gameoutput->AddPic("hammer_almost1", "hammer_effect_almost_1", 0, 0, 46, 125);
	gameoutput->AddImg("hammer_effect_almost_2", "Assets / Textures/FristRound /Pic/hammer_effect_almost_2.png");
	gameoutput->AddPic("hammer_almost2", "hammer_effect_almost_2", 0, 0, 41, 116);
	gameoutput->AddImg("hammer_effect_hit", "Assets / Textures/FristRound /Pic/hammer_effect_hit.png");
	gameoutput->AddPic("hammer_hit", "hammer_effect_hit", 0, 0, 332, 58);
	gameoutput->AddImg("hammer_effect_perfect", "Assets / Textures/FristRound /Pic/hammer_effect_perfect.png");
	gameoutput->AddPic("hammer_perfect", "hammer_effect_perfect", 0, 0, 409, 91);
	//锤子自带效果
	gameoutput->AddImg("hammer_smear", "Assets / Textures/FristRound /Pic/hammer_smear.png");
	gameoutput->AddPic("hammer_smear", "hammer_smear", 0, 0, 431, 985);

	//钉子
	gameoutput->AddImg("nail_normal_1", "Assets / Textures/FristRound /Pic/nail_normal_1.png");
	gameoutput->AddPic("nail_normal1", "nail_normal_1", 0, 0, 81, 209);
	gameoutput->AddImg("nail_normal_2", "Assets / Textures/FristRound /Pic/nail_normal_2.png");
	gameoutput->AddPic("nail_normal2", "nail_normal_2", 0, 0, 81, 197);
	gameoutput->AddImg("nail_normal_3", "Assets / Textures/FristRound /Pic/nail_normal_3.png");
	gameoutput->AddPic("nail_normal3", "nail_normal_3", 0, 0, 156, 82);
	gameoutput->AddImg("nail_normal_4", "Assets / Textures/FristRound /Pic/nail_normal_4.png");
	gameoutput->AddPic("nail_normal4", "nail_normal_4", 0, 0, 150, 101);
	gameoutput->AddImg("nail_normal_5", "Assets / Textures/FristRound /Pic/nail_normal_5.png");
	gameoutput->AddPic("nail_normal5", "nail_normal_5", 0, 0, 153, 95);
	gameoutput->AddImg("nail_normal_6", "Assets / Textures/FristRound /Pic/nail_normal_6.png");
	gameoutput->AddPic("nail_normal6", "nail_normal_6", 0, 0, 157, 84);
	gameoutput->AddImg("nail_normal_7", "Assets / Textures/FristRound /Pic/nail_normal_7.png");
	gameoutput->AddPic("nail_normal7", "nail_normal_7", 0, 0, 86, 25);

	//显示框
	gameoutput->AddImg("fg", "Assets / Textures/FristRound /Pic/fg.png");
	gameoutput->AddPic("fg", "fg", 0, 0, 1988, 1988);
	//箱子
	gameoutput->AddImg("wood_centre", "Assets / Textures/FristRound /Pic/wood_centre.png");
	gameoutput->AddPic("wood_centre", "wood_centre", 0, 0, 470, 234);
	gameoutput->AddImg("wood_left", "Assets / Textures/FristRound /Pic/wood_left.png");
	gameoutput->AddPic("wood_left", "wood_left", 0, 0, 63, 234);
	gameoutput->AddImg("wood_right", "Assets / Textures/FristRound /Pic/wood_right.png");
	gameoutput->AddPic("wood_right", "wood_right", 0, 0, 63, 234);


	//结算环节的图片与音效
	//1
	gameoutput->AddImg("results_art_hammertime_amazing", "Assets / Textures/FristRound /Pic/results_art_hammertime_amazing.png");
	gameoutput->AddPic("amazing", "results_art_hammertime_amazing", 0, 0, 653, 453);
	gameoutput->AddImg("results_art_hammertime_cool", "Assets / Textures/FristRound /Pic/results_art_hammertime_cool.png");
	gameoutput->AddPic("cool", "results_art_hammertime_cool", 0, 0, 653, 453);
	gameoutput->AddImg("results_art_hammertime_tryagain", "Assets / Textures/FristRound /Pic/hammer_time_title_screen.png");
	gameoutput->AddPic("tryagain", "results_art_hammertime_tryagain", 0, 0, 653, 453);
	//2
	gameoutput->AddImg("amazing_sticker", "Assets / Textures/FristRound /Pic/amazing_sticker.png.png");
	gameoutput->AddPic("amazing_sticker", "amazing_sticker.png", 0, 0, 586, 317);
	gameoutput->AddImg("cool_sticker", "Assets / Textures/FristRound /Pic/cool_sticker.png");
	gameoutput->AddPic("cool_sticker", "cool_sticker", 0, 0, 483, 304);
	gameoutput->AddImg("tryagain_sticker", "Assets / Textures/FristRound /Pic/tryagain_sticker.png");
	gameoutput->AddPic("tryagain_sticker", "tryagain_sticker", 0, 0, 428, 344);

}

void CHammerScene::Run()
{
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	Matrix33 tm;
	tm.Translate(0, 0);
	gameoutput->DrawPic("hammer_title", &tm,6);


}

void CHammerScene::End()
{
	//结算环节

}
