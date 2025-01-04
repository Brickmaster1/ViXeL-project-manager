#pragma once

#include "ui/container/Window.h"
#include "ui/Control.h"
#include "DataUtil.h"
#include "ui/ui.hpp"

#include <ui.h>
#include <rocket.hpp>
#include <string>
#include <vector>

class Container : public Control {
public:
    Container() = default;
    ~Container() = default;

    Container* setParent(ui::Controls parent) override;
    Container* enable() override { Control::enable(); return this; }
    Container* disable() override { Control::disable(); return this; }
    Container* setPos(Pos2d pos) override { Control::setPos(pos); return this; }
    Container* setSize(Rect2d size) override { Control::setSize(size); return this; }
    Container* setName(std::string name) override { Control::setName(name); return this; }

    Container* addChild(ui::Controls child);
    std::vector<ui::Controls>::iterator getChildren();
    Container* removeChild(ui::Controls child);

protected:
    virtual void onAddChild(ui::ContainerControls container, ui::Controls control) = 0;
    
    std::vector<ui::Controls> containerChildren;
private:
    
};