#include "ASTPrinter.h"
#include <iostream>

#include "Event_Declaration.h"
#include "Task.h"
#include "Event.h"
#include "FSM.h"
#include "State.h"
#include "Transition.h"

#include <memory>
#include <vector>

void ASTPrinter::printAST(FSM& fsm)
{
	std::cout << "FSM:" << std::endl;
	print(*fsm.getEvent_Declaration());
	const std::shared_ptr<std::vector<State>> states = fsm.getStates();
	for(std::vector<State> s : states)
}

void ASTPrinter::print(Event_Declaration& ed)
{
}

void ASTPrinter::intend()
{
	for (int i = 0; i < m_intend; i++) {
		std::cout << "  ";
	}
}
