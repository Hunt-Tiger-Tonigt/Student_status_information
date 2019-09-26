::[Bat To Exe Converter]
::
::YAwzoRdxOk+EWAnk
::fBw5plQjdG8=
::YAwzuBVtJxjWCl3EqQJgSA==
::ZR4luwNxJguZRRnk
::Yhs/ulQjdF+5
::cxAkpRVqdFKZSDk=
::cBs/ulQjdF+5
::ZR41oxFsdFKZSDk=
::eBoioBt6dFKZSDk=
::cRo6pxp7LAbNWATEpCI=
::egkzugNsPRvcWATEpCI=
::dAsiuh18IRvcCxnZtBJQ
::cRYluBh/LU+EWAnk
::YxY4rhs+aU+JeA==
::cxY6rQJ7JhzQF1fEqQJQ
::ZQ05rAF9IBncCkqN+0xwdVs0
::ZQ05rAF9IAHYFVzEqQJQ
::eg0/rx1wNQPfEVWB+kM9LVsJDGQ=
::fBEirQZwNQPfEVWB+kM9LVsJDGQ=
::cRolqwZ3JBvQF1fEqQJQ
::dhA7uBVwLU+EWDk=
::YQ03rBFzNR3SWATElA==
::dhAmsQZ3MwfNWATElA==
::ZQ0/vhVqMQ3MEVWAtB9wSA==
::Zg8zqx1/OA3MEVWAtB9wSA==
::dhA7pRFwIByZRRnk
::YB416Ek+ZG8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off
(echo aCode = "UTF-8"
echo bCode = "GB2312"
echo Set objArgs = WScript.Arguments
echo.
echo FileUrlSrc = objArgs^(0^)
echo FileUrlDst = objArgs^(1^)
echo Call WriteToFile^(FileUrlDst, ReadFile^(FileUrlSrc, aCode^), bCode^)
echo.
echo Function ReadFile^(FileUrlSrc, CharSet^)
echo     Dim Str
echo     Set stm = CreateObject^("Adodb.Stream"^)
echo     stm.Type = 2
echo     stm.mode = 3
echo     stm.charset = CharSet
echo     stm.Open
echo     stm.loadfromfile FileUrlSrc
echo     Str = stm.readtext
echo     stm.Close
echo     Set stm = Nothing
echo     ReadFile = Str
echo End Function
echo.
echo Function WriteToFile ^(FileUrlDst, Str, CharSet^)
echo     Set stm = CreateObject^("Adodb.Stream"^)
echo     stm.Type = 2
echo     stm.mode = 3
echo     stm.charset = CharSet
echo     stm.Open
echo     stm.WriteText Str
echo     stm.SaveToFile FileUrlDst, 2
echo     stm.flush
echo     stm.Close
echo     Set stm = Nothing
echo End Function)>U82ANI.vbs
for /r %%a in (*.txt) do (
    U82ANI.vbs "%%~a" "%%~a.ansi"
    move /y "%%~a.ansi" "%%~a">nul
)
pause