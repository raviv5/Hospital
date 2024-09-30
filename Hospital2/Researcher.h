#ifndef _RESEARCHER_H
#define _RESEARCHER_H

#include "Employee.h"
#include "Array.h"
#include "Article.h"

class Researcher : virtual public Employee
{
public:
	Researcher(ifstream& infile);
	Researcher(const string& p_name);
	virtual ~Researcher() {};
	Researcher(const Researcher& other) = delete;
	const Researcher& operator=(const Researcher& other) = delete;

	Array<Article>& getArticles();
	const int getNumOfArticles() const;

	void addArticle(Article article);
	virtual void show() const override;
	void showArticles()                         const;

	bool operator>(const Researcher& other);

	virtual void toOs(ostream& os) const override;
	virtual void fromOs(istream& in) override;

protected:

	Array<Article> arr;

};


#endif // !_RESEARCHER_H


