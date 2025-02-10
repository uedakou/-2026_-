//===========================================
// 
// �`���[�g���A���X�e�[�W[stage_tutorial.h]
// Auther:UedaKou
// 
//===========================================
#include "stage_tutorial.h"		// �`���[�g���A��

#include "../object/player.h"	// �v���C���[
#include "../object/field.h"	// �t�B�[���h
#include "../base_object/object_2D.h"	// �|�b�v�A�b�v�p2D
#include "../object/enemy000tutorial.h"	// �G000
#include "../base_object/object_fade.h"	// �t�F�[�h
#include "../base_object/object_billboard.h"	// �r���{�[�h

#define Enemy 1
#define Stage 1

namespace Scene {
	namespace Game {
		class CStage_000;
		//============================================
		// �R���X�g
		//============================================
		CStage_Tutorial::CStage_Tutorial(CBase* scene, CGameData* gameData) :
			CStageLode(scene, gameData)
		{
			CObject::ReleaseAll();

			m_nCntMakeFilde = 0;
			m_player = CPlayer::creat();

#if Stage
			// �t�B�[���h
			CField* pField = nullptr;
			// �A�X�t�@���g
			pField = CField::creat(CField::TYPE::Road,
				D3DXVECTOR3(0.0f, 0.0f, 4500.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXVECTOR3(1000.0f, 0.0f, 1000.0f));
			pField->SetBlock(1, 10);
			pField->SetPlayer(m_player);
			m_gameData->SaveObject(CGameObjectSave::TYPE::FIELD, pField);
			// �_�[�g
			pField = CField::creat(CField::TYPE::Grass,
				D3DXVECTOR3(2000.0f, 0.0f, 4500.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXVECTOR3(1000.0f, 0.0f, 1000.0f));
			pField->SetBlock(3, 10);
			pField->SetPlayer(m_player);
			m_gameData->SaveObject(CGameObjectSave::TYPE::FIELD, pField);

			pField = CField::creat(CField::TYPE::Grass,
				D3DXVECTOR3(-2000.0f, 0.0f, 4500.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXVECTOR3(1000.0f, 0.0f, 1000.0f));
			pField->SetBlock(3, 10);
			pField->SetPlayer(m_player);
			m_gameData->SaveObject(CGameObjectSave::TYPE::FIELD, pField);

			// �r���{�[�h
			CObjectBillbord* pBillbord = nullptr;
			float fRand = 0;
			for (int nCnt = 0; nCnt < 39; nCnt++)
			{
				fRand = (float)(rand() % 100 / 10);
				pBillbord = CObjectBillbord::creat(D3DXVECTOR3(700.0f, 0.0f, 250.0f * nCnt), D3DXVECTOR3(150.0f, 200.0f + 15.0f * fRand, 0.0f));
				pBillbord->SetTexture("data\\TEXTURE\\tree000.png");
				pBillbord->SetType(CObjectBillbord::TYPE::TREE);
				m_gameData->SaveObject(CGameObjectSave::TYPE::BILLBOAD, pBillbord);


				fRand = (float)(rand() % 100 / 10);
				pBillbord = CObjectBillbord::creat(D3DXVECTOR3(-700.0f, 0.0f, 250.0f * nCnt), D3DXVECTOR3(150.0f, 200.0f + 15.0f * fRand, 0.0f));
				pBillbord->SetTexture("data\\TEXTURE\\tree000.png");
				pBillbord->SetType(CObjectBillbord::TYPE::TREE);
				m_gameData->SaveObject(CGameObjectSave::TYPE::BILLBOAD, pBillbord);
			}
#endif // Stage

#if 1
			m_pUpdate = new CTutorial000(gameData);
#else
			m_pUpdate = new CTutorialDebug(gameData);
#endif // 0

			CFade::creat(CFade::FADE_TYPE::WHITE_IN, 30);
		}
		//============================================
		// �f�X�g���N�^
		//============================================
		CStage_Tutorial::~CStage_Tutorial()
		{
			// �X�V���폜
			if (m_pUpdate != nullptr)
			{
				delete m_pUpdate;
			}
			// �v���C���[���폜
			if (m_player != nullptr)
			{
				m_player->DeathFlag();
			}
			m_gameData->AllFlagDeath();
		}
		//============================================
		// �X�V
		//============================================
		nsPrev::CBase* CStage_Tutorial::Update()
		{
			CManager* manager = CManager::GetInstance();	// �}�l�[�W���[
			bool b = manager->GetSceneManager()->GetPose();
			if (b == false)
			{

				CInputKeyboard* Key = manager->GetInKey();	// �L�[�{�[�h����
				// ���������X�V
				CStageLode::Update();
#if Stage


				CObject* Top[MAX_PRIORITY];
				CObject::GetAllObject(Top);
				// �n�ʐ���
				for (int nCnt = 0; nCnt < MAX_PRIORITY; nCnt++)
				{
					CObject* pObject = Top[nCnt];
					CObject* pNext = nullptr;
					while (pObject != nullptr)
					{
						pNext = pObject->GetNext();
						switch (pObject->GetType())
						{
						case CObject::TYPE::PLAYER: {
							if (((CPlayer*)pObject)->GetPos().z >= 3000.0f + 1000.0f * m_nCntMakeFilde)
							{
								CField* pField = nullptr;
								pField = CField::creat(CField::TYPE::Road,
									D3DXVECTOR3(0.0f, 0.0f, 10000.0f + 1000.0f * m_nCntMakeFilde),
									D3DXVECTOR3(0.0f, 0.0f, 0.0f),
									D3DXVECTOR3(1000.0f, 0.0f, 1000.0f));
								pField->SetBlock(1, 1);
								pField->SetPlayer(((CPlayer*)pObject));
								m_gameData->SaveObject(CGameObjectSave::TYPE::FIELD, pField);


								pField = CField::creat(CField::TYPE::Grass,
									D3DXVECTOR3(2000.0f, 0.0f, 10000.0f + 1000.0f * m_nCntMakeFilde),
									D3DXVECTOR3(0.0f, 0.0f, 0.0f),
									D3DXVECTOR3(1000.0f, 0.0f, 1000.0f));
								pField->SetBlock(3, 1);
								pField->SetPlayer(((CPlayer*)pObject));
								m_gameData->SaveObject(CGameObjectSave::TYPE::FIELD, pField);


								pField = CField::creat(CField::TYPE::Grass,
									D3DXVECTOR3(-2000.0f, 0.0f, 10000.0f + 1000.0f * m_nCntMakeFilde),
									D3DXVECTOR3(0.0f, 0.0f, 0.0f),
									D3DXVECTOR3(1000.0f, 0.0f, 1000.0f));
								m_gameData->SaveObject(CGameObjectSave::TYPE::FIELD, pField);

								pField->SetBlock(3, 1);
								pField->SetPlayer(((CPlayer*)pObject));

								// �r���{�[�h
								CObjectBillbord* pBillbord = nullptr;
								float fRand = 0;
								for (int nCnt = 0; nCnt < 4; nCnt++)
								{
									fRand = (float)(rand() % 100 / 10);
									pBillbord = CObjectBillbord::creat(D3DXVECTOR3(700.0f, 0.0f, 9750.0f + 1000 * m_nCntMakeFilde + 250.0f * nCnt), D3DXVECTOR3(150.0f, 200.0f + 15.0f * fRand, 0.0f));
									pBillbord->SetTexture("data\\TEXTURE\\tree000.png");
									pBillbord->SetType(CObjectBillbord::TYPE::TREE);
									m_gameData->SaveObject(CGameObjectSave::TYPE::TREE, pBillbord);

									fRand = (float)(rand() % 100 / 10);
									pBillbord = CObjectBillbord::creat(D3DXVECTOR3(-700.0f, 0.0f, 9750.0f + 1000 * m_nCntMakeFilde + 250.0f * nCnt), D3DXVECTOR3(150.0f, 200.0f + 15.0f * fRand, 0.0f));
									pBillbord->SetTexture("data\\TEXTURE\\tree000.png");
									pBillbord->SetType(CObjectBillbord::TYPE::TREE);
									m_gameData->SaveObject(CGameObjectSave::TYPE::TREE, pBillbord);
								}
								m_nCntMakeFilde++;
							}
							break;
						}
						case CObject::TYPE::FIELD: {
							CField* pFade = (CField*)pObject;
							if (m_player != nullptr)
							{
								if (m_player->GetPos().z >= pFade->GetPos().z + 6000.0f)
								{
									pFade->DeathFlag();
								}
							}
							break;
						}
						case CObject::TYPE::BILLBOARD: {
							CObjectBillbord* pFade = (CObjectBillbord*)pObject;
							if (m_player != nullptr)
							{
								if (m_player->GetPos().z >= pFade->GetPos().z + 6000.0f)
								{
									pFade->DeathFlag();
								}
							}
							break;
						}
						case CObject::TYPE::ENEMY: {
							switch (((CEnemy*)pObject)->GetType())
							{
							case CEnemy::ENEMY_TYPE::Enemy000: {
								CEnemy000* pEnemy = (CEnemy000*)pObject;
								if (m_player != nullptr)
								{
									if (m_player->GetPos().z >= pEnemy->GetPos().z + 500.0f)
									{
										pEnemy->SetPosZ(m_player->GetPos().z + 500.0f);
									}

								}
								break;
							}
							case CEnemy::ENEMY_TYPE::Enemy100: {

								break;
							}
							default:
								break;
							}
							break;
						}
						default:
							break;
						}
						pObject = pNext;
					}
				}
#endif // Stage

				// �`���[�g���A���X�V
				CTutorial* p = m_pUpdate->update();
				if (p != m_pUpdate)
				{
					delete m_pUpdate;
					m_pUpdate = p;
					if (p == nullptr)
					{
						return makeScene<CStage_000>(m_gameData);
					}
				}

				if (Key->GetTrigger(DIK_RETURN))
				{
					return makeScene<CStage_000>(m_gameData);
				}
			}
			return this;
		}
		//============================================
		// �f�X�g���N�^
		//============================================
		bool CStage_Tutorial::GetPose()
		{
			return false;
		}

		//============================================
		// ����
		//============================================
		template<>
		nsPrev::CBase* CBase::makeScene<CStage_Tutorial>(CGameData* gamaData) {
			return new CStage_Tutorial(this, gamaData);
		}

		//============================================
		// �`���[�g���A��
		//============================================
		//============================================
		// �R���X�g���N�^
		//============================================
		CStage_Tutorial::CTutorial000::CTutorial000(CGameData* gamaData):
			CTutorial(gamaData),
			m_nMaxCnt(60)
		{
			m_nCnt = 0;
			m_pPopup = CObject2D::creat(4, D3DXVECTOR3(900.0f, 100.0f, 0.0f), D3DXVECTOR3(300.0f, 200.0f, 0.0f));
			m_gameData->SaveObject(CGameObjectSave::TYPE::FIELD, m_pPopup);

			m_pPopup->SetTexture("data\\TEXTURE\\Tutorial_popup_000.png");
			m_bNext = false;
		}
		//============================================
		// �f�X�g���N�^
		//============================================
		CStage_Tutorial::CTutorial000::~CTutorial000()
		{
			if (m_pPopup != nullptr)
			{
				m_pPopup->DeathFlag();
			}
		}
		//============================================
		// �X�V
		//============================================
		CStage_Tutorial::CTutorial* CStage_Tutorial::CTutorial000::update()
		{
			CManager* pManager = CManager::GetInstance();
			CInputKeyboard* pKey = pManager->GetInKey();
			if (pKey->GetTrigger(DIK_W)||
				pKey->GetTrigger(DIK_A)||
				pKey->GetTrigger(DIK_S)||
				pKey->GetTrigger(DIK_D))
			{
				m_bNext = true;
			}
			if (m_bNext)
			{
				m_nCnt++;
				if (m_nCnt >= m_nMaxCnt)
				{
					return new CTutorial001(m_gameData);
				}
			}
			return this;
		}
		//============================================
		// �R���X�g���N�g
		//============================================
		CStage_Tutorial::CTutorial001::CTutorial001(CGameData* gamaData):
			CTutorial(gamaData),
			m_nMaxCnt(60)
		{
			m_nCnt = 0;
			m_pPopup = CObject2D::creat(4, D3DXVECTOR3(900.0f, 100.0f, 0.0f), D3DXVECTOR3(300.0f, 200.0f, 0.0f));

			m_pPopup->SetTexture("data\\TEXTURE\\Tutorial_popup_001.png");

			m_bNext = false;
		}
		//============================================
		// �f�X�g���N�^
		//============================================
		CStage_Tutorial::CTutorial001::~CTutorial001()
		{
			if (m_pPopup != nullptr)
			{
				m_pPopup->DeathFlag();
			}
		}
		//============================================
		// �X�V
		//============================================
		CStage_Tutorial::CTutorial* CStage_Tutorial::CTutorial001::update()
		{
			CManager* pManager = CManager::GetInstance();
			CInputKeyboard* pKey = pManager->GetInKey();
			if (pKey->GetTrigger(DIK_SPACE) )
			{
				m_bNext = true;
			}
			if (m_bNext)
			{
				m_nCnt++;
				if (m_nCnt >= m_nMaxCnt)
				{
					return new CTutorial002(m_gameData);
				}
			}

			return this;
		}
		//============================================
		// �R���X�g���N
		//============================================
		CStage_Tutorial::CTutorial002::CTutorial002(CGameData* gamaData):
			CTutorial(gamaData),
			m_nMaxCnt(60)
		{
			m_nCnt = 0;
			m_pPopup = CObject2D::creat(4, D3DXVECTOR3(900.0f, 100.0f, 0.0f), D3DXVECTOR3(300.0f, 200.0f, 0.0f));

			m_pPopup->SetTexture("data\\TEXTURE\\Tutorial_popup_002.png");
			CObject* Top[MAX_PRIORITY];
			CObject::GetAllObject(Top);
			for (int nCnt = 0; nCnt < MAX_PRIORITY; nCnt++)
			{
				CObject* pObject = Top[nCnt];
				CObject* pNext = nullptr;
				while (pObject != nullptr)
				{
					pNext = pObject->GetNext();
					if (pObject->GetType() == CObject::TYPE::PLAYER)
					{
						D3DXVECTOR3 pos = ((CPlayer*)pObject)->GetPos();

						pEnemy = CEnemy000Tutorial::creat(D3DXVECTOR3(pos.x, pos.y, pos.z + 3000.0f));
						pEnemy->SetMovePos(D3DXVECTOR3(0.0f, 0.0f, 40.0f));

						break;
					}
					pObject = pNext;
				}
			}
			m_bNext = false;
		}
		//============================================
		// �f�X�g���N�^
		//============================================
		CStage_Tutorial::CTutorial002::~CTutorial002()
		{
			if (m_pPopup != nullptr)
			{
				m_pPopup->DeathFlag();
			}
			if (pEnemy != nullptr)
			{
				pEnemy->DeathFlag();
			}
		}
		//============================================
		// �X�V
		//============================================
		CStage_Tutorial::CTutorial* CStage_Tutorial::CTutorial002::update()
		{
			CManager* pManager = CManager::GetInstance();
			CInputKeyboard* pKey = pManager->GetInKey();
			if (pEnemy->GetLife() <= 0)

			{
				m_bNext = true;
			}
			if (m_bNext)
			{
				m_nCnt++;
				if (m_nCnt >= m_nMaxCnt)
				{
					CFade::creat(CFade::FADE_TYPE::WHITE_OUT, 30);

					return nullptr;
				}
			}
			return this;
		}
		//============================================
		// �f�o�b�O
		//============================================
		CStage_Tutorial::CTutorialDebug::CTutorialDebug(CGameData* gamaData):
			CTutorial(gamaData)
		{
#if Enemy
			CObject* Top[MAX_PRIORITY];
			CObject::GetAllObject(Top);
			for (int nCnt = 0; nCnt < MAX_PRIORITY; nCnt++)
			{
				CObject* pObject = Top[nCnt];
				CObject* pNext = nullptr;
				while (pObject != nullptr)
				{
					pNext = pObject->GetNext();
					if (pObject->GetType() == CObject::TYPE::PLAYER)
					{
						D3DXVECTOR3 pos = ((CPlayer*)pObject)->GetPos();

						m_pEnemy = CEnemy000::creat(D3DXVECTOR3(pos.x, pos.y, pos.z + 3000.0f));
						//m_pEnemy->SetMovePos(D3DXVECTOR3(0.0f, 0.0f, 40.0f));

						break;
					}
					pObject = pNext;
				}
			}
#endif
		}
		CStage_Tutorial::CTutorialDebug::~CTutorialDebug()
		{
		}
		CStage_Tutorial::CTutorial* CStage_Tutorial::CTutorialDebug::update()
		{
#if Enemy


			if (m_pEnemy == nullptr ||
				m_pEnemy->IsDeathFlag())
			{
				CObject* Top[MAX_PRIORITY];
				CObject::GetAllObject(Top);
				for (int nCnt = 0; nCnt < MAX_PRIORITY; nCnt++)
				{
					CObject* pObject = Top[nCnt];
					CObject* pNext = nullptr;
					while (pObject != nullptr)
					{
						pNext = pObject->GetNext();
						if (pObject->GetType() == CObject::TYPE::PLAYER)
						{
							D3DXVECTOR3 pos = ((CPlayer*)pObject)->GetPos();

							m_pEnemy = CEnemy000::creat(D3DXVECTOR3(pos.x, pos.y, pos.z + 3000.0f));
							//m_pEnemy->SetMovePos(D3DXVECTOR3(0.0f, 0.0f, 40.0f));

							break;
						}
						pObject = pNext;
					}
				}
			}
#endif // 0

			return this;
		}
}
}