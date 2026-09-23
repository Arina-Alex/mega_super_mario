#include "first_level.hpp"

#include "second_level.hpp"

using biv::FirstLevel;

FirstLevel::FirstLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* FirstLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::SecondLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void FirstLevel::init_data() {
	ui_factory->create_box({20, 24}, 20, 3); 
	ui_factory->create_mario({25, 10}, 3, 3); 
	ui_factory->create_enemy({28, 10}, 3, 2, 0.2);

	ui_factory->create_moving_platform({47, 25}, 6, 1, 0.1, 7);

	ui_factory->create_box({65, 24}, 15, 3);
	ui_factory->create_full_box({70, 18}, 2, 2); 
	ui_factory->create_jumping_enemy({72, 23}, 3, 2); 

	ui_factory->create_moving_platform({90, 25}, 8, 1, 0.1, 10);
	ui_factory->create_flying_enemy({90, 18}, 3, 2, 0.3, 10); 

	ui_factory->create_box({115, 25}, 20, 3);
	ui_factory->create_ship({120, 20}, 10, 5); 
}
