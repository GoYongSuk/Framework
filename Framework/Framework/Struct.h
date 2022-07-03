#pragma once

struct Vector3  
{
	float x, y, z;
	
	// �ζ��� �Լ�
	Vector3() :x(0), y(0), z(0) {};
	Vector3(float _x, float _y) :x(_x), y(_y), z(0) {};
	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};

};

struct Transform
{
	// ��ġ
	Vector3 Position;
	// ȸ��
	Vector3 Rotation;
	// ũ��
	Vector3 Scale;
};