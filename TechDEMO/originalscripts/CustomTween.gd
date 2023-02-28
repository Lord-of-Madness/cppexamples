extends Node


class_name CustomTween


var t:float
var x:float
var startVal
var endVal
var interverticies :Array=[]
var index:int
var duration
var sprite
var parameter
var Easeinfnc
var _on_end
var intervals:int

var dict = {0:"linear",1:"EASE_IN_QUAD",2:"EASE_OUT_QUAD",3:"SmoothStepN",4:"Bouncy",5:"EASE_IN_OUT_QUAD",6:"SmoothStep3",7:"EASE_IN_SINE",8:"EASE_OUT_SINE"}

func linear():
	return startVal+x*(endVal-startVal)
func Bouncy():
	return (1-x)*(1-x)*startVal+x*x*endVal 
func EASE_IN_SINE():
	return startVal+(1 - cos((x * PI) / 2))*(endVal-startVal)
func EASE_OUT_SINE():
	return startVal+(sin((x * PI) / 2))*(endVal - startVal)
func EASE_IN_QUAD():
	return startVal+(1 - (1 - x) * (1 - x))*(endVal-startVal)
func EASE_OUT_QUAD():
	return startVal+x*x*(endVal - startVal)
func EASE_IN_CUBE():
	return startVal+(1 -(1 - x) * (1 - x) * (1 - x))*(endVal-startVal)
func EASE_OUT_CUBE():
	return startVal+x*x*x*(endVal - startVal)
func SmoothStepN():
	return startVal+((endVal - startVal)*x * x * (3 - 2 * x))
func SmoothStep3():
	return x*EASE_IN_QUAD()+(1-x)*EASE_OUT_QUAD()
func EASE_IN_OUT_QUAD():
	if(x<0.5):
		return startVal+2*x*x*(endVal - startVal)
	else:
		return startVal+(1-(-2 * x + 2)*(-2 * x + 2)/2)*(endVal - startVal)


func _init(spri: Sprite,param:String,start = 0,end = 1,dur=1,Easing:int=0,Fncref=null):
	self.sprite=spri
	self.interverticies.append(start)
	self.interverticies.append(end)
	self.startVal=start
	self.endVal=end
	self.duration = dur
	self.parameter = param
	self.Easeinfnc = Easing
	self.t=0.0
	self.x=t
	self._on_end=Fncref
	self.intervals=len(interverticies)-1

func update(delta: float):
	t += delta/duration
	if t>1:
		t=1.0
	elif t>float(index+1)/intervals:
		index+=1
		startVal=interverticies[index]
		endVal=interverticies[index+1]
	x=t*intervals-index
	if is_instance_valid(sprite):
		sprite.set(parameter,call(dict[Easeinfnc]))

func add_curve(end):
	interverticies.append(end)
	intervals+=1
	return self

func is_done() -> bool:
	return t>=1
