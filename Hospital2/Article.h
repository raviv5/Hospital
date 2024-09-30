#ifndef _ARTICLE_H
#define _ARTICLE_H

#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)

#include "Date.h"

class Article
{
public:


	Article();
	Article(ifstream infile);
	Article(const Date& d, const string& p_magzine, const string& p_name) noexcept(false);
	Article(const Article& other);
	Article(Article&& other);


	const Date& getPublishDate()		const;
	const char* getMagzineName()		const;
	const char* getName()               const;

	void setDate(int d, int m, int y);
	void setMagzineName(const string& p_magzineName);
	void setName(const string& p_name);
	void show();

	const Article& operator=(const Article& other);
	const Article& operator=(Article&& other);
	friend ostream& operator<<(ostream& os, const Article& article);
	friend istream& operator>>(istream& is, Article& article);
private:
	Date  m_PublishDate;
	string m_magzinName;
	string m_name;

};

#endif // !_ARTICLE_H