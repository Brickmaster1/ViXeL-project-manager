#include "Container.h"
#include "ui/Control.h"
#include "ui/ui.hpp"

#include <functional>
#include <memory>

Container::Container() {

}

Container::~Container() {
    
}

Container* Container::addChild(ui::Controls child) {
    // if(prevParent != nullptr) {
    // std::visit([&](auto&& arg) {
    //     if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, Window>) {
    //         auto window = std::get<std::shared_ptr<Window>>(container);
    //         uiWindowR(window->getWindow(), std::get<std::shared_ptr<Control>>(child)->getControl());
    //     }
    // }, container);
    // }
    auto prevParent = std::get<std::shared_ptr<Control>>(child)->getParent();
    containerChildren.push_back(child);
    if(control != nullptr) {
        //Control::onReparent(std::shared_ptr<Container>(this));
        //onAddChild(std::shared_ptr<Container>(this), child);
    }
    return this;
}

std::vector<ui::Controls>::iterator Container::getChildren() {
    return containerChildren.begin();
}

Container* Container::removeChild(ui::Controls child) {
    auto val = std::find(containerChildren.begin(), containerChildren.end(), child);
    if(val != containerChildren.end()) {
        containerChildren.erase(val);
    }
    return this;
}
 
// void Container::internalAddChild(ui::ContainerControls container, ui::Controls child) {
//     std::visit([&](auto&& arg) {
//         if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, Window>) {
//             auto window = std::get<std::shared_ptr<Window>>(container);
//             uiWindowSetChild(window->getWindow(), std::get<std::shared_ptr<Control>>(child)->getControl());
//         }
//     }, container);
// }