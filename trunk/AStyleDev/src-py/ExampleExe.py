#! /usr/bin/python

# ExampleExe.py
# This program calls the Artistic Style executable to format the astyle source files.
# The Artistic Style executable must be in the same directory as this script.
# It will work with either Python version 2 or 3 (unicode).

# to disable the print statement and use the print() function (version 3 format)
from __future__ import print_function

import os
import subprocess
import sys
from ctypes import *

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function."""
	options = "-A2tOP"
	files = [ "../test-c/ASBeautifier.cpp",
	          "../test-c/ASFormatter.cpp" ,
	          "../test-c/astyle.h" ]
	exe = initialize()
	print("ExampleExe Python")
	print("Python Version " + str(sys.version_info[0]) +
		  "." + str(sys.version_info[1]))
	# print information if the script is running in an editor
	# if run from a console the sys.stdin will be a TTY
	if os.name == "nt" and not os.isatty(sys.stdin.fileno()):
		print("AStyle messages will not appear in an editor window.")
		print("Run in a console program to see the messages.")
	display_astyle_version(exe)
	# process the input files
	for file_path in files:
		format_astyle_source(exe, file_path, options)

# -----------------------------------------------------------------------------

def display_astyle_version(exe):
	"""Display the version number from the AStyle executable.
	   This will not display when run from a Windows editor.
	"""
	astyle = [exe, "--version"]
	retval = subprocess.call(astyle)
	if retval:
		print("Bad astyle return: " + str(retval))
		sys.exit(1)

# -----------------------------------------------------------------------------

def format_astyle_source(exe, file_path, options):
	"""Format file_in by calling the AStyle executable.
	   The unicode variables in Version 3 will be changed to
	   byte variables by the operating system.
	   The astyle messages will not display when run from a
	   Windows editor.
	"""
	astyle = [exe, options, file_path]
	retval = subprocess.call(astyle)
	if retval:
		print("Bad astyle return: " + str(retval))
		sys.exit(1)

# -----------------------------------------------------------------------------

def initialize():
	"""Set the file path and executable name.
	   Verify the executable is available.
	   Return the executable name.
	"""
	# change directory to the path where this script is located
	pydir = sys.path[0]
	os.chdir(pydir)
	# return the executable name for the platform
	if os.name == "nt":
		exe = "AStyle.exe"
	else:
		exe = "astyle"
	# verify the astyle executable is available
	if not os.path.isfile(exe):
		print("Cannot find " +  exe)
		sys.exit(1)
	return exe

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	sys.exit()
