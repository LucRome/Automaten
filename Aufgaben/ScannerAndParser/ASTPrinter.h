#pragma once
#include <iostream>

class FSM;
class Event;
class Task;
class State;
class Transition;
class Event_Declaration;

class ASTPrinter
{
public:
	void printAST(FSM& fsm);
private:
	void print(Event& ev);
	void print(Task& ta);
	void print(State& st);
	void print(Transition& tr);
	void print(Event_Declaration& ed);

	//Einrückung
	int m_intend = 0;
	void intend();
};

