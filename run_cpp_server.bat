@echo off
title KNOWBRIDGE AI - Native C++ Web Server
echo ========================================================
echo   KNOWBRIDGE AI - Native C++ Web Server
echo   Stack: C++ + HTML5 + CSS3 + JavaScript
echo   Team: TECHY'VENGERS | Leader: Kamal Lochan Mishra
echo ========================================================
echo.

if not exist "%~dp0server.exe" (
    echo Compiling server.cpp with g++...
    g++ -O2 "%~dp0server.cpp" -o "%~dp0server.exe" -lws2_32 -std=c++11
    if %ERRORLEVEL% NEQ 0 (
        echo Compilation failed. Please ensure MinGW g++ is installed.
        pause
        exit /b 1
    )
)

echo Starting C++ server on http://localhost:8080 ...
start "" "http://localhost:8080"
"%~dp0server.exe"
pause
