@echo off
Copy "%CD%/../header.cpp" %1 >nul
code %1 >nul