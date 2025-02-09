#pragma once

//#include "ui/Control.h"
#include "Container.h"
#include "DataUtil.h"

#include <ui.h>
#include <rocket.hpp>
#include <string>
#include <vector>

class Window : public Container {
public:
    Window();
    ~Window();

    virtual int onClose() = 0;
    virtual void onSizeChange() = 0;
    virtual void onFocusChange() = 0;

    void create() override;

    Window* setTitle(std::string text);
    std::string getTitle() { return windowTitle; }

    Window* setResizable(bool isResizable);
    bool isResizable() { return isWindowResizable; }

    Window* setMenubar(bool hasMenu);
    bool hasMenubar() { return windowHasMenubar; }

    Window* setBorderless(bool isBorderless);
    bool isBorderless() { return isWindowBorderless; }

    Window* setFullscreen(bool isFullscreen);
    bool isFullscreen() { return isWindowFullscreen; }

    Window* setMargined(bool hasMenu);
    bool isMargined() { return isWindowMargined; }

    Window* setParent(ui::Controls parent) override;
    Window* enable() override { Control::enable(); return this; }
    Window* disable() override { Control::disable(); return this; }
    Window* setPos(Pos2d pos) override { Control::setPos(pos); return this; }
    Window* setSize(Rect2d size) override { Control::setSize(size); return this; }
    Window* setName(std::string name) override { Control::setName(name); return this; }

    Window* addChild(ui::Controls child) override { Container::addChild(child); return this; }
    Window* removeChild(ui::Controls child) override { Container::removeChild(child); return this; }

protected:
    

private:
    static int internalOnClose(uiWindow* window, void* instance);
    static void internalOnSizeChange(uiWindow* window, void* instance);
    static void internalOnFocusChange(uiWindow* window, void* instance);

    uiWindow* window;
    std::string windowTitle;
    
    bool isWindowResizable;
    bool windowHasMenubar;
    bool isWindowBorderless;
    bool isWindowFullscreen;
    bool isWindowMargined;
};