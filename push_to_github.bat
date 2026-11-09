@echo off
title Push KNOWBRIDGE AI to GitHub
echo ========================================================
echo   Pushing KNOWBRIDGE AI to GitHub
echo   Team: TECHY'VENGERS | Leader: Kamal Lochan Mishra
echo ========================================================
echo.

set "GIT_CMD=C:\Program Files\Microsoft Visual Studio\18\Insiders\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer\Git\cmd\git.exe"

if not exist "%GIT_CMD%" (
    set "GIT_CMD=git"
)

echo Adding modified files...
"%GIT_CMD%" add .

echo Creating commit...
"%GIT_CMD%" commit -m "feat(round-2): update C++ server, GitHub Pages deployment workflow, and submission report"

echo Pushing to GitHub (main branch)...
"%GIT_CMD%" push -u origin main

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================================
    echo   SUCCESS! Pushed to https://github.com/Kamal-Lochan-Mishra/knowbridge-ai
    echo   GitHub Actions will automatically deploy to GitHub Pages!
    echo ========================================================
) else (
    echo.
    echo ========================================================
    echo   NOTE: If prompted for GitHub login, please sign in.
    echo   Make sure you have created the repository 'knowbridge-ai'
    echo   on https://github.com/new
    echo ========================================================
)

echo.
pause
