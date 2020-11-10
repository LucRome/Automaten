#include "FSM.h"
#include "Event.h"
#include "Event_Declaration.h"
#include <memory>

void dec() {
	std::shared_ptr<Node> ptr = std::make_shared<FSM>();
	ptr->push(*(new Event_Declaration()));
}
