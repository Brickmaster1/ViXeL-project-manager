#include "Window.h"
#include "ui.h"
#include "ui/Control.h"

#include <memory>

Window::Window() {
    
}

Window::~Window() {

}

void Window::create() {
    window = uiNewWindow(windowTitle.c_str(), controlSize.x, controlSize.y, windowHasMenubar);
    control = uiControl(window);

    uiWindowOnClosing(window, internalOnClose, this);
    uiWindowOnContentSizeChanged(window, internalOnSizeChange, this);
    uiWindowOnFocusChanged(window, internalOnFocusChange, this);
    setBorderless(isWindowBorderless);
    setFullscreen(isWindowFullscreen);
    setMargined(isWindowMargined);
    setResizable(isWindowResizable);
    setTitle(windowTitle);
    setParent(controlParent);
    setName(controlName);
    setPos(controlPos);
}

int Window::internalOnClose(uiWindow* window, void* instance) {
    return static_cast<Window*>(instance)->onClose();
}

void Window::internalOnSizeChange(uiWindow* window, void* instance) {
    static_cast<Window*>(instance)->onSizeChange();
}

void Window::internalOnFocusChange(uiWindow* window, void* instance) {
    static_cast<Window*>(instance)->onFocusChange();
}

Window* Window::setBorderless(bool isBorderless) {
    isWindowBorderless = isBorderless;
    if(window != nullptr) {
        uiWindowSetBorderless(window, isBorderless);
    }
    return this;
}

Window* Window::setFullscreen(bool isFullscreen) {
    isWindowFullscreen = isFullscreen;
    if(window != nullptr) {
        uiWindowSetFullscreen(window, isFullscreen);
    }
    return this;
}

Window* Window::setMargined(bool isMargined) {
    isWindowMargined = isMargined;
    if(window != nullptr) {
        uiWindowSetMargined(window, isMargined);
    }
    return this;
}

Window* Window::setTitle(std::string text) {
    windowTitle.assign(text);
    if(window != nullptr) {
        
    }
    return this;
}

Window* Window::setResizable(bool isResizable) {
    isWindowResizable = isResizable;
    if(window != nullptr) {
        uiWindowResizeable(window);
    }
    return this;
}

void Window::onAddChild(ui::ContainerControls container, ui::Controls control) {
    
}