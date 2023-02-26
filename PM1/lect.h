#pragma once
#include <string>
#include <map>
/**
* @brief Класс, содержащий данные об отдельном преподававателе.
*/
class lect
{
public:
	//! Имя преподавателя
	std::string name;
	//! Факультет преподавателя
	std::string fac;
	//! Ученое звание преподавателя
	std::string title;
	//! ученая степень преподавателя
	std::string degree;
	//! map-объект, содержащий наименования ученых степеней и их "вес".
	std::map<std::string, int> degrees = { {"AD",0},{"BD",1},{"FD",2},{"MD",3},{"DD",4} };
	// степени(degrees), расположенные в порядке возрастания: AD -> BD -> FD -> MD -> DD
	// звания(titles), расположенные в порядке возрастания:  Assistant Professor -> Associated Professor -> Senior Lecturer - совпадает с алфавитной сортировкой строк, отдельного объекта map с "весами" для сортировки не требуется
	/** @brief Инициализация значением
	*/
	void setData(std::string l_name, std::string  l_fac, std::string  l_degree, std::string  l_title);
	//! Метод очистки объекта класса lect
	void clear();
	/** @brief Геттер имени преподавателя
	*  @return string
	*/
	std::string getName() { return name; }
	/** @brief Геттер факультета преподавателя
	*  @return string
	*/
	std::string getFac() { return fac; }
	/** @brief Геттер звания преподавателя
	*  @return string
	*/
	std::string getTitle() { return title; }
	/** @brief Геттер степени преподавателя
	*  @return string
	*/
	std::string getDegree() { return degree; }
	/** @brief разыменование указателя
	*  @return lect
	*/
	lect operator*(lect lec) { return lec; }
	/** @brief Оператор сравнения(больше)
	*  @return bool
	*/
	friend bool operator> (lect c1, lect c2);
	/** @brief Оператор сравнения(меньше)
	*  @return bool
	*/
	friend bool operator< (lect c1, lect c2);
	/** @brief Оператор сравнения(меньше или равно)
	*  @return bool
	*/
	friend bool operator<= (lect c1, lect c2);
};
