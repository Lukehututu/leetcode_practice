@echo off
setlocal

:: 获取当前日期并格式化为 YYYY-MM-DD
for /f "tokens=1-3 delims=/- " %%a in ('date /t') do (
    set month=%%a
    set day=%%b
    set year=%%c
)
set currentDate=%year%-%month%-%day%

:: 执行 Git 命令
git add .
git commit -m "%currentDate%"
git push

endlocal
pause
