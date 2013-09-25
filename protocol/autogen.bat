@echo off
rem 查找文件
for /f "delims=" %%i in ('dir /b ".\*.proto"') do echo %%i
for /f "delims=" %%i in ('dir /b/a "*.proto"') do .\tools\protoc.exe -I=. --cpp_out=..\src\common\protocol %%i
for /f "delims=" %%i in ('dir /b/a "*.proto"') do .\tools\ProtoGen_Net\protogen.exe -i:%%i -o:..\src\RobotWatchman\RobotWatchman\protocol\%%~ni.cs
pause