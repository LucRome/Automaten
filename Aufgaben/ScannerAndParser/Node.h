#pragma once
#include <memory>

class Event;
class Task;
class State;
class Transition;
class Event_Declaration;


class Node
{
public:
	virtual void push(std::shared_ptr<Event>);
	virtual void push(std::shared_ptr<Task>);
	virtual void push(std::shared_ptr<State>);
	virtual void push(std::shared_ptr<Transition>);
	virtual void push(std::shared_ptr<Event_Declaration>);
};

