#include "CustomTween.h"

using namespace godot;



void CustomTween::_register_methods() {
	register_method((char*)"_process", &CustomTween::_process);
	//register_method((char*)"linear", &CustomTween::linear<Color>);
}

CustomTween::CustomTween(Sprite& spri, const  String& param, const  Variant& start, const  Variant& end, const  float dur, const int Easing, const std::function<void(CustomTween*)>& Fncref) {
	sprite = spri;
	spritepath = spri.get_path();
	interverticies.push_back(start);
	interverticies.push_back(end);
	startVal = start;
	endVal = end;
	duration = dur;
	parameter = param;
	Easeinfnc = Easing;
	t = 0.0;
	x = t;
	_on_end = Fncref;
	intervals = (int)interverticies.size() - 1;
}

void CustomTween::update(float delta) {
	t += delta / duration;
	if (t > 1)
		t = 1.0;
	else if (t > float(index + 1) / intervals) {
		index += 1;
		startVal = interverticies[index];
		endVal = interverticies[index + 1];
	}
	x = t * intervals - index;

	if (&sprite)
		if (parameter == "modulate")
			sprite.set(parameter, colorDict.dict[Easeinfnc](this));
		else if (parameter == "position")
			sprite.set(parameter, Vector2Dict.dict[Easeinfnc](this));
		else if (parameter == "rotation")
			sprite.set(parameter, floatDict.dict[Easeinfnc](this));
}

CustomTween* CustomTween::add_curve(const Variant& end) {
	interverticies.push_back(end);
	intervals += 1;
	return this;
}