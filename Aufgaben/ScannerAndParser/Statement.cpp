#include "Statement.h"

Statement::Statement()
{
	statement_list.shrink_to_fit();
	task_list.shrink_to_fit();
	transition_list.shrink_to_fit();
}
