#include "Tweens.h"


using namespace godot;


void Tweens::_register_methods() {
	register_method((char*)"_process", &Tweens::_process);
}

void Tweens::_init() {}
Tweens::Tweens() {}
Tweens::~Tweens() {}

void Tweens::_process(float delta) {
	int i = 0;
	// update all active tweens, remove the finished ones
	while (i < tweens.size()) {
		CustomTween* tween = &tweens[i];
		tween->update(delta);
		if (tween->is_done()) {
			tween->_on_end(tween);
			tweens.erase(tweens.begin() + i);
		}
		else ++i;
	}
}

CustomTween* Tweens::tween(Sprite& sprite, const String& param, const  Variant& startVal, const Variant& endVal, const float dur, const int Easeinfnc, const std::function<void(CustomTween*)>& _on_end) {
	CustomTween tween = CustomTween(sprite, param, startVal, endVal, dur, Easeinfnc, _on_end);
	tweens.push_back(std::move(tween));
	return &*tweens.rbegin();//this looks terrifiing but it makes sense...
}