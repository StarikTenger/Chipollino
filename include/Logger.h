#pragma once
#include "AutomatonToImage.h"
#include "FiniteAutomaton.h"
#include "Tester.h"
#include <string>
using namespace std;

class Logger {
private:
	// счетчик картинок
	inline static int i = 0;
	// флаг включения логгирования
	inline static bool active = false;
	// флаг пропуска шага
	inline static bool skip = false;
public:
	Logger();
	~Logger();
	// установка флага логгирования
	static void activate();
	// сброс флага логгирования
	static void deactivate();
	// начало записи в файл
	static void init();
	// начало шага, передается название
	static void init_step(string step_name);
	// добавление записи
	static void log(string text);
	static void log(string text, string val);
	static void log(string a1, string a2, const FiniteAutomaton& fa1, const FiniteAutomaton& fa2);
	static void log(string a1, string a2, string a3, const FiniteAutomaton& fa1, const FiniteAutomaton& fa2, const FiniteAutomaton& fa3);
	static void log(string r1, string r2, int step, vector<Tester::word> words);
	static void log(const FiniteAutomaton& fa1, string r2, int step, vector<Tester::word> words1, vector<Tester::word> words2);
	// завершение шага
	static void finish_step();
	// завершение записи в файл
	static void finish();
	// пропуск шага
	static void skip_next_step();
};