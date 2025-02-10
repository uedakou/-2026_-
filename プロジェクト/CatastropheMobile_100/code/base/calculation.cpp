//============================================
//
// 計算用[calculation.h]
// Author:Uedakou
// 
//============================================
#include "calculation.h"
//***************************************
// 計算用定義
//***************************************


//***************************************
// 計算用処理
//***************************************
float RadianToAngle(float fRad)
{
	return(360.0f / (D3DX_PI * 2)) * fRad;
}

float AngleToRadian(float fAngle)
{
	return(D3DX_PI * 2 / 360.0f) * fAngle;
}
