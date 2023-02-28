extends Node2D

enum EaseType{linear,EASE_IN_QUAD,EASE_OUT_QUAD,SmoothStepN,Bouncy,EASE_IN_OUT_QUAD,SmoothStep3,EASE_IN_SINE,EASE_OUT_SINE}

func _input(event):
	# Handle key press
	if event.is_action_pressed("Button1"):
		button1()
	if event.is_action_pressed("Button2"):
		button2()
	if event.is_action_pressed("Button3"):
		button3()
	if event.is_action_pressed("Button4"):
		button4()
	if event.is_action_pressed("Restart"):
		restart()


func button1():
	# DONE: Some showcase on $Ship1 using SmoothStepN on alpha
	# We can change the color (and alpha) through the modulate property
	Tweens.tween($Ship1, "modulate",Color(1, 1, 1, 1), Color(1, 1, 1, 0),5, EaseType.SmoothStepN,null)
	print("Button 1 pressed.")
	
func button2():
	# DONE: Some showcase on $Ship2 using funky bezier on alpha, rotation and position
	Tweens.tween($Ship2, "modulate",Color(1, 1, 1, 0), Color(1, 1, 1, 1),5, EaseType.SmoothStepN,null)
	Tweens.tween($Ship2, "rotation",0, 1440,5, EaseType.EASE_IN_QUAD,null)
	Tweens.tween($Ship2, "position",$Ship2.position,$Ship2.position+Vector2(-50,50) ,5, EaseType.SmoothStepN,null)
	print("Button 2 pressed.")
	
func button3():
	# DONE: Some showcase on $Ship3 using spline on beziers utilizing on_end
	Tweens.tween($Ship3,"position",$Ship3.position,$Ship3.position+Vector2(200,-200),5,EaseType.EASE_IN_QUAD,
		funcref(self, "on_end_callback")  # callback must be in a separate function
	)
	print("Button 3 pressed.")
	
func button4():
	# TODO: Some showcase of smooth spline movement on $Ship4, change position
	#       The spline must be built using single line of code, e.g. using the Builder pattern
	Tweens.tween($Ship4,"position",$Ship4.position,$Ship4.position+Vector2(-100,-100),5,EaseType.EASE_IN_OUT_QUAD,null).add_curve(
		$Ship4.position+Vector2(-100,0)).add_curve(
		$Ship4.position+Vector2(0,-100)).add_curve(
		$Ship4.position)
	print("Button 4 pressed.")

func on_end_callback(tween):
	Tweens.tween(tween.sprite,"position",tween.endVal,tween.startVal,5,EaseType.EASE_OUT_QUAD,null)
# Restart the scene
func restart():
	get_tree().reload_current_scene()
	print("Scene restarted.")
