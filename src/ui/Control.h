#pragma once

#include "DataUtil.h"
#include "ui.hpp"

#include <memory>
#include <string>

#include <ui.h>



class Control {
public:
    Control() = default;
    ~Control();

    // Since control itself isn't actually a real control, 
    // just a blueprint for a barebones one, this must be overriden
    virtual void create() = 0;
    
    void show();
    void hide();
    bool isHidden() { return isControlHidden; }
    
    void createAndShow();

    void onReparent(ui::ContainerControls newContainer);
    
    virtual Control* enable();
    virtual Control* disable();
    bool isEnabled() { return isControlEnabled; }

    virtual Control* setPos(Pos2d pos);
    Pos2d getPos() { return controlPos; }

    virtual Control* setSize(Rect2d size);
    Rect2d getSize() { return controlSize; }

    virtual Control* setName(std::string name);
    std::string getName() { return controlName; }

    virtual Control* setParent(ui::Controls parent);
    std::shared_ptr<Control> getParent() {
        return std::get<std::shared_ptr<Control>>(controlParent);
    }

    bool isTopLevel();

    uiControl* getControl() { return control; }
protected:
    uiControl* control;
    ui::Controls controlParent;
    std::string controlName;
    Rect2d controlSize;
    Pos2d controlPos;
    
    bool isControlHidden;
    bool isControlEnabled;
private:


};


