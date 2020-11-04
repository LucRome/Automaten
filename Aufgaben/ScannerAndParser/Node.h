#pragma once

class Event;
class Task;
class State;
class Transition;
class Node
{
public:
	virtual void push(Event& e) = 0;
	virtual void push(Task& t) = 0;
	virtual void push(State& s) = 0;
	virtual void push(Transition& t) = 0;
};

