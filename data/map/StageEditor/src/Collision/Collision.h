
#ifndef __COLLISION_H__
#define __COLLISION_H__

class Collision
{
public:

	//�l�p�FX,Y�͍��W�AW�������AH���c��
	static bool Rect(int aX, int aY, int aW, int aH, int bX, int bY, int bW, int bH);
	static bool Rect(float aX, float aY, float aW, float aH, float bX, float bY, float bW, float bH);

	//�l�p(3D)�F���ꂼ��̍��WVEC�Ƒ傫��VEC
	static bool Rect3D(VECTOR aPos, VECTOR aSize, VECTOR bPos, VECTOR bSize);

	//�~�`�F���ꂼ��̍��W�Ɣ��a
	static bool Circlr(int aX, int aY, int aR, int bX, int bY, int bR);

	//�~�`(3D)�F���ꂼ��̍��W�Ɣ��a
	static bool Circlr3D(VECTOR aPos, float aR, VECTOR bPos, float bR);
};

#endif
