//===========================================
// 
// �^�C�g���V�[��[scene_title.h]
// Auther:UedaKou
// 
//===========================================
#ifndef _SCENE_TITLE_H_
#define _SCENE_TITLE_H_
#include "scene_base.h"
#include "../base_object/save_object.h"
#include "../object/title_select.h"	// �Z���N�g
#include "../base_object/object_3D.h"	// �RD

class CObject;
namespace Scene{



	// �ڍs��N���X��
	class CTitle : public CBase
	{
	private:
	public:
		CTitle(CBase* scene);
		virtual ~CTitle();
		virtual CBase* Update()	override;
		virtual void Draw() const override;
		bool GetPose()override;
	private:
		CObject2D* m_pTitle;	// �^�C�g��
		CTitleSelect* m_pSelect[CTitleSelect::MAX];	// �Z���N�g
		CObject3D* m_pField[3];
		int m_nCntField;
		int m_nSelect;	// ���ݑI��
		bool m_bNext;
		const int m_nCntMax;
		int m_nCnt;
	};
}



#endif // _SCENE_TITLE_H_