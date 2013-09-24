@echo off
rem 查找文件
for /f "delims=" %%i in ('dir /b ".\*.proto"') do echo %%i
for /f "delims=" %%i in ('dir /b/a "*.proto"') do protoc -I=. --cpp_out=.\cpp %%i
for /f "delims=" %%i in ('dir /b/a "*.proto"') do .\tools\ProtoGen_Net\protogen.exe -i:%%i -o:..\src\RobotWatchman\RobotWatchman\protocol\%%~ni.cs
pause