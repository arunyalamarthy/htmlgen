// File HtmlTags.cpp

#include "pch.h"
#include "assert.h"
#include "Htmltags.h"

using namespace std;

// Find the closing tag given the opening one
bool
htmltag::closingtag(const string & OpenTag, string & CloseTag)
{
	// String must not be empty
	assert(!OpenTag.empty());
	if (OpenTag.empty()) return false;

	// Find opening <
	string::size_type lesst = OpenTag.find('<');
	assert(lesst != string::npos);
	if (lesst == string::npos) return false;

	// Find closing >
	string::size_type great = OpenTag.find('>', lesst);
	assert(great != string::npos && great > lesst + 1);
	if (great == string::npos || great <= lesst + 1) return false;

	// Find space separating options, if any
	string::size_type space = OpenTag.find(' ', lesst);
	// Space must be after first char
	assert(space == string::npos || space > lesst + 1);
	if (space != string::npos && space <= lesst + 1) return false;

	// Now extract closing tag
	if (space == string::npos || space >= great)
	{
		CloseTag = "</";
		CloseTag.append(OpenTag, lesst + 1, great - lesst);
	}
	else
	{
		CloseTag = "</";
		CloseTag.append(OpenTag, lesst + 1, space - lesst - 1);
		CloseTag.append(">");
	}
	return true;
}

htmltag::htmltag(ostream & stream, const string & OpenTag)
	: m_Stream(stream)
{
	stream << OpenTag.c_str();
	closingtag(OpenTag, m_CloseTag);
}

htmltag::~htmltag()
{
	m_Stream << m_CloseTag.c_str() << "\r\n";
}

string htmltag::str(const string & OpenTag, const string & Body)
{
	string CloseTag, Result(OpenTag);
	closingtag(OpenTag, CloseTag);

	Result.append(Body);
	Result.append(CloseTag);
	Result.append("\r\n");

	return Result;
}