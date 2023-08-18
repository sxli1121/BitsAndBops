#pragma once
class State
{
public:
	virtual ~State() {}
	virtual void OnEnter() {}
	virtual void OnUpdate(float dt){}
	virtual void OnExit(){}
};

