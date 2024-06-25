#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "solution.h"

void test1()
{
    Citation* artp1 = new Article("Title", 2023, "John", "Author", "Journal of Articles");
    artp1->printCitation(std::cout);
    PublishedWork* pubwork = new Article("Title", 2023, "John", "Author", "Journal of Articles");
    pubwork->printCitation(std::cout);

    Citation* artp2 = new WebPage("Title", 2023, "https://ya.ru");
    artp2->printCitation(std::cout);

    return;
}


void test2()
{
    std::map<std::string, Citation*> citations;

    std::map<std::string, std::string> dataWeb = {
         {"key", "{latex2023}"},
         {"title", "LaTeX"},
         {"year", "2023"},
         {"url", "https://en.wikipedia.org/wiki/LaTeX"}};



    std::map<std::string, std::string> dataArticle = {
         {"key", "{hdrc}"},
         {"title", "Gradient domain high dynamic range compression"},
         {"year", "2002"},
         {"journal", "Computer graphics and interactive techniques"},
         {"lastname", "Fattal"},
         {"firstname", "Raanan"}};


    addCitation(citations, CitationType::WebPage, dataWeb);
    addCitation(citations, CitationType::Article, dataArticle);

    for (std::map<std::string, Citation*>::value_type& citation: citations)
    {
        citation.second->printCitation(std::cout);
        delete citation.second;
    }

    return;
}

void test3()
{
    std::map<std::string, Citation*> citations;

    std::map<std::string, std::string> dataWeb = {
         {"key", "{latex2023}"},
         {"title", "LaTeX"},
         {"year", "2023"},
         {"url", "https://en.wikipedia.org/wiki/LaTeX"}};

    std::map<std::string, std::string> dataArticle = {
         {"key", "{hdrc}"},
         {"title", "Gradient domain high dynamic range compression"},
         {"year", "2002"},
         {"journal", "Computer graphics and interactive techniques"},
         {"lastname", "Fattal"},
         {"firstname", "Raanan"}};

    addCitation(citations, CitationType::WebPage, dataWeb);
    addCitation(citations, CitationType::Article, dataArticle);

    {
        const Citation* cit = citations["{latex2023}"];
        std::cout << cit->getInlineCitation() << std::endl;
    }
    {
        const Citation* cit = citations["{hdrc}"];
        std::cout << cit->getInlineCitation() << std::endl;
    }

    for (std::map<std::string, Citation*>::value_type& citation: citations) delete citation.second;
}



void test4()
{
    std::map<std::string, Citation*> citations;

    std::map<std::string, std::string> dataWeb = {
         {"key", "{latex2023}"},
         {"title", "LaTeX"},
         {"year", "2023"},
         {"url", "https://en.wikipedia.org/wiki/LaTeX"}};

    addCitation(citations, CitationType::WebPage, dataWeb);


    std::map<std::string, std::string> dataArticle = {
         {"key", "{hdrc}"},
         {"title", "Gradient domain high dynamic range compression"},
         {"year", "2002"},
         {"journal", "Computer graphics and interactive techniques"},
         {"lastname", "Fattal"},
         {"firstname", "Raanan"}};


    addCitation(citations, CitationType::Article, dataArticle);
    std::string text = "Long text with citations {latex2023}.\nThis has been referenced in {hdrc}.\n";
    insertInlineCitations(text, citations);
    std::cout << text;
    for (std::map<std::string, Citation*>::value_type& citation: citations) delete citation.second;
}



void test5()
{
    std::map<std::string, Citation*> citations;

    std::map<std::string, std::string> dataWeb = {
         {"key", "{latex2023}"},
         {"title", "LaTeX"},
         {"year", "2023"},
         {"url", "https://en.wikipedia.org/wiki/LaTeX"}};

    addCitation(citations, CitationType::WebPage, dataWeb);


    std::map<std::string, std::string> dataArticle = {
         {"key", "{hdrc}"},
         {"title", "Gradient domain high dynamic range compression"},
         {"year", "2002"},
         {"journal", "Computer graphics and interactive techniques"},
         {"lastname", "Fattal"},
         {"firstname", "Raanan"}};


    addCitation(citations, CitationType::Article, dataArticle);
    std::string text = "Long text with citations {hdrc}.\nThis has been referenced in {latex2023}.\n {hdrc}";
    std::cout << text << std::endl;
    printBibliographyAppearance(text, citations);

    for (std::map<std::string, Citation*>::value_type& citation: citations) delete citation.second;
}


void test6()
{
    std::map<std::string, Citation*> citations;

    std::map<std::string, std::string> dataWeb1 = {
         {"key", "{latex2023}"},
         {"title", "LaTeX"},
         {"year", "2023"},
         {"url", "https://en.wikipedia.org/wiki/LaTeX"}};

    std::map<std::string, std::string> dataWeb2 = {
         {"key", "{wikiarticle2}"},
         {"title", "Important article"}, {"year", "2023"},
         {"url", "https://en.wikipedia.org/wiki/Important"}};

    std::map<std::string, std::string> dataWeb3 = {
         {"key", "{wikiarticle3}"},
         {"title", "Very important article"},
         {"year", "2021"},
         {"url", "https://en.wikipedia.org/wiki/MoreImportant"}};

    std::map<std::string, std::string> dataArticle1 = {
         {"key", "{hdrc}"},
         {"title", "Gradient domain high dynamic range compression"},
         {"year", "2002"},
         {"journal", "Computer graphics and interactive techniques"},
         {"lastname", "Fattal"},
         {"firstname", "Raanan"}};

    std::map<std::string, std::string> dataArticle2 = {
        {"key", "{lastname2022a}"},
        {"title", "Gradient domain high dynamic range compression"},
        {"year", "2022"},
        {"journal", "Computer graphics and interactive techniques"},
        {"lastname", "Lastname"},
        {"firstname", "Person"}};

    std::map<std::string, std::string> dataArticle3 = {
        {"key", "{article1}"},
        {"title", "Ordering data automatically"},
        {"year", "2023"},
        {"journal", "Journal of Data"},
        {"lastname", "Aaronson"},
        {"firstname", "Person"}};

    addCitation(citations, CitationType::WebPage, dataWeb1);
    addCitation(citations, CitationType::WebPage, dataWeb2);
    addCitation(citations, CitationType::WebPage, dataWeb3);
    addCitation(citations, CitationType::Article, dataArticle1);
    addCitation(citations, CitationType::Article, dataArticle2);
    addCitation(citations, CitationType::Article, dataArticle3);

    std::string text = "Long text with citations {latex2023}.\n"
                       "This has been referenced in {hdrc}.\n"
                       "{wikiarticle2}\n"
                       "{wikiarticle3}\n"
                       "{lastname2022a}\n"
                       "{article1}\n";
    insertInlineAlphabetical(text, citations);
    std::cout << text << std::endl;

    for (std::map<std::string, Citation*>::value_type& citation: citations) delete citation.second;
}


int main()
{
    std::cout << "Test 1\n";
    test1();

    std::cout << "\nTest 2\n";
    test2();

    std::cout << "\nTest 3\n";
    test3();

    std::cout << "\nTest 4\n";
    test4();

    std::cout << "\nTest 5\n";
    test5();

    std::cout << "\nTest 6\n";
    test6();
    
    return 0;
}