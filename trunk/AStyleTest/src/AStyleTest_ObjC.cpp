// AStyleTest_ObjC.cpp
// Copyright (c) 2018 by Jim Pattee <jimp03@email.com>.
// This code is licensed under the MIT License.
// License.md describes the conditions under which this software may be distributed.

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include "AStyleTest.h"

//----------------------------------------------------------------------------
// anonymous namespace
//----------------------------------------------------------------------------

namespace {
//
//----------------------------------------------------------------------------
// AStyle Objective-C Styles
//----------------------------------------------------------------------------

struct ObjCStyleF : public Test
{
	string textStr;
	const char* textIn;

	ObjCStyleF()
	{
		textStr =
		    "\n@interface Foo : NSObject {\n"
		    "    NSString* var1;\n"
		    "    NSString* var2;\n"
		    "}\n"
		    "@end\n"
		    "\n"
		    "@implementation Foo\n"
		    "\n"
		    "- (void) foo\n"
		    "{\n"
		    "    if (isFoo)\n"
		    "    {\n"
		    "        bar();\n"
		    "    }\n"
		    "}\n"
		    "\n"
		    "- (void) foo : (int) icon\n"
		    "    ofSize : (int) size {\n"
		    "    if (isFoo) {\n"
		    "        bar();\n"
		    "    }\n"
		    "}\n"
		    "\n"
		    "@end\n";
		textIn = textStr.c_str();
	}
};

TEST_F(ObjCStyleF, Default)
{
	// test default style option
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(textIn, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Allman)
{
	// test allman style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo)\n"
	    "    {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{\n"
	    "    if (isFoo)\n"
	    "    {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=allman";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Java)
{
	// test java style option
	char text[] =
	    "\n@interface Foo : NSObject {\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo {\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size {\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=java";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, KR)
{
	// test k&r style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=kr";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Stroustrup)
{
	// test stroustrup style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "     NSString* var1;\n"
	    "     NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "     if (isFoo) {\n"
	    "          bar();\n"
	    "     }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "     ofSize : (int) size\n"
	    "{\n"
	    "     if (isFoo) {\n"
	    "          bar();\n"
	    "     }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=stroustrup, indent=spaces=5";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Whitesmith)
{
	// test whitesmith style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "    {\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "    }\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "    {\n"
	    "    if (isFoo)\n"
	    "        {\n"
	    "        bar();\n"
	    "        }\n"
	    "    }\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "    {\n"
	    "    if (isFoo)\n"
	    "        {\n"
	    "        bar();\n"
	    "        }\n"
	    "    }\n"
	    "\n"
	    "@end\n";
	char options[] = "style=whitesmith";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, VTK)
{
	// test vtk style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo)\n"
	    "        {\n"
	    "        bar();\n"
	    "        }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{\n"
	    "    if (isFoo)\n"
	    "        {\n"
	    "        bar();\n"
	    "        }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=vtk";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Banner)
{
	// test banner style option
	char text[] =
	    "\n@interface Foo : NSObject {\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "    }\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo {\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "        }\n"
	    "    }\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size {\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "        }\n"
	    "    }\n"
	    "\n"
	    "@end\n";
	char options[] = "style=banner";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Gnu)
{
	// test gnu style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "  NSString* var1;\n"
	    "  NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "  if (isFoo)\n"
	    "    {\n"
	    "      bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "  ofSize : (int) size\n"
	    "{\n"
	    "  if (isFoo)\n"
	    "    {\n"
	    "      bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=gnu, indent=spaces=2";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Linux)
{
	// test linux style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "        NSString* var1;\n"
	    "        NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "        if (isFoo) {\n"
	    "                bar();\n"
	    "        }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "        ofSize : (int) size\n"
	    "{\n"
	    "        if (isFoo) {\n"
	    "                bar();\n"
	    "        }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=linux, indent=spaces=8";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Horstmann)
{
	// test horstmann style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{  NSString* var1;\n"
	    "   NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{  if (isFoo)\n"
	    "   {  bar();\n"
	    "   }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "   ofSize : (int) size\n"
	    "{  if (isFoo)\n"
	    "   {  bar();\n"
	    "   }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=horstmann, indent=spaces=3";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, 1TBS)
{
	// test 1tbs style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=1tbs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Google)
{
	// test google style option
	char text[] =
	    "\n@interface Foo : NSObject {\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo {\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size {\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=google";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Mozilla)
{
	// test mozilla style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=mozilla";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, WebKit)
{
	// test webkit style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=webkit";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Pico)
{
	// test pico style option
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{   NSString* var1;\n"
	    "    NSString* var2; }\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{   if (isFoo)\n"
	    "    {   bar(); } }\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{   if (isFoo)\n"
	    "    {   bar(); } }\n"
	    "\n"
	    "@end\n";
	char options[] = "style=pico";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST_F(ObjCStyleF, Lisp)
{
	// test lisp style option
	char text[] =
	    "\n@interface Foo : NSObject {\n"
	    "    NSString* var1;\n"
	    "    NSString* var2; }\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo {\n"
	    "    if (isFoo) {\n"
	    "        bar(); } }\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size {\n"
	    "    if (isFoo) {\n"
	    "        bar(); } }\n"
	    "\n"
	    "@end\n";
	char options[] = "style=lisp";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Method Prefix
//-------------------------------------------------------------------------

TEST(ObjCPadMethodPrefix, LongOption)
{
	// Test pad method prefix long option.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "-    (void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "- (void)Foo3;\n"
	    "\n"
	    "- (void)Foo4\n"
	    "{ }";
	char options[] = "pad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodPrefix, ShortOption)
{
	// Test pad method prefix short option.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "-    (void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "- (void)Foo3;\n"
	    "\n"
	    "- (void)Foo4\n"
	    "{ }";
	char options[] = "-xQ";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodPrefix, UnPadMethodPrefix)
{
	// Test objective-c with pad-method-prefix and unpad-method-prefix.
	// The result should be pad-method-prefix.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "-    (void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "- (void)Foo3;\n"
	    "\n"
	    "- (void)Foo4\n"
	    "{ }";
	char options[] = "pad-method-prefix, unpad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodPrefix, SansPadUnPad)
{
	// Test objective-c with no method prefix option.
	// The result should be no change.
	char text[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "-    (void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodPrefix, Comments)
{
	// Test pad method prefix with comments.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+ (void)Foo2;      // comment\n"
	    "-    (void)Foo3;   /* comment */\n"
	    "\n"
	    "-(void)Foo4        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void)Foo1;      // comment\n"
	    "+ (void)Foo2;      // comment\n"
	    "- (void)Foo3;      /* comment */\n"
	    "\n"
	    "- (void)Foo4       // comment\n"
	    "{ }";
	char options[] = "pad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodPrefix, PadParenOutComments)
{
	// Test pad method prefix with pad-paren-out.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+ (void)Foo2;      // comment\n"
	    "-    (void)Foo3;   /* comment */\n"
	    "\n"
	    "-(void)Foo4        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void) Foo1;     // comment\n"
	    "+ (void) Foo2;     // comment\n"
	    "- (void) Foo3;     /* comment */\n"
	    "\n"
	    "- (void) Foo4      // comment\n"
	    "{ }";
	char options[] = "pad-method-prefix, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodPrefix, SansReturnType)
{
	// Test pad method prefix without a return type.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-Foo1;       // comment\n"
	    "+ Foo2;      // comment\n"
	    "-    Foo3;   /* comment */\n"
	    "\n"
	    "-Foo4        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- Foo1;      // comment\n"
	    "+ Foo2;      // comment\n"
	    "- Foo3;      /* comment */\n"
	    "\n"
	    "- Foo4       // comment\n"
	    "{ }";
	char options[] = "pad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodPrefix, ReplacingTabs)
{
	// Test pad method prefix replacing tabs.
	char textIn[] =
	    "\n"
	    "-\t\t\t(void) URLHandle : (NSURLHandle*)sender;\n";
	char text[] =
	    "\n"
	    "- (void) URLHandle : (NSURLHandle*)sender;\n";
	char options[] = "pad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C UnPad Method Prefix
//-------------------------------------------------------------------------

TEST(ObjCUnPadMethodPrefix, LongOption)
{
	// Test unpad-method-prefix long option.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "-    (void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+(void)Foo2;\n"
	    "-(void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char options[] = "unpad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadMethodPrefix, ShortOption)
{
	// Test unpad method prefix short option.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+ (void)Foo2;\n"
	    "-    (void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+(void)Foo2;\n"
	    "-(void)Foo3;\n"
	    "\n"
	    "-(void)Foo4\n"
	    "{ }";
	char options[] = "-xR";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadMethodPrefix, Comments)
{
	// Test unpad-method-prefix with comments.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+ (void)Foo2;      // comment\n"
	    "-    (void)Foo3;   /* comment */\n"
	    "\n"
	    "-(void)Foo4        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+(void)Foo2;       // comment\n"
	    "-(void)Foo3;       /* comment */\n"
	    "\n"
	    "-(void)Foo4        // comment\n"
	    "{ }";
	char options[] = "unpad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadMethodPrefix, SansReturnType)
{
	// Test unpad-method-prefix without a return type.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-Foo1;       // comment\n"
	    "+ Foo2;      // comment\n"
	    "-    Foo3;   /* comment */\n"
	    "\n"
	    "-Foo4        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-Foo1;       // comment\n"
	    "+Foo2;       // comment\n"
	    "-Foo3;       /* comment */\n"
	    "\n"
	    "-Foo4        // comment\n"
	    "{ }";
	char options[] = "unpad-method-prefix";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadMethodPrefix, PadParenOutComments)
{
	// Test unpad method prefix with pad-paren-out.
	// Unpad method prefix has precedence over pad-paren-out.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+ (void)Foo2;      // comment\n"
	    "-    (void)Foo3;   /* comment */\n"
	    "\n"
	    "-(void)Foo4        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void) Foo1;      // comment\n"
	    "+(void) Foo2;      // comment\n"
	    "-(void) Foo3;      /* comment */\n"
	    "\n"
	    "-(void) Foo4       // comment\n"
	    "{ }";
	char options[] = "unpad-method-prefix, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Return Type
//-------------------------------------------------------------------------

TEST(ObjCPadReturnType, LongOption)
{
	// Test pad return type long option.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+(void)   Foo2;\n"
	    "\n"
	    "-(void)Foo3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void) Foo1;\n"
	    "+(void) Foo2;\n"
	    "\n"
	    "-(void) Foo3\n"
	    "{ }";
	char options[] = "pad-return-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadReturnType, ShortOption)
{
	// Test pad return type short option.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+(void)   Foo2;\n"
	    "\n"
	    "-(void)Foo3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void) Foo1;\n"
	    "+(void) Foo2;\n"
	    "\n"
	    "-(void) Foo3\n"
	    "{ }";
	char options[] = "-xq";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadReturnType, UnPadReturnType)
{
	// Test objective-c with pad-return-type and unpad-return-type.
	// The result should be pad-return-type.
	char textIn[] =
	    "\n"
	    "-(void) Foo1;\n"
	    "+(void)   Foo2;\n"
	    "\n"
	    "-(void) Foo3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void) Foo1;\n"
	    "+(void) Foo2;\n"
	    "\n"
	    "-(void) Foo3\n"
	    "{ }";
	char options[] = "pad-return-type, unpad-return-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadReturnType, SansPadUnPad)
{
	// Test objective-c with no return type option.
	// The result should be no change.
	char text[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+(void) Foo2;\n"
	    "\n"
	    "-(void)  Foo3\n"
	    "{ }";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadReturnType, Comments)
{
	// Test pad return type with comments.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+(void)   Foo2;    /* comment */\n"
	    "\n"
	    "-(void)Foo3        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void) Foo1;      // comment\n"
	    "+(void) Foo2;      /* comment */\n"
	    "\n"
	    "-(void) Foo3       // comment\n"
	    "{ }";
	char options[] = "pad-return-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadReturnType, PadParenOutComments)
{
	// Test pad return type with comments and pad-paren-out.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+(void)   Foo2;    /* comment */\n"
	    "\n"
	    "-(void)Foo3        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void) Foo1;     // comment\n"
	    "+ (void) Foo2;     /* comment */\n"
	    "\n"
	    "- (void) Foo3      // comment\n"
	    "{ }";
	char options[] = "pad-return-type, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadReturnType, ReplacingTabs)
{
	// Test pad return type replacing tabs.
	char textIn[] =
	    "\n"
	    "- (void)\t\t\tURLHandle : (NSURLHandle*)sender;\n";
	char text[] =
	    "\n"
	    "- (void) URLHandle : (NSURLHandle*)sender;\n";
	char options[] = "pad-return-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C UnPad Return Type
//-------------------------------------------------------------------------

TEST(ObjCUnPadReturnType, LongOption)
{
	// Test unpad return type long option.
	char textIn[] =
	    "\n"
	    "-(void)   Foo1;\n"
	    "+(void)Foo2;\n"
	    "\n"
	    "-(void) Foo3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+(void)Foo2;\n"
	    "\n"
	    "-(void)Foo3\n"
	    "{ }";
	char options[] = "unpad-return-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadReturnType, ShortOption)
{
	// Test unpad return type short option.
	char textIn[] =
	    "\n"
	    "-(void)   Foo1;\n"
	    "+(void)Foo2;\n"
	    "\n"
	    "-(void) Foo3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)Foo1;\n"
	    "+(void)Foo2;\n"
	    "\n"
	    "-(void)Foo3\n"
	    "{ }";
	char options[] = "-xr";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadReturnType, Comments)
{
	// Test unpad return type with comments.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)   Foo1;    // comment\n"
	    "+(void)Foo2;       /* comment */\n"
	    "\n"
	    "-(void) Foo3       // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+(void)Foo2;       /* comment */\n"
	    "\n"
	    "-(void)Foo3        // comment\n"
	    "{ }";
	char options[] = "unpad-return-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadReturnType, PadParenOutComments1)
{
	// Test unpad return type with pad-paren-out.
	// Unpad return type has precedence over pad-paren-out.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)Foo1;       // comment\n"
	    "+(void)   Foo2;    /* comment */\n"
	    "\n"
	    "-(void)Foo3        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void)Foo1;      // comment\n"
	    "+ (void)Foo2;      /* comment */\n"
	    "\n"
	    "- (void)Foo3       // comment\n"
	    "{ }";
	char options[] = "unpad-return-type, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadReturnType, PadParenOutComments2)
{
	// Test unpad return type with pad-paren-out and unpad method prefix.
	// Unpad return type and unpad method prefix has precedence over pad-paren-out.
	// The comment alignment should be maintained.
	char text[] =
	    "\n"
	    "-(NSString *)string;        // comment\n"
	    "+(NSHost *)localHost;       /* comment */\n";
	char options[] = "unpad-return-type, unpad-method-prefix, pad-paren-out";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadReturnType, PadParenOutComments3)
{
	// Test unpad return type with pad-paren-out.
	// The method prefix is padded in the input.
	// Unpad return type has precedence over pad-paren-out.
	// The comment alignment should be maintained.
	char text[] =
	    "\n"
	    "- (NSString *)string;       // comment\n"
	    "+ (NSHost *)localHost;      /* comment */\n";
	char options[] = "unpad-return-type, pad-paren-out";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Parameter Type
//-------------------------------------------------------------------------

TEST(ObjCPadParamType, LongOption)
{
	// Test pad param type long option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:    (bool)    barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)    barArg3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1: (bool) barArg1;\n"
	    "-(void)foo2: (bool) barArg2;\n"
	    "\n"
	    "-(void)foo3: (bool) barArg3\n"
	    "{ }";
	char options[] = "pad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, ShortOption)
{
	// Test pad param type short option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:    (bool)    barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)    barArg3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1: (bool) barArg1;\n"
	    "-(void)foo2: (bool) barArg2;\n"
	    "\n"
	    "-(void)foo3: (bool) barArg3\n"
	    "{ }";
	char options[] = "-xS";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, UnPadParamType)
{
	// Test objective-c with pad-param-type and unpad-param-type.
	// The result should be pad-param-type.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:    (bool)    barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)    barArg3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1: (bool) barArg1;\n"
	    "-(void)foo2: (bool) barArg2;\n"
	    "\n"
	    "-(void)foo3: (bool) barArg3\n"
	    "{ }";
	char options[] = "pad-param-type, unpad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, SansPadUnPad)
{
	// Test objective-c with no param type option.
	// The result should be no change.
	char text[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:    (bool)    barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)    barArg3\n"
	    "{ }";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, Comments)
{
	// Test pad param type with comments.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1: (bool) barArg1;     // comment\n"
	    "-(void)foo2: (bool) barArg2;     /* comment */\n"
	    "\n"
	    "-(void)foo3: (bool) barArg3      // comment\n"
	    "{ }";
	char options[] = "pad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, PadParenOut_Comments)
{
	// Test pad param type with comments and pad-paren-out.
	// This will cause a padded method colon after.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void) foo1: (bool) barArg1;   // comment\n"
	    "- (void) foo2: (bool) barArg2;   /* comment */\n"
	    "\n"
	    "- (void) foo3: (bool) barArg3    // comment\n"
	    "{ }";
	char options[] = "pad-param-type, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, PadParenIn_Comments)
{
	// Test pad-param-type with comments and pad-paren-in.
	// This will cause a padded method colon after.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-( void )foo1: ( bool ) barArg1; // comment\n"
	    "-( void )foo2: ( bool ) barArg2; /* comment */\n"
	    "\n"
	    "-( void )foo3: ( bool ) barArg3  // comment\n"
	    "{ }";
	char options[] = "pad-param-type, pad-paren-in";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, PadParen_Comments)
{
	// Test pad-param-type with comments and pad-paren.
	// This will cause a padded method colon after.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;         // comment\n"
	    "-(void)foo2:  (bool)   barArg2;    /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3        // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- ( void ) foo1: ( bool ) barArg1; // comment\n"
	    "- ( void ) foo2: ( bool ) barArg2; /* comment */\n"
	    "\n"
	    "- ( void ) foo3: ( bool ) barArg3  // comment\n"
	    "{ }";
	char options[] = "pad-param-type, pad-paren";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, PadMethodColonNone_Comments)
{
	// Test pad-param-type with comments and pad-method-colon=none.
	// This will cause a padded method colon after.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1: (bool) barArg1;     // comment\n"
	    "-(void)foo2: (bool) barArg2;     /* comment */\n"
	    "\n"
	    "-(void)foo3: (bool) barArg3      // comment\n"
	    "{ }";
	char options[] = "pad-param-type, pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, PadMethodColonAfter_Comments)
{
	// Test pad-param-type with comments and pad-method-colon=after.
	// This will cause a padded method colon after.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1: (bool) barArg1;     // comment\n"
	    "-(void)foo2: (bool) barArg2;     /* comment */\n"
	    "\n"
	    "-(void)foo3: (bool) barArg3      // comment\n"
	    "{ }";
	char options[] = "pad-param-type, pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, PadMethodColonBefore_Comments)
{
	// Test pad-param-type with comments and pad-method-colon=before.
	// This will cause a padded method colon after.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1 : (bool) barArg1;    // comment\n"
	    "-(void)foo2 : (bool) barArg2;    /* comment */\n"
	    "\n"
	    "-(void)foo3 : (bool) barArg3     // comment\n"
	    "{ }";
	char options[] = "pad-param-type, pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, PadMethodColonAll_Comments)
{
	// Test pad-param-type with comments and pad-method-colon=all.
	// This will cause a padded method colon after.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1 : (bool) barArg1;    // comment\n"
	    "-(void)foo2 : (bool) barArg2;    /* comment */\n"
	    "\n"
	    "-(void)foo3 : (bool) barArg3     // comment\n"
	    "{ }";
	char options[] = "pad-param-type, pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, MultipleParams)
{
	// Test pad param type with multiple params.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2 : (int)row1 : (int)row2 : (int)row3;\n"
	    "-(void)foo3: (int)row1: (int)row2: (int)row3;\n"
	    "-(void)foo4 :(int)row1 :(int)row2 :(int)row3;";
	char text[] =
	    "\n"
	    "-(void)foo1: (int) row1: (int) row2: (int) row3;\n"
	    "-(void)foo2 : (int) row1 : (int) row2 : (int) row3;\n"
	    "-(void)foo3: (int) row1: (int) row2: (int) row3;\n"
	    "-(void)foo4 : (int) row1 : (int) row2 : (int) row3;";
	char options[] = "pad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, MultipleParams_Comments)
{
	// Test pad param type with multiple params and comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2 : (int)row1 : (int)row2 : (int)row3;    // comment\n"
	    "-(void)foo3: (int)row1: (int)row2: (int)row3;       /* comment */\n"
	    "-(void)foo4 :(int)row1 :(int)row2 :(int)row3;       // comment";
	char text[] =
	    "\n"
	    "-(void)foo1: (int) row1: (int) row2: (int) row3;    // comment\n"
	    "-(void)foo2 : (int) row1 : (int) row2 : (int) row3; // comment\n"
	    "-(void)foo3: (int) row1: (int) row2: (int) row3;    /* comment */\n"
	    "-(void)foo4 : (int) row1 : (int) row2 : (int) row3; // comment";
	char options[] = "pad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadParamType, ReplacingTabs)
{
	// Test pad param type replacing tabs.
	char textIn[] =
	    "\n"
	    "- (void) URLHandle :\t\t\t(NSURLHandle*)\t\t\tsender :\t\t(int)\t\trow;\n";
	char text[] =
	    "\n"
	    "- (void) URLHandle : (NSURLHandle*) sender : (int) row;\n";
	char options[] = "pad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C UnPad Parameter Type
//-------------------------------------------------------------------------

TEST(ObjCUnPadParamType, LongOption)
{
	// Test pad param type long option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:    (bool)    barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)    barArg3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:(bool)barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)barArg3\n"
	    "{ }";
	char options[] = "unpad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, ShortOption)
{
	// Test pad param type short option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:    (bool)    barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)    barArg3\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;\n"
	    "-(void)foo2:(bool)barArg2;\n"
	    "\n"
	    "-(void)foo3:(bool)barArg3\n"
	    "{ }";
	char options[] = "-xs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, Comments)
{
	// Test unpad param type with comments.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:(bool)barArg2;       /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)barArg3        // comment\n"
	    "{ }";
	char options[] = "unpad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, PadParenOut_Comments)
{
	// Test unpad param type with comments and pad-paren-out.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (void) foo1:(bool)barArg1;     // comment\n"
	    "- (void) foo2:(bool)barArg2;     /* comment */\n"
	    "\n"
	    "- (void) foo3:(bool)barArg3      // comment\n"
	    "{ }";
	char options[] = "unpad-param-type, pad-paren-out";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, PadMethodColonNone_Comments)
{
	// Test unpad-param-type with comments and pad-method-colon=none.
	// This will cause an unpadded method colon.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:(bool)barArg2;       /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)barArg3        // comment\n"
	    "{ }";
	char options[] = "unpad-param-type, pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, PadMethodColonAfter_Comments)
{
	// Test unpad-param-type with comments and pad-method-colon=after.
	// This will cause a padded method colon.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1: (bool)barArg1;      // comment\n"
	    "-(void)foo2: (bool)barArg2;      /* comment */\n"
	    "\n"
	    "-(void)foo3: (bool)barArg3       // comment\n"
	    "{ }";
	char options[] = "unpad-param-type, pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, PadMethodColonBefore_Comments)
{
	// Test unpad-param-type with comments and pad-method-colon=before.
	// This will cause an unpadded method colon.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1 :(bool)barArg1;      // comment\n"
	    "-(void)foo2 :(bool)barArg2;      /* comment */\n"
	    "\n"
	    "-(void)foo3 :(bool)barArg3       // comment\n"
	    "{ }";
	char options[] = "unpad-param-type, pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, PadMethodColonAll_Comments)
{
	// Test unpad-param-type with comments and pad-method-colon=all.
	// This will cause a padded method colon.
	// The comment alignment should be maintained.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(bool)barArg1;       // comment\n"
	    "-(void)foo2:  (bool)   barArg2;  /* comment */\n"
	    "\n"
	    "-(void)foo3:(bool)  barArg3      // comment\n"
	    "{ }";
	char text[] =
	    "\n"
	    "-(void)foo1 : (bool)barArg1;     // comment\n"
	    "-(void)foo2 : (bool)barArg2;     /* comment */\n"
	    "\n"
	    "-(void)foo3 : (bool)barArg3      // comment\n"
	    "{ }";
	char options[] = "unpad-param-type, pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, MultipleParams)
{
	// Test unpad param type with multiple params.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2 : (int) row1 : (int) row2 : (int) row3;\n"
	    "-(void)foo3:  (int)  row1:  (int)  row2: (int) row3;\n"
	    "-(void)foo4 :(int) row1 :(int) row2 :(int) row3;";
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2 :(int)row1 :(int)row2 :(int)row3;\n"
	    "-(void)foo3:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo4 :(int)row1 :(int)row2 :(int)row3;";
	char options[] = "unpad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, MultipleParams_Comments)
{
	// Test unpad param type with multiple params and comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2 : (int) row1 : (int) row2 : (int) row3; // comment\n"
	    "-(void)foo3: (int)  row1: (int) row2: (int)  row3;  /* comment */\n"
	    "-(void)foo4 :(int) row1 :(int)row2 :(int)row3;      // comment";
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2 :(int)row1 :(int)row2 :(int)row3;       // comment\n"
	    "-(void)foo3:(int)row1:(int)row2:(int)row3;          /* comment */\n"
	    "-(void)foo4 :(int)row1 :(int)row2 :(int)row3;       // comment";
	char options[] = "unpad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCUnPadParamType, MethodDefinition_SquareBrackets)
{
	// Test unpad param type with square brackets in the method definition.
	char textIn[] =
	    "\n"
	    "-sendArray: (int[3]) a;\n";
	char text[] =
	    "\n"
	    "-sendArray:(int[3])a;\n";
	char options[] = "unpad-param-type";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Method Colon None
//-------------------------------------------------------------------------

TEST(ObjCPadMethodColonNone, LongOption)
{
	// Test pad-method-colon=none long option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2:(int)row;\n"
	    "-(void)foo3:(int)row;\n"
	    "-(void)foo4:(int)row;";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, ShortOption)
{
	// Test pad-method-colon=none short option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2:(int)row;\n"
	    "-(void)foo3:(int)row;\n"
	    "-(void)foo4:(int)row;";
	char options[] = "-xP0";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, MultipleSpaces)
{
	// Test pad-method-colon=none with multiple spaces.
	// This and pad-method-colon=all will test all options.
	char textIn[] =
	    "\n"
	    "-(void)foo  :   (int)row;";
	char text[] =
	    "\n"
	    "-(void)foo:(int)row;";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, Limits)
{
	// Test pad-method-colon=none with 'for' and 'while' loop limits.
	// This should not cause an exception.
	// This and pad-method-colon=all will test all options.
	char textIn[] =
	    "\n-(void)readHeader\n"
	    "{\n"
	    "    NSData *data = [file dataOfLength\n"
	    "    : HEADLEN\n"
	    "    atOffset :\n"
	    "    [NSNumber numberWithUnsignedLong\n"
	    ":\n"
	    "    0L]];\n"
	    "}";
	char text[] =
	    "\n-(void)readHeader\n"
	    "{\n"
	    "    NSData *data = [file dataOfLength\n"
	    "                         :HEADLEN\n"
	    "                         atOffset:\n"
	    "                         [NSNumber numberWithUnsignedLong\n"
	    "                          :\n"
	    "                          0L]];\n"
	    "}";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, SingleCharFollows)
{
	// Test pad-method-colon=none 'for' and 'while' loop limits.
	// The single char following the colon should be recognized.
	// This and pad-method-colon=all will test all options.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [[matrix cellAtRow:0 column:0] setTitle: NSLocalizedString(@\"Name\")];\n"
	    "    [[matrix cellAtRow: 1 column: 0] setTitle : NSLocalizedString(@\"Type\")];\n"
	    "    [[matrix cellAtRow:   2 column:   0] setTitle: NSLocalizedString(@\"Date\")];\n"
	    "    [[matrix cellAtRow   :3 column   :0] setTitle :NSLocalizedString(@\"Size\")];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [[matrix cellAtRow:0 column:0] setTitle:NSLocalizedString(@\"Name\")];\n"
	    "    [[matrix cellAtRow:1 column:0] setTitle:NSLocalizedString(@\"Type\")];\n"
	    "    [[matrix cellAtRow:2 column:0] setTitle:NSLocalizedString(@\"Date\")];\n"
	    "    [[matrix cellAtRow:3 column:0] setTitle:NSLocalizedString(@\"Size\")];\n"
	    "}";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, EndOfLineFollows)
{
	// The colon is at end-of-line.
	// This and pad-method-colon=all will test all options.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData :\n"
	    "     [handle readDataOfLength : nbytes]];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData:\n"
	    "                           [handle readDataOfLength:nbytes]];\n"
	    "}";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, Comment)
{
	// Test pad-method-colon=none with following comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;     // comment\n"
	    "-(void)foo2 : (int)row;   // comment\n"
	    "-(void)foo3: (int)row;    /* comment */\n"
	    "-(void)foo4 :(int)row;    // comment\n";
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row;     // comment\n"
	    "-(void)foo2:(int)row;     // comment\n"
	    "-(void)foo3:(int)row;     /* comment */\n"
	    "-(void)foo4:(int)row;     // comment\n";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, ParenFollows)
{
	// Test pad-method-colon=none with a following ')'.
	// The ending colon should not be padded.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction:@selector(colorChoosen : )];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction:@selector(colorChoosen:)];\n"
	    "}";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, MultipleParams)
{
	// Test pad-method-colon=none with multiple params.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3;\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;";
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo3:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo4:(int)row1:(int)row2:(int)row3;";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, MultipleParams_Comments)
{
	// Test pad-method-colon=none with multiple params and comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;      // comment\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3; /* coment */\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;   // comment";
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo3:(int)row1:(int)row2:(int)row3;          /* coment */\n"
	    "-(void)foo4:(int)row1:(int)row2:(int)row3;          // comment";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonNone, ReplacingTabs)
{
	// Test pad-method-colon=none replacing tabs.
	char textIn[] =
	    "\n"
	    "- (void) URLHandle:(NSURLHandle*) sender\t\t\t:\t\t\t(int) row;\n";
	char text[] =
	    "\n"
	    "- (void) URLHandle:(NSURLHandle*) sender:(int) row;\n";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Method Colon All
//-------------------------------------------------------------------------

TEST(ObjCPadMethodColonAll, LongOption)
{
	// Test pad-method-colon=all long option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1 : (int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3 : (int)row;\n"
	    "-(void)foo4 : (int)row;";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, ShortOption)
{
	// Test pad-method-colon=all short option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1 : (int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3 : (int)row;\n"
	    "-(void)foo4 : (int)row;";
	char options[] = "-xP1";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, MultipleSpaces)
{
	// Test pad-method-colon=all with multiple spaces.
	// This and pad-method-colon=none will test all options.
	char textIn[] =
	    "\n"
	    "-(void)foo  :   (int)row;";
	char text[] =
	    "\n"
	    "-(void)foo : (int)row;";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, Limits)
{
	// Test pad-method-colon=all with 'for' and 'while' loop limits.
	// This should not cause an exception.
	// This and pad-method-colon=none will test all options.
	char textIn[] =
	    "\n-(void)readHeader\n"
	    "{\n"
	    "    NSData *data = [file dataOfLength\n"
	    "    :HEADLEN\n"
	    "    atOffset:\n"
	    "    [NSNumber numberWithUnsignedLong\n"
	    ":\n"
	    "    0L]];\n"
	    "}";
	char text[] =
	    "\n-(void)readHeader\n"
	    "{\n"
	    "    NSData *data = [file dataOfLength\n"
	    "                         : HEADLEN\n"
	    "                         atOffset :\n"
	    "                         [NSNumber numberWithUnsignedLong\n"
	    "                          :\n"
	    "                          0L]];\n"
	    "}";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, SingleCharFollows)
{
	// Test pad-method-colon=all 'for' and 'while' loop limits.
	// The single char following the colon should be recognized.
	// This and pad-method-colon=none will test all options.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [[matrix cellAtRow:0 column:0] setTitle: NSLocalizedString(@\"Name\")];\n"
	    "    [[matrix cellAtRow: 1 column: 0] setTitle : NSLocalizedString(@\"Type\")];\n"
	    "    [[matrix cellAtRow:   2 column:   0] setTitle: NSLocalizedString(@\"Date\")];\n"
	    "    [[matrix cellAtRow   :3 column   :0] setTitle :NSLocalizedString(@\"Size\")];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [[matrix cellAtRow : 0 column : 0] setTitle : NSLocalizedString(@\"Name\")];\n"
	    "    [[matrix cellAtRow : 1 column : 0] setTitle : NSLocalizedString(@\"Type\")];\n"
	    "    [[matrix cellAtRow : 2 column : 0] setTitle : NSLocalizedString(@\"Date\")];\n"
	    "    [[matrix cellAtRow : 3 column : 0] setTitle : NSLocalizedString(@\"Size\")];\n"
	    "}";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, EndOfLineFollows)
{
	// The colon is at end-of-line.
	// This and pad-method-colon=none will test all options.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData:\n"
	    "     [handle readDataOfLength:nbytes]];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData :\n"
	    "                           [handle readDataOfLength : nbytes]];\n"
	    "}";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, Comment)
{
	// Test pad-method-colon=none with following comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;     // comment\n"
	    "-(void)foo2 : (int)row;   // comment\n"
	    "-(void)foo3: (int)row;    /* comment */\n"
	    "-(void)foo4 :(int)row;    // comment\n";
	char text[] =
	    "\n"
	    "-(void)foo1 : (int)row;   // comment\n"
	    "-(void)foo2 : (int)row;   // comment\n"
	    "-(void)foo3 : (int)row;   /* comment */\n"
	    "-(void)foo4 : (int)row;   // comment\n";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, ParenFollows)
{
	// Test pad-method-colon=all with a following ')'.
	// The ending colon should not be padded.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction : @selector(colorChoosen : )];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction : @selector(colorChoosen:)];\n"
	    "}";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, MultipleParams)
{
	// Test pad-method-colon=all with multiple params.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3;\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;";
	char text[] =
	    "\n"
	    "-(void)foo1 : (int)row1 : (int)row2 : (int)row3;\n"
	    "-(void)foo2 : (int)row1 : (int)row2 : (int)row3;\n"
	    "-(void)foo3 : (int)row1 : (int)row2 : (int)row3;\n"
	    "-(void)foo4 : (int)row1 : (int)row2 : (int)row3;";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, MultipleParams_Comments)
{
	// Test pad-method-colon=all with multiple params and comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;      // comment\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3; /* coment */\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;   // comment";
	char text[] =
	    "\n"
	    "-(void)foo1 : (int)row1 : (int)row2 : (int)row3;    // comment\n"
	    "-(void)foo2 : (int)row1 : (int)row2 : (int)row3;    // comment\n"
	    "-(void)foo3 : (int)row1 : (int)row2 : (int)row3;    /* coment */\n"
	    "-(void)foo4 : (int)row1 : (int)row2 : (int)row3;    // comment";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAll, ReplacingTabs)
{
	// Test pad-method-colon=all replacing tabs.
	char textIn[] =
	    "\n"
	    "- (void) URLHandle:(NSURLHandle*) sender\t\t\t:\t\t\t(int) row;\n";
	char text[] =
	    "\n"
	    "- (void) URLHandle : (NSURLHandle*) sender : (int) row;\n";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Method Colon After
//-------------------------------------------------------------------------

TEST(ObjCPadMethodColonAfter, LongOption)
{
	// Test pad-method-colon=after long option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1: (int)row;\n"
	    "-(void)foo2: (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4: (int)row;";
	char options[] = "pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAfter, ShortOption)
{
	// Test pad-method-colon=after short option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1: (int)row;\n"
	    "-(void)foo2: (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4: (int)row;";
	char options[] = "-xP2";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAfter, Comment)
{
	// Test pad-method-colon=none with following comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;     // comment\n"
	    "-(void)foo2 : (int)row;   // comment\n"
	    "-(void)foo3:  (int)row;   /* comment */\n"
	    "-(void)foo4 :(int)row;    // comment\n";
	char text[] =
	    "\n"
	    "-(void)foo1: (int)row;    // comment\n"
	    "-(void)foo2: (int)row;    // comment\n"
	    "-(void)foo3: (int)row;    /* comment */\n"
	    "-(void)foo4: (int)row;    // comment\n";
	char options[] = "pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAfter, ParenFollows)
{
	// Test pad-method-colon=after with a following ')'.
	// The ending colon should not be padded.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction : @selector(colorChoosen : )];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction: @selector(colorChoosen:)];\n"
	    "}";
	char options[] = "pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAfter, MultipleParams)
{
	// Test pad-method-colon=after with multiple params.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3;\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;";
	char text[] =
	    "\n"
	    "-(void)foo1: (int)row1: (int)row2: (int)row3;\n"
	    "-(void)foo2: (int)row1: (int)row2: (int)row3;\n"
	    "-(void)foo3: (int)row1: (int)row2: (int)row3;\n"
	    "-(void)foo4: (int)row1: (int)row2: (int)row3;";
	char options[] = "pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAfter, MultipleParams_Comments)
{
	// Test pad-method-colon=after with multiple params and comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;      // comment\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3; /* coment */\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;   // comment";
	char text[] =
	    "\n"
	    "-(void)foo1: (int)row1: (int)row2: (int)row3;       // comment\n"
	    "-(void)foo2: (int)row1: (int)row2: (int)row3;       // comment\n"
	    "-(void)foo3: (int)row1: (int)row2: (int)row3;       /* coment */\n"
	    "-(void)foo4: (int)row1: (int)row2: (int)row3;       // comment";
	char options[] = "pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonAfter, ReplacingTabs)
{
	// Test pad-method-colon=after replacing tabs.
	char textIn[] =
	    "\n"
	    "- (void) URLHandle:(NSURLHandle*) sender\t\t\t:\t\t\t(int) row;\n";
	char text[] =
	    "\n"
	    "- (void) URLHandle: (NSURLHandle*) sender: (int) row;\n";
	char options[] = "pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Method Colon Before
//-------------------------------------------------------------------------

TEST(ObjCPadMethodColonBefore, LongOption)
{
	// Test pad-method-colon=before long option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1 :(int)row;\n"
	    "-(void)foo2 :(int)row;\n"
	    "-(void)foo3 :(int)row;\n"
	    "-(void)foo4 :(int)row;";
	char options[] = "pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonBefore, ShortOption)
{
	// Test pad-method-colon=before short option.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char text[] =
	    "\n"
	    "-(void)foo1 :(int)row;\n"
	    "-(void)foo2 :(int)row;\n"
	    "-(void)foo3 :(int)row;\n"
	    "-(void)foo4 :(int)row;";
	char options[] = "-xP3";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonBefore, Comment)
{
	// Test pad-method-colon=none with following comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row;     // comment\n"
	    "-(void)foo2  : (int)row;  // comment\n"
	    "-(void)foo3: (int)row;    /* comment */\n"
	    "-(void)foo4 :(int)row;    // comment\n";
	char text[] =
	    "\n"
	    "-(void)foo1 :(int)row;    // comment\n"
	    "-(void)foo2 :(int)row;    // comment\n"
	    "-(void)foo3 :(int)row;    /* comment */\n"
	    "-(void)foo4 :(int)row;    // comment\n";
	char options[] = "pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonBefore, ParenFollows)
{
	// Test pad-method-colon=before with a following ')'.
	// The ending colon should not be padded.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction : @selector(colorChoosen : )];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [panel setAction :@selector(colorChoosen:)];\n"
	    "}";
	char options[] = "pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonBefore, MultipleParams)
{
	// Test pad-method-colon=before with multiple params.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3;\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;";
	char text[] =
	    "\n"
	    "-(void)foo1 :(int)row1 :(int)row2 :(int)row3;\n"
	    "-(void)foo2 :(int)row1 :(int)row2 :(int)row3;\n"
	    "-(void)foo3 :(int)row1 :(int)row2 :(int)row3;\n"
	    "-(void)foo4 :(int)row1 :(int)row2 :(int)row3;";
	char options[] = "pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonBefore, MultipleParams_Comments)
{
	// Test pad-method-colon=before with multiple paramsand comments.
	char textIn[] =
	    "\n"
	    "-(void)foo1:(int)row1:(int)row2:(int)row3;          // comment\n"
	    "-(void)foo2 : (int)row1 :(int)row2: (int)row3;      // comment\n"
	    "-(void)foo3:   (int)row1   :(int)row2:   (int)row3; /* coment */\n"
	    "-(void)foo4 :(int)row1:(int)row2   :   (int)row3;   // comment";
	char text[] =
	    "\n"
	    "-(void)foo1 :(int)row1 :(int)row2 :(int)row3;       // comment\n"
	    "-(void)foo2 :(int)row1 :(int)row2 :(int)row3;       // comment\n"
	    "-(void)foo3 :(int)row1 :(int)row2 :(int)row3;       /* coment */\n"
	    "-(void)foo4 :(int)row1 :(int)row2 :(int)row3;       // comment";
	char options[] = "pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonBefore, ReplacingTabs)
{
	// Test pad-method-colon=before replacing tabs.
	char textIn[] =
	    "\n"
	    "- (void) URLHandle:(NSURLHandle*) sender\t\t\t:\t\t\t(int) row;\n";
	char text[] =
	    "\n"
	    "- (void) URLHandle :(NSURLHandle*) sender :(int) row;\n";
	char options[] = "pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Pad Method Colon Other
//-------------------------------------------------------------------------

TEST(ObjCPadMethodColonOther, NoOption)
{
	// Test without pad-method-colon option.
	// Statements should not change.
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row;\n"
	    "-(void)foo2 : (int)row;\n"
	    "-(void)foo3: (int)row;\n"
	    "-(void)foo4 :(int)row;";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonOther, Selector)
{
	// Test pad-method-colon=all within a @selector.
	// The ending colon should not be padded.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    cutTitleSel = @selector(cutTitle:toFitWidth:);\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    cutTitleSel = @selector(cutTitle : toFitWidth:);\n"
	    "}";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonOther, ScopeResolution)
{
	// pad-method-colon should not pad a scope resolution operator.
	char text[] =
	    "\nconst char* TiXmlBase::errorString[TiXmlBase::TIXML_ERROR_STRING_COUNT] =\n"
	    "{\n"
	    "};\n"
	    "\n"
	    "void GetDetectorState(DetectorState[nsUniversalDetector::NumDetectors], PRUint32& offset )\n"
	    "{\n"
	    "    ListStyles style[Logger::num_levels];\n"
	    "}";
	char options[] = "pad-method-colon=all";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonOther, QuestionColon1)
{
	// Test pad-method-colon=none with '?' and ':'.
	// This should not remove the padding.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [caseSensButt setState : ([entry boolValue] ? NSOnState : NSOffState)];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [caseSensButt setState:([entry boolValue] ? NSOnState : NSOffState)];\n"
	    "}";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonOther, QuestionColon2)
{
	// Test pad-method-colon=none with '?' and ':'.
	// This should not remove the padding for '? :'.
	// But should remove for the method call.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    fsfilter = fsattribute ? [info objectForKey : @\"fsfilter\"] : nil;\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    fsfilter = fsattribute ? [info objectForKey:@\"fsfilter\"] : nil;\n"
	    "}";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonOther, QuestionColon3)
{
	// Test pad-method-colon=none with '?' and ':'.
	// This should not remove the padding for '? :'.
	// But should remove for the method call.
	char textIn[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    FSNode *pnode = (i == 0) ? nil : [components objectAtIndex : (i-1)];\n"
	    "}";
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    FSNode *pnode = (i == 0) ? nil : [components objectAtIndex:(i-1)];\n"
	    "}";
	char options[] = "pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCPadMethodColonOther, CSharpFile)
{
	// pad-method-colon should not pad in a C# file.
	char text[] =
	    "\n[global::System.Diagnostics.DebuggerNonUserCodeAttribute()]\n"
	    "[global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]\n"
	    "\n"
	    "[assembly: AssemblyTitle(\"TreeMaps\")]\n"
	    "[assembly: AssemblyDescription("")]\n"
	    "\n"
	    "[field: NonSerialized]\n"
	    "public class GitVersion: IDocumentVersion\n"
	    "{\n"
	    "    [param: MarshalAs(UnmanagedType.Currency)]\n"
	    "    [return: MarshalAs(UnmanagedType.Bool)]\n"
	    "}";
	char options[] = "pad-method-colon=all, mode=cs";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Align Method Colon for Method Definition
//-------------------------------------------------------------------------

TEST(ObjCAlignMethodColonDef, LongOption)
{
	// Test align-method-colon long option.
	char text[] =
	    "\n"
	    "- (BOOL)tableView:(NSTableView *)tableView\n"
	    "       acceptDrop:(id <NSDraggingInfo>)info\n"
	    "              row:(int)row";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, ShortOption)
{
	// Test align-method-colon short option.
	char text[] =
	    "\n"
	    "- (BOOL)tableView:(NSTableView *)tableView\n"
	    "       acceptDrop:(id <NSDraggingInfo>)info\n"
	    "              row:(int)row";
	char options[] = "-xM";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, Headers)
{
	// Test align-method-colon headers.
	char text[] =
	    "\n"
	    "- (BOOL)tableView:(NSTableView *)tableView\n"
	    "       acceptDrop:(id <NSDraggingInfo>)info\n"
	    "              row:(int)row;\n"
	    "\n"
	    "- (id)tableView:(NSTableView *)aTableView\n"
	    "    objectValueForTableColumn:(NSTableColumn *)aTableColumn\n"
	    "                          row:(int)rowIndex;\n"
	    "\n"
	    "- (BOOL)openFile:(NSString *)fullPath\n"
	    "    withApplication:(NSString *)appname\n"
	    "      andDeactivate:(BOOL)flag;";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, MethodsBreak)
{
	// Test align-method-colon methods with broken braces.
	char text[] =
	    "\n"
	    "- (BOOL)tableView:(NSTableView *)tableView\n"
	    "       acceptDrop:(id <NSDraggingInfo>)info\n"
	    "              row:(int)row\n"
	    "{ }\n"
	    "\n"
	    "- (id)tableView:(NSTableView *)aTableView\n"
	    "    objectValueForTableColumn:(NSTableColumn *)aTableColumn\n"
	    "                          row:(int)rowIndex\n"
	    "{ }\n"
	    "\n"
	    "- (BOOL)openFile:(NSString *)fullPath\n"
	    "    withApplication:(NSString *)appname\n"
	    "      andDeactivate:(BOOL)flag\n"
	    "{ }\n";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, MethodsAttach)
{
	// Test align-method-colon methods with attached braces.
	char text[] =
	    "\n"
	    "- (BOOL)tableView:(NSTableView *)tableView\n"
	    "       acceptDrop:(id <NSDraggingInfo>)info\n"
	    "              row:(int)row {\n"
	    "}\n"
	    "\n"
	    "- (id)tableView:(NSTableView *)aTableView\n"
	    "    objectValueForTableColumn:(NSTableColumn *)aTableColumn\n"
	    "                          row:(int)rowIndex {\n"
	    "}\n"
	    "\n"
	    "- (BOOL)openFile:(NSString *)fullPath\n"
	    "    withApplication:(NSString *)appname\n"
	    "      andDeactivate:(BOOL)flag {\n"
	    "}\n";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, MethodsAttachToLongest)
{
	// Test align-method-colon methods with attached braces.
	// Attached brace is the longest line.
	char text[] =
	    "\n"
	    "- (void)short : (GTMFoo *)theFoo\n"
	    "          longKeyword : (NSRect)theRect\n"
	    "                error : (NSError **)theError\n"
	    "    evenLongerKeyword : (float)theInterval {\n"
	    "}\n";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, MultiLineDefinition)
{
	// Test align-method-colon methods with multi-line definition.
	// Semicolon is the longest line.
	char text[] =
	    "\n"
	    "- (void)short : (GTMFoo *)theFoo\n"
	    "          longKeyword : (NSRect)theRect\n"
	    "                error : (NSError **)theError\n"
	    "    evenLongerKeyword : (float)theInterval;\n";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, Define1)
{
	// Test align-method-colon methods with a define.
	// The define should not be formatted.
	char text[] =
	    "\n"
	    "#define BZ_UPDATE_CRC(crcVar,cha)            \\\n"
	    "{                                            \\\n"
	    "   crcVar = (crcVar << 8) ^                  \\\n"
	    "            BZ2_crc32Table[(crcVar >> 24) ^  \\\n"
	    "                           ((UChar)cha)];    \\\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, Define2)
{
	// Test align-method-colon methods with an indented define.
	// The define should be formatted correctly.
	char textIn[] =
	    "\n"
	    "#define BZ_UPDATE_CRC(crcVar,cha)            \\\n"
	    "{                                            \\\n"
	    "   crcVar = (crcVar << 8) ^                  \\\n"
	    "            BZ2_crc32Table[(crcVar >> 24) ^  \\\n"
	    "                           ((UChar)cha)];    \\\n"
	    "}";
	char text[] =
	    "\n"
	    "#define BZ_UPDATE_CRC(crcVar,cha)            \\\n"
	    "    {                                            \\\n"
	    "        crcVar = (crcVar << 8) ^                  \\\n"
	    "                 BZ2_crc32Table[(crcVar >> 24) ^  \\\n"
	    "                                ((UChar)cha)];    \\\n"
	    "    }";
	char options[] = "align-method-colon, indent-preproc-define";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, PadMethodColonNone)
{
	// Test align-method-colon with pad-method-colon=none.
	char textIn[] =
	    "\n"
	    "- (id)tableView :(NSTableView *)aTableView\n"
	    "    objectValueForTableColumn : (NSTableColumn *)aTableColumn\n"
	    "                          row   :  (int)rowIndex\n"
	    "{ }\n";
	char text[] =
	    "\n"
	    "- (id)tableView:(NSTableView *)aTableView\n"
	    "    objectValueForTableColumn:(NSTableColumn *)aTableColumn\n"
	    "                          row:(int)rowIndex\n"
	    "{ }\n";
	char options[] = "align-method-colon, pad-method-colon=none";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, PadMethodColonAll)
{
	// Test align-method-colon with pad-method-colon=all.
	char textIn[] =
	    "\n"
	    "- (id)tableView : (NSTableView *)aTableView\n"
	    "    objectValueForTableColumn:(NSTableColumn *)aTableColumn\n"
	    "                          row   :  (int)rowIndex\n"
	    "{ }\n";
	char text[] =
	    "\n"
	    "- (id)tableView : (NSTableView *)aTableView\n"
	    "    objectValueForTableColumn : (NSTableColumn *)aTableColumn\n"
	    "                          row : (int)rowIndex\n"
	    "{ }\n";
	char options[] = "align-method-colon, pad-method-colon=all";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, PadMethodColonAfter)
{
	// Test align-method-colon with pad-method-colon=after.
	char textIn[] =
	    "\n"
	    "- (id)tableView :(NSTableView *)aTableView\n"
	    "    objectValueForTableColumn : (NSTableColumn *)aTableColumn\n"
	    "                          row   :  (int)rowIndex\n"
	    "{ }\n";
	char text[] =
	    "\n"
	    "- (id)tableView: (NSTableView *)aTableView\n"
	    "    objectValueForTableColumn: (NSTableColumn *)aTableColumn\n"
	    "                          row: (int)rowIndex\n"
	    "{ }\n";
	char options[] = "align-method-colon, pad-method-colon=after";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, PadMethodColonBefore)
{
	// Test align-method-colon with pad-method-colon=before.
	char textIn[] =
	    "\n"
	    "- (id)tableView: (NSTableView *)aTableView\n"
	    "    objectValueForTableColumn : (NSTableColumn *)aTableColumn\n"
	    "                          row   :  (int)rowIndex\n"
	    "{ }\n";
	char text[] =
	    "\n"
	    "- (id)tableView :(NSTableView *)aTableView\n"
	    "    objectValueForTableColumn :(NSTableColumn *)aTableColumn\n"
	    "                          row :(int)rowIndex\n"
	    "{ }\n";
	char options[] = "align-method-colon, pad-method-colon=before";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, LineContainsTabs)
{
	// Align method definition with embedded tabs.
	char text[] =
	    "\n"
	    "-	(BOOL)	openAppFile: (NSString*)fullPath\n"
	    "        withApplication: (NSString*)appname\n"
	    "          andDeactivate: (BOOL)flag {\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, ExternC1)
{
	// Align method definition enclosed in 'extern c'.
	char text[] =
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "extern \"C\" {\n"
	    "#endif\n"
	    "\n"
	    "@interface A {}\n"
	    "- (void)method:(NSInteger)parameter;\n"
	    "@end\n"
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "}\n"
	    "#endif";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonDef, ExternC2)
{
	// Align method definition enclosed in 'extern c'.
	char text[] =
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "extern \"C\" {\n"
	    "#endif\n"
	    "\n"
	    "- (NSDateComponents *) components: (NSUInteger) unitFlags\n"
	    "                         fromDate: (NSDate *) startingDate\n"
	    "                           toDate: (NSDate *) resultDate\n"
	    "                          options: (NSUInteger) opts;\n"
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "}\n"
	    "#endif";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Align Method Colon for Method Call
//-------------------------------------------------------------------------

TEST(ObjCAlignMethodColonCall, LongOption)
{
	// Test align-method-colon long option.
	char text[] =
	    "\n"
	    "-(void)Foo\n"
	    "{\n"
	    "    [myObj methodCall:arg1\n"
	    "                 key2:arg2\n"
	    "             keyword3:arg3\n"
	    "                error:arg4];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, ShortOption)
{
	// Test align-method-colon short option.
	char text[] =
	    "\n"
	    "-(void)Foo\n"
	    "{\n"
	    "    [myObj methodCall:arg1\n"
	    "                 key2:arg2\n"
	    "             keyword3:arg3\n"
	    "                error:arg4];\n"
	    "}";
	char options[] = "-xM";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, AlignToLongest)
{
	// Test align-method-colon with a long arg.
	char text[] =
	    "\n"
	    "-(void)Foo\n"
	    "{\n"
	    "    [myObj short:arg1\n"
	    "              longKeyword:arg2\n"
	    "        evenLongerKeyword:arg3\n"
	    "                    error:arg4];\n"
	    "}\n";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, NoColonOnLine1)
{
	// Test methods with no colon on line1.
	// Should align on longest colon.
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row\n"
	    "{\n"
	    "    [[NSNotificationCenter default Center]\n"
	    "                   object:self\n"
	    "     postNotificationName:myNotification\n"
	    "                 userinfo:nil];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, NoKeywordOnLine1)
{
	// Test methods with no keyword on line1.
	// Should align on the object.
	char text[] =
	    "\n"
	    "void foo()\n"
	    "{\n"
	    "    NSArray*  eqParts = [equation\n"
	    "                         componentsSeparatedByCharactersInSet:\n"
	    "                         [NSCharacterSet whitespaceCharacterSet]];\n"
	    "    Employee* joeBlow = [[Employee alloc]\n"
	    "                         firstName:@\"Joe\"\n"
	    "                          lastname:@\"Blow\"\n"
	    "                         birthDate:\n"
	    "                               ssn:@\"555-12-1212\"];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, MethodAssignment1)
{
	// Test align-method-colon in an assignment.
	char text[] =
	    "\n-(void) Foo\n"
	    "{\n"
	    "    NSDateComponents* components = [calendar components:(NSYearCalendarUnit)\n"
	    "                                               fromDate:today];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, MethodAssignment2)
{
	// Test align-method-colon in an assignment with a continuation.
	char text[] =
	    "\n"
	    "void Foo()\n"
	    "{\n"
	    "    NSString* homeDirectory =\n"
	    "        [NSString stringWithCString: homeDirectoryChar\n"
	    "                           encoding: [NSString defaultCStringEncoding]];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, MethodAssignment3)
{
	// Test align-method-colon in an assignment with run-in braces and continuation.
	char text[] =
	    "\n"
	    "void Foo()\n"
	    "{   NSString* homeDirectory =\n"
	    "        [NSString stringWithCString: homeDirectoryChar\n"
	    "                           encoding: [NSString defaultCStringEncoding]];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, ColonAtEnd1)
{
	// The colon is at end of line .
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData :\n"
	    "                           nSMutableDataBytes\n"
	    "                     readDataOfLength : nbytes];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, ColonAtEnd2)
{
	// The colon is at end of line with following object.
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData :\n"
	    "                           [handle readDataOfLength : nbytes]];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, ColonAtEnd3)
{
	// The colon is at end of line with following object.
	char text[] =
	    "\n"
	    "void Foo()\n"
	    "{\n"
	    "    nextEvent = [[self window] nextEventMatchingMask:\n"
	    "                               NSLeftMouseUpMask | NSLeftMouseDraggedMask];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, RunInBraces1)
{
	// Align with run-in braces.
	char text[] =
	    "\n"
	    "NSString* getText(NSString* filePath)\n"
	    "{   NSString* textIn = [NSString contentsOfFile: filePath\n"
	    "                                       encoding: NSASCIIStringEncoding\n"
	    "                                          error: NULL];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, RunInBraces2)
{
	// Align with run-in braces.
	// When a method call follows a method definition the variables
	// must be cleared.
	char text[] =
	    "\n"
	    "-(void)longKeyword:(GTMFoo *)theFoo\n"
	    "           keyword:(float)theInterval\n"
	    "             error:(NSError **)theError\n"
	    "{   [myObj longKeyword:arg1\n"
	    "               keyword:arg3\n"
	    "                 error:arg4];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, AttachedBraces)
{
	// Align with attached braces.
	// When a method call follows a method definition the variables
	// must be cleared.
	char text[] =
	    "\n"
	    "-(void)longKeyword:(GTMFoo *)theFoo\n"
	    "           keyword:(float)theInterval\n"
	    "             error:(NSError **)theError {\n"
	    "    [myObj longKeyword:arg1\n"
	    "               keyword:arg3\n"
	    "                 error:arg4];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, RunInBracesTabs1)
{
	// Align with run-in braces and tabbed indents.
	char text[] =
	    "\n"
	    "NSString* getText(NSString* filePath)\n"
	    "{	NSString* textIn = [NSString contentsOfFile: filePath\n"
	    "	                                   encoding: NSASCIIStringEncoding\n"
	    "	                                      error: NULL];\n"
	    "}";
	char options[] = "align-method-colon, indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, RunInBracesTabs2)
{
	// Align with run-in braces and tabbed indents with embedded tabs.
	char text[] =
	    "\n"
	    "NSString* getText(NSString* filePath)\n"
	    "{	NSString* textIn =	[NSString	contentsOfFile: filePath\n"
	    "	                                      encoding: NSASCIIStringEncoding\n"
	    "	                                         error: NULL];\n"
	    "}";
	char options[] = "align-method-colon, indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, InStatementValue)
{
	// Align with parens in a value computation.
	char text[] =
	    "\n"
	    "-(void) Foo\n"
	    "{\n"
	    "    NSDateComponents* components =\n"
	    "        [calendar components:(NSYearCalendarUnit |\n"
	    "                              NSMonthCalendarUnit |\n"
	    "                              NSDayCalendarUnit)\n"
	    "                    fromDate:today];\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCAlignMethodColonCall, ExternC)
{
	// Test align-method-colon in an 'extern c'.
	char text[] =
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "extern \"C\" {\n"
	    "#endif\n"
	    "\n"
	    "-(void)Foo\n"
	    "{\n"
	    "    [myObj methodCall:arg1\n"
	    "                 key2:arg2\n"
	    "             keyword3:arg3\n"
	    "                error:arg4];\n"
	    "}\n"
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "}\n"
	    "#endif";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C WITHOUT Align Method Colon for Method Call
//-------------------------------------------------------------------------

TEST(ObjCSansAlignMethodColonCall, DefaultAlignment)
{
	// Test default alignment.
	char text[] =
	    "\n"
	    "-(void)Foo\n"
	    "{\n"
	    "    [myObj methodCall:arg1\n"
	    "           key2:arg2\n"
	    "           keyword3:arg3\n"
	    "           error:arg4];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, AlignToLongest)
{
	// Test default alignment with a long arg.
	char text[] =
	    "\n"
	    "-(void)Foo\n"
	    "{\n"
	    "    [myObj short:arg1\n"
	    "           longKeyword:arg2\n"
	    "           evenLongerKeyword:arg3\n"
	    "           error:arg4];\n"
	    "}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, NoColonOnLine1)
{
	// Test default alignment with no colon on line1.
	// Should align on longest colon.
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row\n"
	    "{\n"
	    "    [[NSNotificationCenter default Center]\n"
	    "     object:self\n"
	    "     postNotificationName:myNotification\n"
	    "     userinfo:nil];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, NoKeywordOnLine1)
{
	// Test default alignment with no keyword on line1.
	// Should align on the object.
	char text[] =
	    "\n"
	    "void foo()\n"
	    "{\n"
	    "    NSArray*  eqParts = [equation\n"
	    "                         componentsSeparatedByCharactersInSet:\n"
	    "                         [NSCharacterSet whitespaceCharacterSet]];\n"
	    "    Employee* joeBlow = [[Employee alloc]\n"
	    "                         firstName:@\"Joe\"\n"
	    "                         lastname:@\"Blow\"\n"
	    "                         birthDate:\n"
	    "                         ssn:@\"555-12-1212\"];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, MethodAssignment)
{
	// Test default alignment in an assignment.
	char text[] =
	    "\n-(void) Foo\n"
	    "{\n"
	    "    NSDateComponents* components = [calendar components:(NSYearCalendarUnit)\n"
	    "                                             fromDate:today];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, ColonAtEnd1)
{
	// The default alignment with colon at end of line .
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData :\n"
	    "                           nSMutableDataBytes\n"
	    "                           readDataOfLength : nbytes];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, ColonAtEnd2)
{
	// The colon is at end of line with following object.
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [(NSMutableData *)data appendData :\n"
	    "                           [handle readDataOfLength : nbytes]];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, ColonAtEnd3)
{
	// The colon is at end of line with following object.
	char text[] =
	    "\n"
	    "void Foo()\n"
	    "{\n"
	    "    nextEvent = [[self window] nextEventMatchingMask:\n"
	    "                               NSLeftMouseUpMask | NSLeftMouseDraggedMask];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, RunInBraces)
{
	// Align with run-in braces.
	char text[] =
	    "\n"
	    "NSString* getText(NSString* filePath)\n"
	    "{   NSString* textIn = [NSString contentsOfFile: filePath\n"
	    "                                 encoding: NSASCIIStringEncoding\n"
	    "                                 error: NULL];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, RunInBracesTabs1)
{
	// Align with run-in braces and tabbed indents.
	char text[] =
	    "\n"
	    "NSString* getText(NSString* filePath)\n"
	    "{	NSString* textIn = [NSString contentsOfFile: filePath\n"
	    "	                             encoding: NSASCIIStringEncoding\n"
	    "	                             error: NULL];\n"
	    "}";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, RunInBracesTabs2)
{
	// Align with run-in braces and tabbed indents with embedded tabs.
	char text[] =
	    "\n"
	    "NSString* getText(NSString* filePath)\n"
	    "{	NSString* textIn =	[NSString	contentsOfFile: filePath\n"
	    "	                                encoding: NSASCIIStringEncoding\n"
	    "	                                error: NULL];\n"
	    "}";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, InStatementValue)
{
	// Align with parens in a value computation.
	char text[] =
	    "\n"
	    "-(void) Foo\n"
	    "{\n"
	    "    NSDateComponents* components =\n"
	    "        [calendar components:(NSYearCalendarUnit |\n"
	    "                              NSMonthCalendarUnit |\n"
	    "                              NSDayCalendarUnit)\n"
	    "                  fromDate:today];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, ExternC)
{
	// Align with default in an 'extern c'.
	char text[] =
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "extern \"C\" {\n"
	    "#endif\n"
	    "\n"
	    "-(void)Foo\n"
	    "{\n"
	    "    [myObj methodCall:arg1\n"
	    "           key2:arg2\n"
	    "           keyword3:arg3\n"
	    "           error:arg4];\n"
	    "}\n"
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "}\n"
	    "#endif";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCSansAlignMethodColonCall, Misc)
{
	// Align with default in a non-standard call call.
	// The "timeout" should actually be aligned with the "sendPacket".
	// But for now, this alignment will be used.
	// The method that computes alignment is getObjCFollowingKeyword in ASBeautifier.
	// Most programmers will probably use align-method-colon anyway.
	char text[] =
	    "\n"
	    "- (void) dismiss\n"
	    "{\n"
	    "    [(OutPort*)[connection sendPort] sendPacket: packet\n"
	    "                           timeout: [connection requestTimeout]];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//-------------------------------------------------------------------------
// AStyle Objective-C Other Tests
//-------------------------------------------------------------------------

TEST(ObjCOther, 1TBSAddBraces)
{
	// test 1tbs style option with added braces
	char textIn[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo)\n"
	    "        bar();\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size {\n"
	    "    if (isFoo)\n"
	    "        bar();\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@implementation Foo\n"
	    "\n"
	    "- (void) foo\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "- (void) foo : (int) icon\n"
	    "    ofSize : (int) size\n"
	    "{\n"
	    "    if (isFoo) {\n"
	    "        bar();\n"
	    "    }\n"
	    "}\n"
	    "\n"
	    "@end\n";
	char options[] = "style=1tbs";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, GoogleWithAccessModifiers)
{
	// test google style option with access modifiers
	char text[] =
	    "\n@interface Foo : NSObject {\n"
	    "  @public\n"
	    "    bool var1;\n"
	    "  @protected\n"
	    "    bool var2;\n"
	    "  @private\n"
	    "    bool var3;\n"
	    "}\n"
	    "@end\n";
	char options[] = "style=google";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, GoogleWithMultilineInterface)
{
	// test google style option with a multi-line interface
	char text[] =
	    "\n@interface Foo\n"
	    "    : NSObject {\n"
	    "    bool var1;\n"
	    "    bool var2;\n"
	    "}\n"
	    "@end\n";
	char options[] = "style=google";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, HeaderData)
{
	// test a header with Objective-C statements
	char text[] =
	    "\n#include <Foundation/Foundation.h>\n"
	    "\n"
	    "@class FooClass;\n"
	    "\n"
	    "@interface Foo : NSObject\n"
	    "{\n"
	    "    NSString* var1;\n"
	    "    NSString* var2;\n"
	    "}\n"
	    "@property(retain)NSString* var3;\n"
	    "\n"
	    "-(void)method1;\n"
	    "\n"
	    "-(void)methodWithArg1:(NSString*)param1;\n"
	    "\n"
	    "-(void)writeData:(NSData *)data\n"
	    "    atOffset:(NSNumber *)offset;\n"
	    "\n"
	    "-(void)method2;\n"
	    "\n"
	    "@end";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, SpacesBeforeDefinition)
{
	// test for spaces before the definition start
	// data will break on colons if not recognized
	char textIn[] =
	    "\n"
	    "       - (BOOL)tableView:(NSTableView *)tableView\n"
	    "       acceptDrop:(id <NSDraggingInfo>)info\n"
	    "              row:(int)row\n"
	    "{ }";
	char text[] =
	    "\n"
	    "- (BOOL)tableView:(NSTableView *)tableView\n"
	    "       acceptDrop:(id <NSDraggingInfo>)info\n"
	    "              row:(int)row\n"
	    "{ }";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, CStyleSubtractBeginsLine)
{
	// a c-style subtract that begins a line
	// cannot be mistaken for an objective-c method.
	char text[] =
	    "\n"
	    "void Foo()\n"
	    "{\n"
	    "    m_Control->SetMarginMask(C_FOLDING_MARGIN,\n"
	    "                             m_Control->GetMarginMask(C_FOLDING_MARGIN)\n"
	    "                             | (  wxSCI_MASK_FOLDERS\n"
	    "                                  - (  (1 << wxSCI_MARKNUM_CHANGEUNSAVED)\n"
	    "                                       | (1 << wxSCI_MARKNUM_CHANGESAVED))) );\n"
	    "}";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, InterfaceContinuation1)
{
	// test an Objective-C header with continuation lines
	// no brace
	char text[] =
	    "\n@interface Foo1 :\n"
	    "    NSObject\n"
	    "@end\n"
	    "\n"
	    "@interface Foo2\n"
	    "    : NSObject\n"
	    "@end\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, InterfaceContinuation2)
{
	// test google style option with a multi-line interface
	// attached brace
	char text[] =
	    "\n@interface Foo1 :\n"
	    "    NSObject {\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@interface Foo2\n"
	    "    : NSObject {\n"
	    "}\n"
	    "@end\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, InterfaceContinuation3)
{
	// test google style option with a multi-line interface
	// broken brace
	char text[] =
	    "\n@interface Foo1 :\n"
	    "    NSObject\n"
	    "{\n"
	    "}\n"
	    "@end\n"
	    "\n"
	    "@interface Foo2\n"
	    "    : NSObject\n"
	    "{\n"
	    "}\n"
	    "@end\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, InterfaceNoBraces)
{
	// test interface with no braces
	char text[] =
	    "\n"
	    "@interface SettingsTableViewController () <iTunesFilesSelectionDelegate>\n"
	    "@property (weak, nonatomic) IBOutlet UITableViewCell *dailyLimitCell;\n"
	    "@property (weak, nonatomic) IBOutlet UITableViewCell *sendFeedbackCell;\n"
	    "@end\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, MethodCallIndent)
{
	// test indent of method call containing a colon
	char text[] =
	    "\n- (void) Foo\n"
	    "{\n"
	    "    NSString* homeDirectory = [NSString stringWithUTF8String: homeDirectoryChar];\n"
	    "    NSString* projectPath = [NSString stringWithFormat: @\"%@/%@/%@\",\n"
	    "                                      homeDirectory, @\"Projects\", subPath];\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, NSExceptionMacros)
{
	// test indent of NSException macros NS_DURING and NS_HANDLER
	// tabs are used to check the continuation line indent
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "	NS_DURING\n"
	    "	{\n"
	    "		[[NSWorkspace sharedWorkspace] openFile: path\n"
	    "		                               withApplication: [node name]];\n"
	    "	}\n"
	    "	NS_HANDLER\n"
	    "	{\n"
	    "		NSRunAlertPanel(NSLocalizedString(@\"error\", @\"\"),\n"
	    "		                [NSString stringWithFormat: @\"%@ %@!\"]);\n"
	    "	}\n"
	    "	NS_ENDHANDLER\n"
	    "}";
	char options[] = "indent=tab";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, OtherColonIndent)
{
	// test indent of other troublesome objects containing a colon
	char text[] =
	    "\n- (void) Foo\n"
	    "{\n"
	    "    if (pathCompareSel == NULL) {\n"
	    "        pathCompareSel = @selector(compare:);\n"
	    "    }\n"
	    "    if (initialized == NO) {\n"
	    "        cutTitleSel = @selector(cutTitle:toFitWidth:);\n"
	    "        cutTitle = (cutIMP)[self instanceMethodForSelector: cutTitleSel];\n"
	    "    }\n"
	    "    return (([paths count] > 0) ? [paths makeImmutableCopyOnFail: NO] : nil);\n"
	    "}";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, MethodCallHeader)
{
	// test method call containing a header (default)
	// the header should not be recognized
	// break-blocks tests ASFormatter, indentation tests ASBeautifier
	char text[] =
	    "\nvoid Foo()\n"
	    "{\n"
	    "    [[NSNotificationCenter default Center]\n"
	    "     postNotificationName:myNotification\n"
	    "     object:self\n"
	    "     userinfo:nil];\n"
	    "}";
	char options[] = "break-blocks";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, AutoreleasepoolBreak)
{
	// Precommand header autoreleasepoolwith broken braces.
	char text[] =
	    "\nvirtual void foo()\n"
	    "{\n"
	    "    @autoreleasepool\n"
	    "    {\n"
	    "        bar()\n"
	    "    }\n"
	    "}\n";
	char options[] = "style=break";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, AutoreleasepoolAttach)
{
	// Precommand header autoreleasepoolwith attached braces.
	char textIn[] =
	    "\nvirtual void foo()\n"
	    "{\n"
	    "    @autoreleasepool\n"
	    "    {\n"
	    "        bar()\n"
	    "    }\n"
	    "}\n";
	char text[] =
	    "\nvirtual void foo() {\n"
	    "    @autoreleasepool {\n"
	    "        bar()\n"
	    "    }\n"
	    "}\n";
	char options[] = "style=attach";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, AutoreleasepoolKandR)
{
	// Precommand header autoreleasepoolwith K&R braces.
	char textIn[] =
	    "\nvirtual void foo()\n"
	    "{\n"
	    "    @autoreleasepool\n"
	    "    {\n"
	    "        bar()\n"
	    "    }\n"
	    "}\n";
	char text[] =
	    "\nvirtual void foo()\n"
	    "{\n"
	    "    @autoreleasepool {\n"
	    "        bar()\n"
	    "    }\n"
	    "}\n";
	char options[] = "style=k&r";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, IndentClasses)
{
	// test google style option with indent classes
	// classes should NOT be indented
	char text[] =
	    "\n@interface Foo : NSObject {\n"
	    "@public\n"
	    "    bool var1;\n"
	    "@protected\n"
	    "    bool var2;\n"
	    "@private\n"
	    "    bool var3;\n"
	    "}\n"
	    "@end\n";
	char options[] = "indent-classes";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, IndentModifiers)
{
	// test google style option with indent classes
	char text[] =
	    "\n@interface Foo : NSObject {\n"
	    "  @public\n"
	    "    bool var1;\n"
	    "  @protected\n"
	    "    bool var2;\n"
	    "  @private\n"
	    "    bool var3;\n"
	    "}\n"
	    "@end\n";
	char options[] = "indent-modifiers";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, ContinuationIndent1)
{
	// test method containing a long indent
	// the continuation indent must be increased for correct alignment
	char text[] =
	    "\n-(void) Foo\n"
	    "{\n"
	    "    NSDateComponents* components = [calendar components:(NSYearCalendarUnit |\n"
	    "                                                         NSMonthCalendarUnit |\n"
	    "                                                         NSDayCalendarUnit)\n"
	    "                                             fromDate:today];\n"
	    "}";
	char options[] = "max-continuation-indent=60";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, ContinuationIndent2)
{
	// The first function has no ending ';' and the ending '}' is followed by a comment.
	// The next objective statement should NOT be flagged as a 'isNonInStatementArray'.
	// If it is the indentation will be wrong.
	char text[] =
	    "\nvoid Foo2()\n"
	    "{\n"
	    "    dict = [[NSDictionary alloc] initWithObjects:@\"foo\", @\"bar\", @\"baz\"]\n"
	    "}	// p 277\n"
	    "\n"
	    "-(void) Foo\n"
	    "{\n"
	    "    NSDateComponents* components = [calendar components:(NSYearCalendarUnit |\n"
	    "                                                         NSDayCalendarUnit)\n"
	    "                                             fromDate:today];\n"
	    "}";
	char options[] = "max-continuation-indent=60";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, AlignPointer)
{
	// Test align-pointer=name option.
	// The (*) should not change.
	char textIn[] =
	    "\nvoid foo()\n"
	    "{\n"
	    "    [icons sortUsingFunction: (int (*)(id, id, void*))compareWithExtType\n"
	    "           context: (void*)NULL];\n"
	    "}";
	char text[] =
	    "\nvoid foo()\n"
	    "{\n"
	    "    [icons sortUsingFunction: (int (*)(id, id, void *))compareWithExtType\n"
	    "           context: (void *)NULL];\n"
	    "}";
	char options[] = "align-pointer=name";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadInterfaceColon1)
{
	// test padding a @interface statement.
	char textIn[] =
	    "\n@interface Foo:NSObject\n"
	    "{\n"
	    "}\n"
	    "\n"
	    "@interface Foo:NSObject\n"
	    "\n"
	    "-(void)method1;\n";
	char text[] =
	    "\n@interface Foo : NSObject\n"
	    "{\n"
	    "}\n"
	    "\n"
	    "@interface Foo : NSObject\n"
	    "\n"
	    "-(void)method1;\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadInterfaceColon2)
{
	// test limits in padding a @interface statement.
	char textIn[] =
	    "\n@interface Foo:\n"
	    "NSObject\n"
	    "@end\n"
	    "\n"
	    "@interface Foo\n"
	    ":NSObject\n"
	    "@end\n";
	char text[] =
	    "\n@interface Foo :\n"
	    "    NSObject\n"
	    "@end\n"
	    "\n"
	    "@interface Foo\n"
	    "    : NSObject\n"
	    "@end\n";
	char options[] = "";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	ASSERT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadOperator1)
{
	// Test methods with pad-oper option.
	// Statements should not change.
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row\n"
	    "{\n"
	    "    [[NSNotificationCenter default Center]\n"
	    "     postNotificationName:myNotification\n"
	    "     object:self\n"
	    "     userinfo:nil];\n"
	    "}";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadOperator2)
{
	// Test selector with pad-oper option.
	// Statement should not change.
	char text[] =
	    "\n"
	    "-(void)foo1:(int)row\n"
	    "{\n"
	    "    cutTitleSel = @selector(cutTitle:toFitWidth:);\n"
	    "}";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadOperator3)
{
	// Test 'or' with pad-oper option.
	// The 'or' at the end should not be padded.
	char text[] =
	    "\nvoid foo()\n"
	    "{\n"
	    "    leafpos = [[LeafPosition alloc] initWithPosX:x posY:y relativeToPoint:or];\n"
	    "}";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadOperator4)
{
	// Test pad-oper question.
	// Don't pad '?:' within the '[]'.
	char textIn[] =
	    "\nvoid foo()\n"
	    "{\n"
	    "    fsfilter = fsattribute?[info objectForKey:@\"fsfilter\"]:nil;\n"
	    "    FSNode *pnode = (i == 0)?nil:[components objectAtIndex:(i)];\n"
	    "}";
	char text[] =
	    "\nvoid foo()\n"
	    "{\n"
	    "    fsfilter = fsattribute ? [info objectForKey:@\"fsfilter\"] : nil;\n"
	    "    FSNode *pnode = (i == 0) ? nil : [components objectAtIndex:(i)];\n"
	    "}";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadOperator5)
{
	// Test pad-oper question.
	// Test the questionMarkStack with multiple '(' and '['.
	char textIn[] =
	    "\nvoid foo()\n"
	    "{\n"
	    "    caseSensitive = Attribute(\"CaseSensitive\")?atol(Attribute(\"CaseSensitive\")) != 0:false;\n"
	    "    tabPoints[5].y = HasFlag?(tabPoints[4].y):tabPoints[4].y;\n"
	    "}";
	char text[] =
	    "\nvoid foo()\n"
	    "{\n"
	    "    caseSensitive = Attribute(\"CaseSensitive\") ? atol(Attribute(\"CaseSensitive\")) != 0 : false;\n"
	    "    tabPoints[5].y = HasFlag ? (tabPoints[4].y) : tabPoints[4].y;\n"
	    "}";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, PadOperator6)
{
	// Test selector with pad-oper option.
	// -1 should not be padded.
	char text[] =
	    "\n"
	    "void Foo()\n"
	    "{\n"
	    "    port[1] = [portArray objectAtIndex:-1];\n"
	    "}";
	char options[] = "pad-oper";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, SansReturnValue)
{
	// Test method without a return type (assumes an Id).
	char textIn[] =
	    "\n"
	    "@interface A\n"
	    "-aLongMethodTitle:(NSInteger)parameter\n"
	    "anotherParam:(NSInteger)lmao\n"
	    "yetAnotherParam:(NSObject *)obj;\n"
	    "@end\n"
	    "\n"
	    "-aLongMethodTitle:(NSInteger)parameter\n"
	    "anotherParam:(NSInteger)lmao\n"
	    "yetAnotherParam:(NSObject *)obj;\n";
	char text[] =
	    "\n"
	    "@interface A\n"
	    "-aLongMethodTitle:(NSInteger)parameter\n"
	    "       anotherParam:(NSInteger)lmao\n"
	    "    yetAnotherParam:(NSObject *)obj;\n"
	    "@end\n"
	    "\n"
	    "-aLongMethodTitle:(NSInteger)parameter\n"
	    "       anotherParam:(NSInteger)lmao\n"
	    "    yetAnotherParam:(NSObject *)obj;\n";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(textIn, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, ExternCInsideAnInterface)
{
	// Test method with "extern C" inside an interface.
	char text[] =
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "extern \"C\" {\n"
	    "#endif\n"
	    "\n"
	    "@interface A (X)\n"
	    "- (void)method: (NSInteger)parameter;\n"
	    "@end\n"
	    "\n"
	    "#if defined(__cplusplus)\n"
	    "}\n"
	    "#endif\n";
	char options[] = "align-method-colon";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

TEST(ObjCOther, MethodPrefixIncrement)
{
	// '++' and '--' are not a method prefix.
	char text[] =
	    "\n"
	    "void Foo()\n"
	    "{\n"
	    "    for (x = 0;\n"
	    "            x < end;\n"
	    "            ++x)\n"
	    "        manager(x);\n"
	    "}\n";
	char options[] = "";
	char* textOut = AStyleMain(text, options, errorHandler, memoryAlloc);
	EXPECT_STREQ(text, textOut);
	delete[] textOut;
}

//----------------------------------------------------------------------------

}  // namespace
