#pragma once

#include "ui/Control.h"
#include "DataUtil.h"

#include <ui.h>
#include <rocket.hpp>
#include <string>
#include <vector>

class Container : public Control {
public:
    Container();
    ~Container();

    void create() override {}

    Container* setParent(ui::Controls parent) override { Control::setParent(parent); return this; }
    Container* enable() override { Control::enable(); return this; }
    Container* disable() override { Control::disable(); return this; }
    Container* setPos(Pos2d pos) override { Control::setPos(pos); return this; }
    Container* setSize(Rect2d size) override { Control::setSize(size); return this; }
    Container* setName(std::string name) override { Control::setName(name); return this; }

    virtual Container* addChild(ui::Controls child);
    std::vector<ui::Controls>::iterator getChildren();
    virtual Container* removeChild(ui::Controls child);

protected:
    std::vector<ui::Controls> containerChildren;

private:
    
};