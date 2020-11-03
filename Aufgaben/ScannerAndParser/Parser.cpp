#include "Parser.h"
#include "Parser.h"

Parser::Parser(std::string filepath)
    :scanner(Scanner(filepath))
{
}

bool Parser::parse()
{
    return FSM();
}

std::queue<std::string> Parser::getCalltimeline() const
{
    return m_calltimeline;
}

bool Parser::match(Terminals t)
{
    bool success;
    lookRet lR = scanner.lookup(true);
    if (lR.token == t) {
        success = true;
    }
    else {
        if (lR.token == Terminals::ERROR) {
            printer.printScannerError(lR.line, lR.column);
        }
        else {
            printer.printParserError(lR.line, lR.column, t, lR.token);
        }
        success = false;
    }
    return success;
}

bool Parser::match_noConsume(Terminals t) //just for tests, so no Parser error here
{
    bool success;
    lookRet lR = scanner.lookup(false);
    if (lR.token == t) {
        success = true;
    }
    else {
        if (lR.token == Terminals::ERROR) {
            printer.printScannerError(lR.line, lR.column);
        }
        success = false;
    }
    return success;;
}

bool Parser::FSM()
{
    m_calltimeline.push("FSM");
    return event_declarations() && state_transitions();
}

bool Parser::event_declarations()
{
    m_calltimeline.push("event_declarations");
    return match(EVENT) && id_list() && match(SEMICOLON);
}

bool Parser::id_list()
{
    m_calltimeline.push("id_list");
    return match(ID) && id_list2();
}

bool Parser::id_list2()
{
    m_calltimeline.push("id_list2");
    bool success;
    if (match_noConsume(COMMA)) {
        //remove COMMA
        scanner.lookup(true);
        success = id_list();
    }
    else { //empty
        success = true;
    }
    return success;
}

bool Parser::state_transitions()
{
    m_calltimeline.push("state_transitions");
    return statetransition() && state_transitions2();
}

bool Parser::state_transitions2()
{
    bool success;
    m_calltimeline.push("state_transitions2");
    if (match_noConsume(IN)) {
        success = state_transitions();
    }
    else
    {
        success = true;
    }
    return success;
}

bool Parser::statetransition()
{
    m_calltimeline.push("statetransition");
    return (match(IN) && opt_initial() && 
        match(STATE) && match(ID) && match(COLON) && transitions());
}

bool Parser::opt_initial()
{
    m_calltimeline.push("opt_initial");
    if (match_noConsume(INITIAL)) {
        match(INITIAL);
    }
    return true;
}

bool Parser::transitions()
{
    bool success = false;
    m_calltimeline.push("transitions");
    if (match_noConsume(ON)) {
        success = transition() && transitions();
    }
    else {
        success = true;
    }
    return success;
}

bool Parser::transition()
{
    m_calltimeline.push("transition");
    return (match(ON) && id_list() && match(GOTO) && match(ID) 
        && match(COLON) && opt_id_list() && match(SEMICOLON));
}

bool Parser::opt_id_list()
{
    m_calltimeline.push("opt_id_list");
    bool success;
    if (match_noConsume(ID)) {
        success = id_list();
    }
    else {
        success = true;
    }
    return success;
}
