#pragma once
// File HtmlTags.h

#include <iostream>
#include <strstream>

//==============================================================
// HTML Classes by G.Bavestrelli                   
// Copyright G.Bavestrelli 2000
// Any feedback is welcome, you can contact me at 
// giovanni.bavestrelli@pomini.it
//==============================================================

class htmltag
{
	std::ostream & m_Stream;
	std::string    m_CloseTag;

public:

	htmltag(std::ostream & stream, const std::string & OpenTag);
	~htmltag();

	static std::string
		str(const std::string & OpenTag, const std::string & Body = "");

private:

	static bool
		closingtag(const std::string & OpenTag,
			std::string & CloseTag);
};
