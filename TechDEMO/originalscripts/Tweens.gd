extends Node


var tweens : Array = []  # all active tweens

func _process(delta):
	var i = 0
	# update all active tweens, remove the finished ones
	while i < len(tweens):
		var tween = tweens[i]
		tween.update(delta)
		if tween.is_done():
			tweens.pop_at(i)
			if tween._on_end != null:
				tween._on_end.call_func(tween)  # call the function referenced by FuncRef
		else:
			i += 1


func tween(sprite,param,startVal,endVal,dur,Easeinfnc,_on_end):  # (t: CustomTween) => void
	var tween = CustomTween.new(sprite,param,startVal,endVal,dur,Easeinfnc,_on_end)
	tweens.append(tween)
	return tween
