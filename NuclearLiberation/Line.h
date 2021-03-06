#pragma once
#include "Geometry.h"


class Line : public virtual Geometry
{
public:

	void init(ID3D10Device* device, D3DXCOLOR color = WHITE);
	void draw();
};
