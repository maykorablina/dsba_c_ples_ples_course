#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "set"

enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
public:
    virtual ~Citation() {}
    virtual void printCitation(std::ostream& ostr) const = 0;
    // task 3 function included here
    virtual std::string getInlineCitation() const = 0;
    virtual int Type() const = 0;
    virtual std::string Info() const = 0;

protected:
    Citation(std::string t, int y) : _title(t), _year(y) {}
    std::string _title;
    int _year;
};

class PublishedWork : public Citation {
protected:
    std::string _firstname;
    std::string _lastname;
    PublishedWork(std::string fn, std::string ln, std::string t, int y) : Citation(t, y), _firstname(std::move(fn)), _lastname(ln) {}
};

class Article : public PublishedWork {
protected:
    std::string _journal;
    int _type = 0;
public:
    Article(std::string title, int year, std::string name, std::string surname, std::string journal) : PublishedWork(name, surname, title, year), _journal(journal) {}
    void printCitation(std::ostream& ostr) const override {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "Author: " << _firstname << ' ' << _lastname << std::endl;
        ostr << "Journal: " << _journal << std::endl;
    }
    std::string getInlineCitation() const override {
        std::string s = "[" + _lastname + ", " + std::to_string(_year) + "]";
        return s;
    }
    int Type() const override {
        return 0;
    }
    std::string Info() const override {
        return _lastname;
    }
};

// example 1 - Web Page
// you will need to modify it
class WebPage : public Citation
{
public:
    WebPage(const std::string& title, int year, const std::string& url)
        : Citation(title, year),
          _url(url)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "URL: " << _url << std::endl;
    }
    std::string getInlineCitation() const override {
        std::string s = "[Web page, " + std::to_string(_year) + "]";
        return s;
    }
    int Type() const override{
        return 1;
    }
    std::string Info() const override {
        return _title;
    }

protected:
    std::string _url;
    int _type = 1;
};


// example 2 - Book
// included only as an example, not used in the tasks
// class Book : public PublishedWork
// {
// public:
//     Book(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& publisher)
//         : PublishedWork(title, year, firstname, lastname),
//           _publisher(publisher)
//     {
//     }

//     void printCitation(std::ostream& ostr) const override
//     {
//         PublishedWork::printCitation(ostr);
//         ostr << "Publisher:" << _publisher << std::endl;
//     }

// protected:
//     std::string _publisher;
// };


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string> data)
{
    Citation* citationToAdd;
    if (type == CitationType::Article) {
        citationToAdd = new Article(data.at("title"), std::stoi(data.at("year")), data.at("firstname"), data.at("lastname"), data.at("journal"));
    }
    else {
        citationToAdd = new WebPage(data.at("title"), std::stoi(data.at("year")), data.at("url"));
    }
    citations[data.at("key")] = citationToAdd;
    return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::vector<std::string> keys;
    int index_start = 0;
    int length = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '{') {
            index_start = i;
            length += 1;
        }
        if (length > 0 and text[i] != '}') {
            length += 1;
        }
        if (text[i] == '}') {
//            length += 1;
            std::string key = text.substr(index_start, length);
//            std::cout << key << '\n';
            keys.push_back(key);
            length = 0;
        }
    }
    for (int i = 0; i < keys.size(); i++) {
        auto start = text.find(keys[i]);
        int length = keys[i].length();
        text.replace(start, length, citations.at(keys[i])->getInlineCitation());
    }
}


// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::vector<std::string> keys;
    int index_start = 0;
    int length = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '{') {
            index_start = i;
            length += 1;
        }
        if (length > 0 and text[i] != '}') {
            length += 1;
        }
        if (text[i] == '}') {
            std::string key = text.substr(index_start, length);
            if (std::find(keys.begin(), keys.end(), key) == keys.end()) {
                keys.push_back(key);
                std::cout << keys.size() << ".\n";
                citations.at(key)->printCitation(std::cout);
            }
            length = 0;
        }
    }
}


// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions


void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations) {
    std::vector<std::string> keys;
    std::vector<std::string> articles;
    std::vector<std::string> webpages;
    int index_start = 0;
    int length = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '{') {
            index_start = i;
            length += 1;
        }
        if (length > 0 and text[i] != '}') {
            length += 1;
        }
        if (text[i] == '}') {
            std::string key = text.substr(index_start, length);
            keys.push_back(key);
            if (citations.at(key)->Type() == 0) {
                if (std::find(articles.begin(), articles.end(), citations.at(key)->Info()) == articles.end()) {
                    articles.push_back(citations.at(key)->Info());
                }

            } else {
                if (std::find(webpages.begin(), webpages.end(), citations.at(key)->Info()) == webpages.end()) {
                    webpages.push_back(citations.at(key)->Info());
                }
            }
            length = 0;
        }
    }
    std::sort(articles.begin(), articles.end());
    std::sort(webpages.begin(), webpages.end());
    articles.insert(articles.end(), webpages.begin(), webpages.end());

    for (int i = 0; i < keys.size(); i++) {
        auto start = text.find(keys[i]);
        int length = keys[i].length();
        auto position = std::find(articles.begin(), articles.end(), citations.at(keys[i])->Info());
        int ind_pos = position - articles.begin() + 1;
        std::string ans = "[" + std::to_string(ind_pos) + "]";
        text.replace(start, length, ans);
    }

}
#endif