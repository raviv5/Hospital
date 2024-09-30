#include "Article.h"
#include "Date.h"
#include <algorithm>


//----------------------------------------------------------------------------//
Article::Article() :m_PublishDate(1, 1, 2000)
{

}
//----------------------------------------------------------------------------//
Article::Article(ifstream infile)
{
	cin >>*this;
}

//----------------------------------------------------------------------------//
Article::Article(const Date& d, const string& p_magzine, const string& p_name) : m_PublishDate(d)
{
	setMagzineName(p_magzine);
	setName(p_name);
	if (all_of(m_magzinName.begin(), m_magzinName.end(), [](char c) {return c == ' '; }))
	{
		throw "Invalid magzine name ! name cant be empty !";
	}
	if (all_of(m_name.begin(), m_name.end(), [](char c) {return c == ' '; }))
	{
		throw "Invalid article name ! name cant be empty !";
	}
}
//----------------------------------------------------------------------------//
Article::Article(const Article& other) :m_PublishDate(other.m_PublishDate)
{
	*this = other;
}
//----------------------------------------------------------------------------//
Article::Article(Article&& other) :m_PublishDate(other.m_PublishDate)
{
	*this = std::move(other);

}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
const Date& Article::getPublishDate()      const
{
	return m_PublishDate;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const char* Article::getMagzineName()     const
{
	return m_magzinName.c_str();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const char* Article::getName()                  const
{
	return m_name.c_str();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Article::setDate(int d, int m, int y)
{
	m_PublishDate.setDay(d);
	m_PublishDate.setMonth(m);
	m_PublishDate.setYear(y);
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Article::setMagzineName(const string& p_magzineName)
{
	m_magzinName = p_magzineName;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Article::setName(const string& p_name)
{
	m_name = p_name;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Article::show()
{
	cout << "the name of the Article: " << m_name << endl << "published in the magzine: " << m_magzinName << endl << "publish Date: ";
	m_PublishDate.show();
	cout << endl;

}
//----------------------------------------------------------------------------//
const Article& Article::operator=(const Article& other)
{
	if (this != &other)
	{
		m_magzinName = other.m_magzinName;
		m_name = other.m_name;
		m_PublishDate = other.m_PublishDate;

	}
	return *this;
}
//----------------------------------------------------------------------------//
const Article& Article::operator=(Article&& other)
{
	std::swap(m_magzinName, other.m_magzinName);
	std::swap(m_name, other.m_name);
	m_PublishDate = other.m_PublishDate;
	return *this;
}
//----------------------------------------------------------------------------//
ostream& operator<<(ostream& os, const Article& article)
{

	if (typeid(os) == typeid(ofstream))
	{
		os << article.m_name <<endl<< article.m_magzinName <<endl<< article.m_PublishDate;
	}
	else
	{
		os << "the name of the Article: " << article.getName() << endl << "published in the magzine: " << article.getMagzineName() << endl << "publish Date: " << article.getPublishDate();
	}

	return os;

}
//----------------------------------------------------------------------------//

 istream& operator>>(istream& is, Article& article)
{
	 

	 is.ignore();
	 getline(is, article.m_name);
	 getline(is, article.m_magzinName);
	 is >>  article.m_PublishDate;
	 return is;
}