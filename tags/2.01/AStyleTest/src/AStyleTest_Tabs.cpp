//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace
{

//-----------------------------------------------------------------------------
// AStyle Tab Options
//-----------------------------------------------------------------------------

TEST(Tabs, Default)
{
	// test default indent of 4 spaces per tab
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"    if (isFoo)\n"
		"    {\n"
		"        bar();\n"
		"    }\n"
		"    else\n"
		"        anotherBar();\n"
		"}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, Spaces_8)
{
	// test indent of 8 spaces per tab
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo)\n"
		"        {\n"
		"                bar();\n"
		"        }\n"
		"        else\n"
		"                anotherBar();\n"
		"}\n";
	char options[] = "indent=spaces=8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, Spaces_Short8)
{
	// test indent of 8 spaces per tab
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"        if (isFoo)\n"
		"        {\n"
		"                bar();\n"
		"        }\n"
		"        else\n"
		"                anotherBar();\n"
		"}\n";
	char options[] = "s8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, Tab_Default)
{
	// test default tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 8 spaces
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	        && isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, Tab_DefaultShort)
{
	// test default tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 8 spaces
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	        && isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "t";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, Tab_8)
{
	// test tab indent of 8 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 16 spaces
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	                && isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "indent=tab=8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, Tab_Short8)
{
	// test tab indent of 8 spaces per tab
	// the '&& isBar' line will be indented with 2 tab widths or 16 spaces
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"	                && isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "t8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, ForceTab_Default)
{
	// test default force tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tabs instead of 8 spaces
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "indent=force-tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, ForceTab_DefaultShort)
{
	// test default force tab indent of 4 spaces per tab
	// the '&& isBar' line will be indented with 2 tabs instead of 8 spaces
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "T";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, ForceTab_8)
{
	// test default force tab indent of 8 spaces per tab
	// the result of this test is the same as the default option
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "indent=force-tab=8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

TEST(Tabs, ForceTab_Short8)
{
	// test default force tab indent of 8 spaces per tab
	// the result of this test is the same as the default option
	char text[] =
		"\nvoid Foo(bool isFoo)\n"
		"{\n"
		"	if (isFoo\n"
		"			&& isBar)\n"
		"	{\n"
		"		bar();\n"
		"	}\n"
		"	else\n"
		"		anotherBar();\n"
		"}\n";
	char options[] = "T8";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete [] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
