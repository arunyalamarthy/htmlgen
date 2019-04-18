// htmlgen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "htmltags.h"
#include <fstream>      // std::filebuf

void HelloWorld(std::ostream & o);

using namespace std;
int main()
{
	std::filebuf fb;
	fb.open("test.html", std::ios::out);
	std::ostream os(&fb);
	os << "Test sentence\n";
	HelloWorld(os);
	fb.close();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
void HelloWorld(std::ostream & o)
{
	htmltag HTML(o, "<HTML>\r\n");
	{
		htmltag HEAD(o, "<HEAD>\r\n");
		htmltag TITLE(o,
			"<TITLE>Simple Title");
	}
	htmltag BODY(o, "<BODY>");
	o << "Hello World";
}