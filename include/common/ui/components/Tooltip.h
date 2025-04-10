#pragma once

#include "interfaces/UIComponent.h"
#include "interfaces/IContainer.h"
#include "interfaces/IRenderable.h"

class Tooltip : public UIComponent, public IContainer , public IRenderable {
private:
	float _margin = 4.f;

public:


};