#include <stdio.h>
#include <stdio.h>

#include "SurfaceT.h"
#include "Size2D.h"
#include "Size3D.h"
#include "Point3D.h"
#include "Point2D.h"
#include "Vector.h"

struct TypeAndValue{
	//type Type = NULL;
	typedef void* Type;
	//type T = Type;
	T Value;
}

struct Clojuer {
	//type R = intmax_t;
	typedef intmax_t R;
	R(*Lambada)(Vector<TypeAndValue>&) = NULL;
	Vector<TypeAndValue> Arg;
};

struct Space {
	//type ZType = double;
	typedef double ZType;
	//type Color = RGB32;
	typedef RGB32 Color;
	//type Metric = double;
	typedef double Metric;

	SurfaceT<ZType> Z;
	SurfaceT<Color> Front;
	Size3D<Metric> Size;
	Vector<Clojuer> Clojuers;
};

Space ConstructSpace(Size3D<double>& Si,Point2D<intmax_t>& IS){
	Space S;
	S.Z = ConstructSurfaceT<double>(IS.X, IS.Y);
	S.Front = ConstructSurfaceT<RGB32>(IS.X, IS.Y);
	S.Size = ConstructSize3D(Si.X, Si.Y, Si.Z);
	S.Clojuers ConstructVector<Clojuer>(8);
	Fill(S.Z, Si.Z);
	return S;
}
bool Free(Space& S) {
	Free(S.Z);
	Free(S.Front);
	Free(S.Size);
	Free(S.Clojuers);

	return true;
}

bool SetPixel(Space& S, Point2D<size_t>& P,S.Metoric& Z, S.Color& C) {
	if (Index(S.Z, P.X, P.Y) == NULL) { return false; }
	if (*Index(S.Z, P.X, P.Y) < Z) { return false; }
	if (Index(S.Front, P.X, P.Y) == NULL) { return false; }
	(*Index(S.Front, P.X, P.Y)) = C;
	(*Index(S.Z, P.X, P.Y)) = Z;

	return true;
}

bool SetPixel(Space& S, Point3D<S.Metric>& P, S.Color& C) {
	if (Index(S.Z,S.Size.X*P.X,S.Size.Y* P.Y) == NULL) { return false; }
	if (*Index(S.Z,S.Size.X* P.X, S.Size.Y*P.Y) < S.Size.Z*P.Z) { return false; }
	if (Index(S.Front,S.Size.X* P.X,S.Size.Y* P.Y) == NULL) { return false; }
	(*Index(S.Front, S.Size.X*P.X,S.Size.Y* P.Y)) = C;
	(*Index(S.Z, S.Size.X*P.X, S.Size.Y*P.Y)) = S.Size.Z*P.Z;

	return true;
}
struct Camera3D {
	//type Metric = double;
	typedef double Metric;
	Point3D<Metric> Camera;
	Point3D<Metric> Look;
	Metric Zoom;
	//type Lense = NULL;
	typedef void* Lense;
	Lense L;
	//type Color = RGB32;
	typedef RGB32 Color;
	SurfaceT<Color> View;
};
struct LightFlow3D{
	//type Metric = double;
	typedef double Metric;
	Point3D<Metric> Light;
	Point3D<Metric> Look;
	//type Color = RGB32;
	typedef RGB32 Color;
	Color C;
	Metric Volume = 0;
};

struct TranceMog_Moc {
	Vector<SurfaceT<RGB16>> Graphic;
	size_t Index = 0;
	size_t Tic = 0;
	size_t Dir = 0;
	Point2D<size_t> P;
	Size2D<size_t> TipSize;
};

struct ObjectInfo {
	char Name[32] = {0,};
	//type T = NULL;
	typedef void* T:
	T Info;
	//type Metric = double;
	typedef double Metric;
	Point3D<Metric> Position;
	Size3D<double> Theta;
	//type TranceMog = TranceMog_Moc;
	typedef TranceMog_Moc TranceMog;
	TranceMog Visual;
};