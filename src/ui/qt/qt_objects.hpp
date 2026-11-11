#pragma once
#include "qt_ui_obj.hpp"
#include "mario.hpp"
#include "box.hpp"
#include "enemy.hpp"
#include "full_box.hpp"
#include "flying_enemy.hpp"
#include "jumping_enemy.hpp"
#include "money.hpp"
#include "mushroom.hpp"
#include "mushroom_box.hpp"
#include "moving_platform.hpp"
#include "ship.hpp"

namespace biv {
    class QtMario : public Mario, public QtUIObject {
    public:
        QtMario(const Coord& top_left, int w, int h) 
            : Mario(top_left, w, h), QtUIObject(this, QColor(255, 0, 0), "assets/mario.png") {}
    };

    class QtBox : public Box, public QtUIObject {
    public:
        QtBox(const Coord& top_left, int w, int h) 
            : Box(top_left, w, h), QtUIObject(this, QColor(139, 69, 19), "assets/brick.png") {}
    };

    class QtFullBox : public FullBox, public QtUIObject {
    public:
        QtFullBox(const Coord& top_left, int w, int h, UIFactory* factory) 
            : FullBox(top_left, w, h, factory), QtUIObject(this, QColor(255, 215, 0), "assets/question_box.png") {}
    };

    class QtEnemy : public Enemy, public QtUIObject {
    public:
        QtEnemy(const Coord& top_left, int w, int h, float speed) 
            : Enemy(top_left, w, h, speed), QtUIObject(this, QColor(128, 0, 128), "assets/enemy.png") {}
    };

    class QtFlyingEnemy : public FlyingEnemy, public QtUIObject {
    public:
        QtFlyingEnemy(const Coord& top_left, int w, int h, float speed, float max_dist) 
            : FlyingEnemy(top_left, w, h, speed, max_dist), QtUIObject(this, QColor(0, 191, 255), "assets/flying_enemy.png") {}
    };

    class QtJumpingEnemy : public JumpingEnemy, public QtUIObject {
    public:
        QtJumpingEnemy(const Coord& top_left, int w, int h) 
            : JumpingEnemy(top_left, w, h), QtUIObject(this, QColor(255, 140, 0), "assets/jumping_enemy.png") {}
    };

    class QtMoney : public Money, public QtUIObject {
    public:
        QtMoney(const Coord& top_left, int w, int h) 
            : Money(top_left, w, h), QtUIObject(this, QColor(255, 223, 0), "assets/coin.png") {}
    };

    class QtMushroom : public Mushroom, public QtUIObject {
    public:
        QtMushroom(const Coord& top_left, int w, int h) 
            : Mushroom(top_left, w, h), QtUIObject(this, QColor(50, 205, 50), "assets/mushroom.png") {}
    };

    class QtMushroomBox : public MushroomBox, public QtUIObject {
    public:
        QtMushroomBox(const Coord& top_left, int w, int h, UIFactory* factory) 
            : MushroomBox(top_left, w, h, factory), QtUIObject(this, QColor(218, 165, 32), "assets/question_box.png") {}
    };

    class QtMovingPlatform : public MovingPlatform, public QtUIObject {
    public:
        QtMovingPlatform(const Coord& top_left, int w, int h, float speed, float max_dist) 
            : MovingPlatform(top_left, w, h, speed, max_dist), QtUIObject(this, QColor(128, 128, 128), "assets/platform.png") {}
    };

    class QtShip : public Ship, public QtUIObject {
    public:
        QtShip(const Coord& top_left, int w, int h) 
            : Ship(top_left, w, h), QtUIObject(this, QColor(0, 100, 0), "assets/pipe.png") {}
    };
}