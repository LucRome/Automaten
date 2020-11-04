#include "Parser.h"
#include "Parser.h"
#include "Event_Declaration.h"
#include "State_Transitions.h"
#include "Task.h"
#include "Event.h"

Parser::Parser(std::string filepath)
    :scanner(Scanner(filepath))
{
}

bool Parser::parse()
{
    bool v = FSM_func();
    v = false;
    return v;
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

std::string Parser::match_retName(Terminals t)
{
    std::string name;
    lookRet lR = scanner.lookup(true);
    if (lR.token == t) {
        name = lR.token.name;
    }
    else {
        if (lR.token == Terminals::ERROR) {
            printer.printScannerError(lR.line, lR.column);
        }
        else {
            printer.printParserError(lR.line, lR.column, t, lR.token);
        }
        name = "";
    }
    return name;
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

bool Parser::id(std::shared_ptr<Node>& dad, nameables n)
{
    std::string name = match_retName(ID);
    if (name != "") { // -> success match(ID)
        //Objekt erstellen und pushen
        if (n == n_state)
        {
            State& s = *(new State());
            s.setName(name);
            dad->set_goto(s);
        }
        else if (n == n_task) {
            Task& t = *(new Task());
            t.setName(name);
            dad->push(t);
        }
        else if (n == n_event) {
            Event& e = *(new Event());
            e.setName(name);
            dad->push(e);
        }
        return true;
    }
    else
    {
        return false;
    }
}


bool Parser::FSM_func() //=: FSM
{
    bool ret;
    m_calltimeline.push("FSM");
    ast_start = std::make_shared<FSM>();
    //TODO: AST implementieren
    return event_declarations(ast_start) && state_transitions(ast_start);
}

bool Parser::event_declarations(std::shared_ptr<Node>& dad) //=: Event_Declaration
{
    Event_Declaration& self = *(new Event_Declaration());
    std::shared_ptr<Node> p_self = std::make_shared<Event_Declaration>(self);
    dad->push(self);
    m_calltimeline.push("event_declarations");
    return match(EVENT) && id_list(p_self, nameables::n_event) && match(SEMICOLON);
}

bool Parser::id_list(std::shared_ptr<Node>& dad, nameables n) //=: alles mit name
{
    //TODO: detType dad, addname
    m_calltimeline.push("id_list");
    
    return id(dad, n) && id_list2(dad, n);
}

bool Parser::id_list2(std::shared_ptr<Node>& dad, nameables n) //=: wie ID
{
    //TODO:
    m_calltimeline.push("id_list2");
    bool success;
    if (match_noConsume(COMMA)) {
        //remove COMMA
        scanner.lookup(true);
        success = id_list(dad, n);
    }
    else { //empty
        success = true;
    }
    return success;
}

bool Parser::state_transitions(std::shared_ptr<Node>& dad) //=: State_Transitions
{
    State_Transitions& self = *(new State_Transitions());
    std::shared_ptr<Node> p_self = std::make_shared<State_Transitions>(self);
    dad->push(self);
    m_calltimeline.push("state_transitions");
    return statetransition(p_self) && state_transitions2(dad);
}

bool Parser::state_transitions2(std::shared_ptr<Node>& dad) //=: State_Transitions (kein neues Objekt hier)
{
    //TODO: ?
    bool success;
    m_calltimeline.push("state_transitions2");
    if (match_noConsume(IN)) {
        success = state_transitions(dad);
    }
    else
    {
        success = true;
    }
    return success;
}

bool Parser::statetransition(std::shared_ptr<Node>& dad) //=: State
{
    bool succ = false;
    State& self = *(new State());
    std::shared_ptr<Node> p_self = std::make_shared<State>(self);
    dad->push(self);
    m_calltimeline.push("statetransition");
    succ = match(IN) && opt_initial(p_self) && match(STATE);
    std::string name = match_retName(ID);
    succ = succ && name != "";
    if (succ) {
        self.setName(name);
        succ = succ && match(COLON) && transitions(p_self);
    }
    return  succ;
        
}

bool Parser::opt_initial(std::shared_ptr<Node>& dad) //=: State.initial
{
    m_calltimeline.push("opt_initial");
    if (match_noConsume(INITIAL)) {
        dad->setInitial();
        match(INITIAL);
    }
    return true;
}

bool Parser::transitions(std::shared_ptr<Node>& dad) //: Transition (kein neues Obj. hier)
{
    //TODO: ?
    bool success = false;
    m_calltimeline.push("transitions");
    if (match_noConsume(ON)) {
        success = transition(dad) && transitions(dad);
    }
    else {
        success = true;
    }
    return success;
}

bool Parser::transition(std::shared_ptr<Node>& dad) //=: Transition
{
    Transition& self = *(new Transition());
    std::shared_ptr<Node> p_self = std::make_shared<Transition>(self);
    dad->push(self);
    m_calltimeline.push("transition");
    return (match(ON) && id_list(p_self, nameables::n_event) && match(GOTO) && id(p_self, nameables::n_state) 
        && match(COLON) && opt_id_list(p_self) && match(SEMICOLON));
}

bool Parser::opt_id_list(std::shared_ptr<Node>& dad) //=: Transition.task_list
{
    m_calltimeline.push("opt_id_list");
    bool success;
    if (match_noConsume(ID)) {
        success = id_list(dad, nameables::n_event);
    }
    else {
        success = true;
    }
    return success;
}
