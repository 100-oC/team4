#include"../Scene/Scene.h"
#include"Player.h"
#include"../Item/Ball.h"
#include<math.h>
#include <vector>

void Player::Init()
{
	handle = LoadGraph(PLAYER_IMAGE_NUM);

	x = START_POS_X;
	y = START_POS_Y;

	radian = ChangeDegToRad(0);	//プレイヤーを90°回転
	sRad = 0;

	speed = 0.0f;

	direction = false;

	
	angle = 0.0;            
	angularVelocity = 0.0;  
	pendulumLength = 0;     
	isPendulumActive = false;  

	velocityX = 0;
	velocityY = 0;
	currentPoleIndex = -1;
	float timeStep = 0;

	nearestPoleIndex = -1;

	isBounce = false;
}

void Player::Step(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	//float sX = x, sY = y;	//保存座標

	////Yスピードを加算
	//speed += Y_SPEED;

	////変更された角度を戻す
	//if (speed > 0)
	//{
	//	if (sRad > 0)
	//	{
	//		sRad -= 0.05f;
	//	}
	//	else if (sRad < 0)
	//	{
	//		sRad += 0.05f;
	//	}
	//}

	////下に落とす
	//Move(radian+ sRad, speed, sX, sY, direction);
	//
	////進行方向の角度を求める
	//if(speed>=0)
	//{
	//	//radian = GetAngle(x, y, sX, sY);
	//}

	////座標を確定
	//y = sY;
	//x = sX;

	if (angle > 360)angle = 0.0;

	if (CheckHitKey(KEY_INPUT_F) && !isPendulumActive) {

		ConnectToNearestPole(poleX, poleY); // Fキーが押されたときの処理
	}
	if (!CheckHitKey(KEY_INPUT_F) && isPendulumActive) {
		isPendulumActive = false;
		ReleaseKey();
	}
	// プレイヤーの座標を更新
	x += velocityX;
	y += velocityY;
	// 重力をシミュレート
	velocityY += 0.5;

	UpdatePendulum(poleX, poleY); // 振り子の更新

	Bounce();

	//プレイヤーが画面下に落ちたら
	if (y >= SCREEN_SIZE_Y + 50&& !CheckHitKey(KEY_INPUT_F))
	{
		x = START_POS_X;
		y = START_POS_Y;

		speed = 0.0f;
		velocityY = 0.0;
		velocityX = 0.0;
	}

}
void Player::Draw(int pX, int pY, float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	// アクティブなポールの振り子の線を描画
	if (isPendulumActive && currentPoleIndex != -1) {
		// 振り子の線を描画
		DrawLine(poleX[currentPoleIndex] - pX, poleY[currentPoleIndex] - pY, x - pX, y - pY, GetColor(255, 255, 255));
	}
	DrawRotaGraphF(x - pX, y - pY, 0.5f, radian + sRad, handle, true, direction);

	//当たり判定
	//DrawBox(x - 32 / 2-pX, y - 32 / 2-pY, x+32/2-pX, y+32/2-pY, GetColor(255, 0, 0), false);
}
void Player::Fin()
{

}
void Player::InitializePendulum(int poleIndex,float poleX[BALL_MAX_NUM],float poleY[BALL_MAX_NUM])
{
	// プレイヤーの現在位置からポールまでの距離を計算
	pendulumLength = CalculateDistance(x, y, poleX[poleIndex], poleY[poleIndex]);

	// プレイヤーとポールのY座標が近い場合の処理
	if ((poleY[poleIndex] - y) <= 100 && (y - poleY[poleIndex]) <= 100)
	{
		// プレイヤーがポールの左にいる場合
		if (x < poleX[poleIndex]) {
			angle = 270.0;
		}
		// プレイヤーがポールの右にいる場合
		else {
			angle = 90.0;
		}
	}
	// プレイヤーとポールのX座標が近い場合の処理
	else if ((poleX[poleIndex] - x) <= 100 && (x - poleX[poleIndex]) <= 100)
	{
		// プレイヤーがポールの上にいる場合
		if (y > poleY[poleIndex]){
			// プレイヤーがポールの左にいる場合
			if (x < poleX[poleIndex])angle = 350.0;
			// プレイヤーがポールの右にいる場合
			else angle = 10.0;
		}
		// プレイヤーがポールの下にいる場合
		else {
			// プレイヤーがポールの左にいる場合
			if (x < poleX[poleIndex])angle = 190.0;
			// プレイヤーがポールの右にいる場合
			else angle = 170.0;
		}
	}
	else
	{
		// プレイヤーの現在位置からポールまでの角度を計算
		angle = atan2(poleY[poleIndex] - y, poleX[poleIndex] - x) * 180.0 / DX_PI;

		// プレイヤーの位置に応じて角度を調整
		if ((x > poleX[poleIndex] && y > poleY[poleIndex]) ||
			(x < poleX[poleIndex] && y < poleY[poleIndex])) {
			angle += 180.0;
		}
	}


	// 角速度を計算
	angularVelocity = (velocityX * cos(DX_PI * angle / 180.0) + velocityY * sin(DX_PI * angle / 180.0)) / pendulumLength;

	// プレイヤーの初期位置をポールの位置と角度から設定
	x = poleX[poleIndex] + int(pendulumLength * cos(DX_PI * angle / 180.0));
	y = poleY[poleIndex] + int(pendulumLength * sin(DX_PI * angle / 180.0));
}

void Player::ConnectToNearestPole(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	timeStep = 0.0;
	nearestPoleIndex = -1;
	double minDistance = DBL_MAX; // 最小距離を非常に大きな値で初期化

	// 全てのポールとの距離を計算し、最も近いポールを見つける
	for (int i = 0; i < BALL_MAX_NUM; ++i) {
		double distance = CalculateDistance(x, y, poleX[i], poleY[i]);
		if (distance < minDistance) {
			minDistance = distance;
			nearestPoleIndex = i;
		}
	}

	// 最も近いポールが見つかった場合、振り子の初期化を行う
	if (nearestPoleIndex != -1) {
		velocityX = 0;
		velocityY = 0;
		InitializePendulum(nearestPoleIndex,
			poleX, poleY);
		currentPoleIndex = nearestPoleIndex; // 現在のポールを更新
		isPendulumActive = true; // 振り子運動をアクティブにする
	}
}

void Player::UpdatePendulum(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	if (isPendulumActive && currentPoleIndex != -1) {
		// 角度をラジアンに変換
		double radian = angle * DX_PI / 180.0;

		// 角速度の更新
		angularVelocity += (-gravity / pendulumLength * sin(radian));
		// 角度の更新
		angle += angularVelocity;

		// 振り子の端の座標を更新
		x = poleX[currentPoleIndex] + int(pendulumLength * sin(radian));
		y = poleY[currentPoleIndex] + int(pendulumLength * cos(radian)); // Y座標の更新方法を修正
	}
}

void Player::ReleaseKey() 
{
	isPendulumActive = false;

	// 角度をラジアンに変換
	double radian = angle * DX_PI / 180.0;

	// 角速度に応じて初速度を設定
	double initialVelocityX = pendulumLength * angularVelocity * cos(radian);
	double initialVelocityY = pendulumLength * angularVelocity * sin(radian);

	// 重力の影響を考慮した速度の計算
	velocityX = initialVelocityX;
	velocityY = -initialVelocityY - (gravity * timeStep);

	// 時間の経過による速度の更新
	timeStep += 0.1;

	// 速度の制限
	if (abs(velocityX) > maxVelocity) velocityX = (velocityX > 0) ? maxVelocity : -maxVelocity;
	if (abs(velocityY) > maxVelocity) velocityY = (velocityY > 0) ? maxVelocity : -maxVelocity;
}

void Player::Bounce() 
{
	if (isBounce) {
		x += velocityX;
		y += velocityY;
		if (x == velocityX || y == velocityY)
			isBounce = false;
	}
}

void Player::SetisBounce()
{
	if (!isBounce)isBounce = true;
	else isBounce = false;
}

void Player::SetvelocityX(float i)
{
	velocityX = i;
}
void Player::SetvelocityY(float i)
{
	velocityY = i;
}