#pragma once
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include "qt_keyboard.hpp"

namespace biv {
    struct QtRenderObject {
        int x, y, width, height;
        QColor color;
    };

    class QtWindow : public QWidget {
        Q_OBJECT
    private:
        QtKeyboard* keyboard;
        std::vector<QtRenderObject> objects_to_draw;
        const int CELL_SIZE = 16;

    public:
        QtWindow(int map_width, int map_height, QtKeyboard* kb, QWidget* parent = nullptr) 
            : QWidget(parent), keyboard(kb) {
            setFixedSize(map_width * CELL_SIZE, map_height * CELL_SIZE);
            setWindowTitle("Super Mario Qt");
            setStyleSheet("background-color: #5C94FC;");
        }

        void set_objects(const std::vector<QtRenderObject>& objs) {
            objects_to_draw = objs;
        }

    protected:
        void keyPressEvent(QKeyEvent* event) override {
            if (!keyboard) return;
            switch (event->key()) {
                case Qt::Key_A: keyboard->set_input(UserInput::MAP_RIGHT); break;
                case Qt::Key_D: keyboard->set_input(UserInput::MAP_LEFT); break;
                case Qt::Key_Space: keyboard->set_input(UserInput::MARIO_JUMP); break;
                case Qt::Key_Q: keyboard->set_input(UserInput::EXIT); break;
            }
        }

        void paintEvent(QPaintEvent* event) override {
            QPainter painter(this);
            for (const auto& obj : objects_to_draw) {
                painter.fillRect(
                    obj.x * CELL_SIZE, 
                    obj.y * CELL_SIZE, 
                    obj.width * CELL_SIZE, 
                    obj.height * CELL_SIZE, 
                    obj.color
                );
            }
        }
    };
}