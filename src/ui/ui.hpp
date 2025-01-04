#pragma once

#include "ui.h"
#include <memory>
#include <variant>

class Control;
class Container;
class Window;
class Box;
class MenuBar;

namespace ui {
    using Controls = std::variant<std::shared_ptr<Control>, std::shared_ptr<Window>, std::shared_ptr<MenuBar>>;
    using ContainerControls = std::variant<std::shared_ptr<Container>, std::shared_ptr<Window>>;

    inline void AppMain() {
        uiMain();
    }

    inline const char* AppInit(uiInitOptions options) {
        return uiInit(&options);
    }

    inline const char* AppInit() {
        return AppInit({0});
    }

    inline void AppUninit() {
        uiUninit();
    }
    
    inline void AppQuit() {
        uiQuit();
    }
}
