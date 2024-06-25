#ifndef SOLUTION_H
#define SOLUTION_H


#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>


enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
protected:
    std::string _title;
    int _year;

public:
    Citation(std::string  title, int year): _title(std::move(title)), _year(year){}

    virtual ~Citation() {}
    virtual void printCitation(std::ostream& out) const = 0;
    virtual std::string getInlineCitation() const = 0;
    virtual CitationType getType() const = 0;
    virtual std::string getInfo() const = 0;
};


// Task 1
class PublishedWork: public Citation
{
protected:
    std::string _firstname;
    std::string _lastname;

public:
    PublishedWork(const std::string& title, int year, std::string firstname, std::string lastname):
    Citation(title, year), _firstname(std::move(firstname)), _lastname(std::move(lastname)){}
};


class Article: public PublishedWork
{
private:
    std::string _journal;
    CitationType _type = CitationType::Article;

public:
    Article(const std::string& title, int year, std::string firstname, std::string lastname, std::string journal):
            PublishedWork(title, year, std::move(firstname), std::move(lastname)), _journal(std::move(journal)){}

    void printCitation(std::ostream& out) const override
    {
        out << "Title: " << _title << '\n'
            << "Year: " << _year << '\n'
            << "Author: " << _firstname << ' ' << _lastname << '\n'
            << "Journal: " << _journal << '\n';
    }

    std::string getInlineCitation() const override
    {
        return "[" +_lastname + ", " + std::to_string(_year) + "]";
    }

    std::string getInfo() const override
    {
        return _lastname;
    }

    CitationType getType() const override
    {
        return _type;
    }
};


class WebPage : public Citation
{
protected:
    std::string _url;
    CitationType _type = CitationType::WebPage;

public:
    WebPage(const std::string& title, int year, std::string  url): Citation(title, year), _url(std::move(url)){}

    void printCitation(std::ostream& out) const override
    {
        out << "Title: " << _title << '\n'
            << "Year: " << _year << '\n'
            << "URL: " << _url << '\n';
    }

    std::string getInlineCitation() const override
    {
        return "[Web page, " + std::to_string(_year) + "]";
    }

    std::string getInfo() const override
    {
        return _title;
    }

    CitationType getType() const override
    {
        return _type;
    }
};


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string>& data)
{
    Citation *citationToAdd;
    if (type == CitationType::WebPage)
    {
        citationToAdd = new WebPage(data.at("title"), std::stoi(data.at("year")), data.at("url"));
    }
    else
    {
        citationToAdd = new Article(data.at("title"), std::stoi(data.at("year")), data.at("firstname"),
                                    data.at("lastname"), data.at("journal"));
    }

    citations[data.at("key")] = citationToAdd;

    return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::string line = "", key = "";
    bool flag = true;

    for (char c : text)
    {
        if (flag and c != '{') line +=c;
        else if (flag and c == '{')
        {
            key += c;
            flag = false;
        }
        else if (!flag and c != '}') key += c;
        else if (!flag and c == '}')
        {
            key += c;
            line += citations.at(key)->getInlineCitation();
            flag = true;
            key.clear();
        }
    }

    text = line;
}


// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::vector<std::string> buf;
    std::string key = "";
    int counter = 1;
    bool flag = true;

    for (char c : text)
    {
        if (flag and c == '{')
        {
            key += c;
            flag = false;
        }
        else if (!flag and c != '}') key += c;
        else if (!flag and c == '}')
        {
            key += c;
            flag = true;

            if (std::find(buf.begin(), buf.end(), key) == buf.end())
            {
                std::cout << counter << ".\n";
                citations.at(key)->printCitation(std::cout);
                buf.push_back(key);
                counter++;
            }

            key.clear();
        }
    }
}


// task 6
void replaceToInt(std::string& text, std::map<std::string, std::string> dict)
{
    std::string line = "", key = "";
    bool flag = true;

    for (char c : text)
    {
        if (flag and c != '{') line +=c;
        else if (flag and c == '{')
        {
            key += c;
            flag = false;
        }
        else if (!flag and c != '}') key += c;
        else if (!flag and c == '}')
        {
            key += c;
            line += "[" + dict.at(key) + "]";
            flag = true;
            key.clear();
        }
    }

    text = line;
}

bool sorter(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b)
{
    return a.second < b.second;
}

void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::vector<std::string> buf;
    std::string key = "";
    bool flag = true;

    for (char c : text)
    {
        if (flag and c == '{')
        {
            key += c;
            flag = false;
        }
        else if (!flag and c != '}') key += c;
        else if (!flag and c == '}')
        {
            key += c;
            flag = true;

            if (std::find(buf.begin(), buf.end(), key) == buf.end()) buf.push_back(key);

            key.clear();
        }
    }

    std::map<std::string, std::string> dict;
    std::vector<std::pair<std::string, std::string>> comparison_art, comparison_web;
    std::pair<std::string, std::string> pair;

    for (const auto& el: buf){
        pair.first = el, pair.second = citations.at(el)->getInfo();
        if (citations.at(el)->getType() == CitationType::Article) comparison_art.push_back(pair);
        else comparison_web.push_back(pair);
    }

    std::sort(comparison_art.begin(), comparison_art.end(), sorter);
    std::sort(comparison_web.begin(), comparison_web.end(), sorter);

    for (int i = 0; i < comparison_art.size(); i++) dict[comparison_art[i].first] = std::to_string(i + 1);
    for (int i = 0; i < comparison_web.size(); i++) dict[comparison_web[i].first] = std::to_string(comparison_art.size() + i + 1);

    replaceToInt(text, dict);
}

#endif
