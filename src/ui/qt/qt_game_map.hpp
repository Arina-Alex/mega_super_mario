#pragma once
#include "game_map.hpp"
#include "qt_window.hpp"
#include <QApplication>

namespace biv {
    class QtGameMap : public GameMap {
    private:
        QtWindow* window;
        std::vector<QtRenderObject> objs;

    public:
        QtGameMap(const int height, const int width, QtKeyboard* kb) 
            : GameMap(height, width) {
            window = new QtWindow(width, height, kb);
            window->show(); 
        }

        ~QtGameMap() {
            delete window;
        }

        void add_obj(int x, int y, int w, int h, QColor color) {
            objs.push_back({x, y, w, h, color});
        }

        void clear() noexcept override {
            objs.clear();
        }

        void refresh() noexcept override {
            window->set_objects(objs);
            window->update(); 
        }

        void remove_objs() override {
            objs.clear();
        }

        void show() const noexcept override {
            QApplication::processEvents();
        }
    };
}