#include "FSM.h"

void FSM::push_statement(std::shared_ptr<Statement> st)
{
	statement_list.push_back(st);
}
