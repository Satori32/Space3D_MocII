#pragma once
#include <stdio.h>

#include "Point3D.h"

struct Camera3D {
	//type Type = double;
	typedef double Type;
	//type T = Type;

	//type Zm = double;
	typedef double Zm;
	//type Z = Zm;

	Point3D<T> Camera = { 0, };
	Point3D<T> Look = { 0, };
	Z Zoom = 0;
	//T Gray = 0;
	static const bool CanFly = false;
};

template<class T> Camera3D ConstructCamera3D<T>(Point3D<T>& Camera, Point3D<T>& Look, T& Zoom);
bool Free(Camera3D& In);