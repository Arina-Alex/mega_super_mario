#pragma once
#include <vector>
#include "game_map.hpp"
#include "qt_window.hpp"
#include "qt_ui_obj.hpp"
#include <QApplication>

namespace biv {
    class QtGameMap : public GameMap {
    private:
        QtWindow* window;
        std::vector<QtUIObject*> objs;

    public:
        QtGameMap(const int height, const int width, QtKeyboard* kb) 
            : GameMap(height, width) {
            window = new QtWindow(width, height, kb);
            window->show(); 
        }

        ~QtGameMap() {
            delete window;
        }

        void add_obj(QtUIObject* obj) {
            objs.push_back(obj);
        }

        void remove_obj(QtUIObject* obj) {
            objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
        }

        void clear() noexcept override {}

        void refresh() noexcept override {
            std::vector<QtRenderObject> render_objs;
            for (auto* obj : objs) {
                render_objs.push_back({
                    obj->get_left(),
                    obj->get_top(),
                    obj->get_width(),
                    obj->get_height(),
                    obj->get_color(),
                    obj->get_sprite_path()
                });
            }
            window->set_objects(render_objs);
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