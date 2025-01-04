#include "Control.h"

#include <memory>

Control::~Control() {
    uiControlDestroy(control);
}

void Control::show() {
    isControlHidden = false;
    if(control != nullptr) {
        uiControlShow(control);
    }
}

void Control::hide() {
    isControlHidden = true;
    if(control != nullptr) {
        uiControlHide(control);
    }
}

void Control::createAndShow() {
    create();
    show();
}

Control* Control::setSize(Rect2d size) {
    controlSize = {size.x, size.y};
    return this;
}

Control* Control::setPos(Pos2d pos) {
    controlPos = {pos.x, pos.y};
    return this;
}

Control* Control::setName(std::string name) {
    controlName = name;
    return this;
}

Control* Control::enable() {
    isControlEnabled = true;
    if(control != nullptr) {
        uiControlEnable(control);
    }
    return this;
}

Control* Control::disable() {
    isControlEnabled = false;
    if(control != nullptr) {
        uiControlDisable(control);
    }
    return this;
}

bool Control::isTopLevel() {
    if(control != nullptr) {
        return uiControlToplevel(control);
    }
    return NULL;
}

Control* Control::setParent(ui::Controls parent) {
    controlParent = parent;
    if(control != nullptr) {
        uiControlSetParent(control, std::get<std::shared_ptr<Control>>(parent)->control);
    }
    return this;
}