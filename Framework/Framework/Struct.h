#pragma once

struct Vector3  
{
	float x, y, z;
	
	// 인라인 함수
	Vector3() :x(0), y(0), z(0) {};
	Vector3(float _x, float _y) :x(_x), y(_y), z(0) {};
	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};

};

struct Transform
{
	// 위치
	Vector3 Position;
	// 회전
	Vector3 Rotation;
	// 크기
	Vector3 Scale;
};