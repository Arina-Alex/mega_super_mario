#pragma once
#include "rect.hpp"
#include <QColor>
#include <QString>

namespace biv {
    class QtUIObject {
    protected:
        Rect* rect;
        QColor color;
        QString sprite_path;

    public:
        QtUIObject(Rect* rect, QColor color, QString sprite_path = "") 
            : rect(rect), color(color), sprite_path(sprite_path) {}
            
        virtual ~QtUIObject() = default;

        int get_left() const { return rect->get_left(); }
        int get_top() const { return rect->get_top(); }
        int get_width() const { return rect->get_right() - rect->get_left(); }
        int get_height() const { return rect->get_bottom() - rect->get_top(); }
        
        QColor get_color() const { return color; }
        QString get_sprite_path() const { return sprite_path; }
    };
}