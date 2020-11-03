#include "Scanner.h"

Scanner::Scanner(std::string filepath)
	:m_file(filepath)
{
	m_scanSuccessfull = scan();
}

Token Scanner::getNextToken()
{
	Token ret = readNextToken();
	m_tokens.pop();
	return ret;
}

Token Scanner::readNextToken() const
{
	return m_tokens.front();
}

std::queue<Token> Scanner::getTokens()
{
	return m_tokens;
}

Token Scanner::automat()
{
	bool success = true;
	bool end = false;
	//Zustandsautomat (Endzustände mit Return: hier)
	int step = 0;
	Token token = { Terminals::ERROR, "" };
	while (!end && success) {
		end = true;
		switch (step)
		{
			//Endzustände
		case 6:
			token = { Terminals::EVENT, "" };
			m_name = "";
			step = 0;
			break;
		case 14:
			token = { Terminals::INITIAL, "" };
			m_name = "";
			step = 0;
			break;
		case 15:
			token = { Terminals::IN, "" };
			m_name = "";
			step = 0;
			break;
		case 21:
			token = { Terminals::STATE, "" };
			m_name = "";
			step = 0;
			break;
		case 24:
			token = { Terminals::ON, "" };
			m_name = "";
			step = 0;
			break;
		case 29:
			token = { Terminals::GOTO, "" };
			m_name = "";
			step = 0;
			break;
		case 30:
			token = { Terminals::COMMA, "" };
			m_name = "";
			step = 0;
			break;
		case 31:
			token = { Terminals::SEMICOLON, "" };
			m_name = "";
			step = 0;
			break;
		case 32:
			token = { Terminals::COLON, "" };
			m_name = "";
			step = 0;
			break;
		case 35:
			token = { Terminals::ID, m_name };
			m_name = "";
			step = 0;
			break;
		case 36:
			token = { Terminals::ERROR, "" };
			m_name = "";
			step = 0;
			success = false;
			break;
		default:
			if (!m_file.fileEnd()) {
				step = eval(step);
				end = false;
			}
			else {
				token = { Terminals::FINISH, "" };
			}
		}
	}
	return token;;
}

bool Scanner::scan()
{
	bool success = true;
	//queue solange auffüllen, bis Datei zuende
	/*do{
		success = lookup();
	} while (!m_file.fileEnd() && success);
	m_file.closeFile();*/
	return success;
}

Token Scanner::lookup(bool consume)
{
	Token t;

	if (consume && tokenAlreadyScanned) { 
		//ret Temp, next time: new scan
		t = tempToken;
		tokenAlreadyScanned = false;
	}
	else if (consume && !tokenAlreadyScanned) {
		//new scan, no save
		t = automat();
	}
	else if (!consume && tokenAlreadyScanned) {
		//ret Temp, keep temp
		t = tempToken;
	}
	else {
		//!consume && !tokenAlreadyScanned
		//-> scan, save Token in temp
		t = automat();
		tempToken = t;
		tokenAlreadyScanned = true;
	}
	return t;
}

int Scanner::eval(int state)
{
	int nxt_state = state;
	char nxt = m_file.getNextChar();
	m_name += nxt;

	if (is_fin(nxt) && state != 0) {
		m_file.ungetChar();
		m_name.pop_back();
	}

	switch (state)
	{
	case 0:
		if (nxt == ' ') { nxt_state = 0; }
		else if (nxt == 'e') { nxt_state = 1; }
		else if (nxt == 'i') { nxt_state = 7; }
		else if (nxt == 's') { nxt_state = 16; }
		else if (nxt == 'o') { nxt_state = 22; }
		else if (nxt == 'g') { nxt_state = 25; }
		else if (nxt == ',') { nxt_state = 30; }
		else if (nxt == ';') { nxt_state = 31; }
		else if (nxt == ':') { nxt_state = 32; }
		else if (is_id_start(nxt)) { nxt_state = 33; }
		else (nxt_state = 36);
		break;
	case 1:
		if (nxt == 'v') { nxt_state = 2; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 2:
		if (nxt == 'e') { nxt_state = 3; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 3:
		if (nxt == 'n') { nxt_state = 4; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 4:
		if (nxt == 't') { nxt_state = 5; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 5:
		if (is_fin(nxt)) { nxt_state = 6; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 7:
		if (nxt == 'n') { nxt_state = 8; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 8:
		if (nxt == 'i') { nxt_state = 9; }
		else if (is_fin(nxt)) { nxt_state = 15; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 9:
		if (nxt == 't') { nxt_state = 10; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 10:
		if (nxt == 'i') { nxt_state = 11; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 11:
		if (nxt == 'a') { nxt_state = 12; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 12:
		if (nxt == 'l') { nxt_state = 13; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 13:
		if (is_fin(nxt)) { nxt_state = 14; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 16:
		if (nxt == 't') { nxt_state = 17; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 17:
		if (nxt == 'a') { nxt_state = 18; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 18:
		if (nxt == 't') { nxt_state = 19; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 19:
		if (nxt == 'e') { nxt_state = 20; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 20:
		if (is_fin(nxt)) { nxt_state = 21; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 22:
		if (nxt == 'n') { nxt_state = 23; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 23:
		if (is_fin(nxt)) { nxt_state = 24; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 25:
		if (nxt == 'o') { nxt_state = 26; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 26:
		if (nxt == 't') { nxt_state = 27; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 27:
		if (nxt == 'o') { nxt_state = 28; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 28:
		if (is_fin(nxt)) { nxt_state = 29; }
		else { nxt_state = StandardAlternatives(nxt); }
		break;
	case 33:
		if (is_id_end(nxt)) { nxt_state = 34; }
		else { nxt_state = 36; }
		break;
	case 34:
		nxt_state = StandardAlternatives(nxt);
		break;
	default:
		break;
	}

	return nxt_state;
}

int Scanner::StandardAlternatives(char c)
{
	char ret;
	if (is_id_end(c)) { ret = 34; }
	else if (is_fin(c)) { ret = 35; }
	else { ret = 36; }
	return ret;
}

bool Scanner::is_id_start(char c)
{
	//A: 65;Z: 90; a: 97; z: 122; _: 95
	bool a = (c >= 'A' && c <= 'Z');
	bool b = (c >= 'a' && c <= 'z');
	bool d = (c == '_');
	return (a || b || d);
}

bool Scanner::is_id_end(char c)
{
	bool a = is_id_start(c);
	bool b = (c >= '0' && c <= '9');
	return (a || b);
}

bool Scanner::is_fin(char c)
{
	return (c == ',' || c == ';' || c == ':' || c == ' ');
}
