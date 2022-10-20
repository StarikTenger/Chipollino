#pragma once
#include "BaseObject.h"
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct State {
	int index;
	// используется для объединения состояний в процессе работы алгоритмов
	// преобразования автоматов возможно для визуализации
	vector<int> label;
	string identifier;
	bool is_terminal;
	map<char, vector<int>> transitions;
	State();
	State(int index, vector<int> label, string identifier, bool is_terminal,
		  map<char, vector<int>> transitions);
	void set_transition(int, char);
};

class FiniteAutomaton : public BaseObject {
  private:
	bool is_deterministic = 0;
	int initial_state = 0;
	vector<char> alphabet;
	vector<State> states;

  public:
	FiniteAutomaton();
	FiniteAutomaton(int initial_state, vector<char> alphabet,
				  vector<State> states, bool is_deterministic = false);
	// визуализация автомата
	string to_txt() override;
	// поиск множества состояний НКА, достижимых из множества состояний по
	// eps-переходам (если флаг установлен в 0 - по всем переходам)
	vector<int> closure(const vector<int>&, bool);
	// детерминизация ДКА
	FiniteAutomaton determinize();
	// построение eps-замыкания
	FiniteAutomaton remove_eps();
	// минимизация ДКА (по Майхиллу-Нероуда)
	FiniteAutomaton minimize();
	// пересечение ДКА (на выходе - автомат, распознающий слова пересечения
	// языков L1 и L2)
	static FiniteAutomaton intersection(const FiniteAutomaton&,
									  const FiniteAutomaton&);
	// объединение ДКА (на выходе - автомат, распознающий слова объединенеия
	// языков L1 и L2)
	static FiniteAutomaton uunion(const FiniteAutomaton&, const FiniteAutomaton&);
	// разность ДКА (на выходе - автомат, распознающий слова разности языков L1
	// и L2)
	FiniteAutomaton difference(const FiniteAutomaton&);
	// дополнение ДКА (на выходе - автомат, распознающий язык L' = Σ* - L)
	FiniteAutomaton complement();
	// обращение НКА (на выходе - автомат, распознающий язык, обратный к L)
	FiniteAutomaton reverse();
	// добавление ловушки в ДКА(нетерминальное состояние с переходами только в
	// себя)
	FiniteAutomaton add_trap_state();
	// удаление ловушки
	FiniteAutomaton remove_trap_state();
	// объединение эквивалентных классов (принимает на вход вектор размера
	// states.size()) [i] элемент хранит номер класса [i] состояния
	FiniteAutomaton merge_equivalent_classes(vector<int>);
	// объединение эквивалентных по бисимуляции состояний
	FiniteAutomaton merge_bisimilar();
	// проверка автоматов на эквивалентность
	static bool equivalent(const FiniteAutomaton&, const FiniteAutomaton&); // TODO
	// проверка автоматов на равентсво(буквальное)
	static bool equal(const FiniteAutomaton&, const FiniteAutomaton&);
	// проверка автоматов на бисимилярность
	static bool bisimilar(const FiniteAutomaton&, const FiniteAutomaton&);
	// проверка автоматов на вложенность (аргумент вложен в this)
	bool subset(const FiniteAutomaton&); // TODO
									   // и тд
};