#pragma once
#include "Parser.h"
//ParseTree Klassen
#include "Event_Declaration.h"
#include "Task.h"
#include "Event.h"
#include "FSM.h"
#include "Node.h"
#include "State.h"
#include "Transition.h"

Parser::Parser(std::string filepath)
    :scanner(Scanner(filepath))
{
}

bool Parser::parse()
{
    return FSM_func();
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
        //Objekt erstellen und pushen (state in anderer id(...))
        
        if (n == n_task) {
            std::shared_ptr<Task> t = std::make_shared<Task>();
            t->setName(name);
            dad->push(t);
        }
        else if (n == n_event) {
            std::shared_ptr<Event> e = std::make_shared<Event>();
            e->setName(name);
            dad->push(e);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Parser::id(std::shared_ptr<State>& self)
{
    std::string name = match_retName(ID);
    if(name != ""){
        self->setName(name);
        return true;
    };
    return false;
}


bool Parser::FSM_func() //=: FSM
{
    m_calltimeline.push("FSM");
    ast_start = std::make_shared<FSM>();
    //TODO: AST implementieren
    return event_declarations(ast_start) && state_transitions(ast_start);
}

bool Parser::event_declarations(std::shared_ptr<Node>& dad) //=: Event_Declaration
{
    std::shared_ptr<Event_Declaration> self = std::make_shared<Event_Declaration>();
    std::shared_ptr<Node> n_self = self;
    dad->push(self);
    m_calltimeline.push("event_declarations");
    return match(EVENT) && id_list(n_self, nameables::n_event) && match(SEMICOLON);
}

bool Parser::id_list(std::shared_ptr<Node>& dad, nameables n) //=: alles mit name
{
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

bool Parser::state_transitions(std::shared_ptr<Node>& dad) //Dad: FSM
{
    m_calltimeline.push("state_transitions");
    return statetransition(dad) && state_transitions2(dad);
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

bool Parser::statetransition(std::shared_ptr<Node>& dad) //=: State (wird in id erstellt)
{
    std::shared_ptr<State> self = std::make_shared<State>();
    std::shared_ptr<Node> p_self = self;
    dad->push(self);
    m_calltimeline.push("statetransition");
    return match(IN) && opt_initial(self) && match(STATE) 
        && id(self) && match(COLON) && transitions(p_self);       
}

bool Parser::opt_initial(std::shared_ptr<State>& dad) //=: State.initial
{
    m_calltimeline.push("opt_initial");
    if (match_noConsume(INITIAL)) {
        dad->setInitial(true);
        match(INITIAL);
    }
    else {
        dad->setInitial(false);
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
    std::shared_ptr<Transition> self = std::make_shared<Transition>();
    std::shared_ptr<Node> p_self = self;
    std::shared_ptr<State> son = std::make_shared<State>();
    dad->push(self);
    self->push(son);
    m_calltimeline.push("transition");
    return (match(ON) && id_list(p_self, nameables::n_event) && match(GOTO) && id(son) 
        && match(COLON) && opt_id_list(p_self) && match(SEMICOLON));
}

bool Parser::opt_id_list(std::shared_ptr<Node>& dad) //=: Transition.task_list
{
    m_calltimeline.push("opt_id_list");
    bool success;
    if (match_noConsume(ID)) {
        success = id_list(dad, nameables::n_task);
    }
    else {
        success = true;
    }
    return success;
}
