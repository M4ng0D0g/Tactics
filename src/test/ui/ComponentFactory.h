#pragma once

#include "ui/components/Panel.h"
#include "ui/components/GridPanel.h"
#include "ui/components/options/CommonOps.h"

class ComponentFactory {
public:
	static std::shared_ptr<Panel> createBackground(const CommonOps& ops);
	static std::shared_ptr<GridPanel> createBoard(const CommonOps& ops);
	static std::shared_ptr<Panel> createTile(const CommonOps& ops, bool isBlack);
};