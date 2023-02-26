/*
* @file lect.cpp
* @brief файл реализации класса lect
*/
#include "lect.h"
#include <iostream>

void lect::setData(std::string l_name, std::string l_fac, std::string l_degree, std::string l_title)
{
	name = l_name;
	fac = l_fac;
	title = l_title;
	degree = l_degree;
}

void lect::clear()
{
	name.clear(); fac.clear(); title.clear(); degree.clear();
}

bool operator>(lect c1, lect c2)
{
	if (c1.fac < c2.fac) { return false; }
	if (c1.fac > c2.fac) { return true; }
	if (c1.fac == c2.fac)
	{
		if (c1.name < c2.name) { return false; }
		if (c1.name > c2.name) { return true; }
		if (c1.name == c2.name)
		{
			if (c1.degrees[c1.degree] < c2.degrees[c2.degree]) { return false; }
			if (c1.degrees[c1.degree] > c2.degrees[c2.degree]) { return true; }
			if (c1.degrees[c1.degree] == c2.degrees[c2.degree])
			{
				if (c1.title < c2.title) { return false; }
				if (c1.title > c2.title) { return true; }
				if (c1.title == c2.title) { return false; }
			}
		}
	}

}

bool operator<(lect c1, lect c2)
{
	if (c1.fac > c2.fac) { return false; }
	if (c1.fac < c2.fac) { return true; }
	if (c1.fac == c2.fac)
	{
		if (c1.name > c2.name) { return false; }
		if (c1.name < c2.name) { return true; }
		if (c1.name == c2.name)
		{
			if (c1.degrees[c1.degree] > c2.degrees[c2.degree]) { return false; }
			if (c1.degrees[c1.degree] < c2.degrees[c2.degree]) { return true; }
			if (c1.degrees[c1.degree] == c2.degrees[c2.degree])
			{
				if (c1.title > c2.title) { return false; }
				if (c1.title < c2.title) { return true; }
				if (c1.title == c2.title) { return false; }
			}
		}
	}
}

bool operator<=(lect c1, lect c2)
{
	if (c1.fac > c2.fac) { return false; }
	if (c1.fac < c2.fac) { return true; }
	if (c1.fac == c2.fac)
	{
		if (c1.name > c2.name) { return false; }
		if (c1.name < c2.name) { return true; }
		if (c1.name == c2.name)
		{
			if (c1.degrees[c1.degree] > c2.degrees[c2.degree]) { return false; }
			if (c1.degrees[c1.degree] < c2.degrees[c2.degree]) { return true; }
			if (c1.degrees[c1.degree] == c2.degrees[c2.degree])
			{
				if (c1.title > c2.title) { return false; }
				if (c1.title < c2.title) { return true; }
				if (c1.title == c2.title) { return true; }
			}
		}
	}
}
