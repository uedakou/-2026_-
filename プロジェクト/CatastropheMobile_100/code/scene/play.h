//===========================================
// 
// ゲーム全体処理[play.h]
// Auther:UedaKou
// 
//===========================================
#ifndef _PLAY_H_
#define _PLAY_H_
#include "scene_game.h"
#include "../base/main.h"		// メイン
//#include "../base_object/save_object.h"	// セーブオブジェクト
//#include "game_data.h"					// ゲームデータ
#include "../base_object/text.h"	// テキスト

#define MAX_FIELD (16)	// 地面最大数
#define MAX_ENEMY (64)	// 敵最大数

class CObject;
namespace Scene {
	namespace Game {
		class Play : public CBase
		{
		public:
			Play(CBase* game, CGameData* gameData);
			virtual ~Play();
			nsPrev::CBase* Update()	override;
			bool GetPose()override;
			void Draw() const override;

		private:
			void CameraController();
		private:
			bool bPause;	// ポーズ
			int m_nScore;	// スコア
			CText* m_pText;	// テキスト
		};
	}
}





#endif // !_PLAY_H_