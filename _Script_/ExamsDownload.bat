@ECHO OFF
@REM Activate <DelayedExpansion> using <SETLOCAL> to use/expand the local variable !VAR! at run-time.
@REM If the local variable is VAR or %VAR%, then we can use !VAR! as its expansion at run-time. 
@REM For example, with !VAR!, we can realize string concartenation like:
@REM
@REM 	VAR=%VAR%!VAR!
@REM
@REM Be aware that something like VAR=%VAR%%VAR% won't work.
@REM <EnableDelayedExpansion> is helpful for SET in FOR loop. Without that, SET doesn't work in FOR.
@REM For example:
@REM 
@REM 	FOR ... %%G IN (...) DO (
@REM 		SET Var=%%G  <-- Var won't get value of %%G correctly, because of delay. So Var may be empty.
@REM 		ECHO %Var%   <-- Not work!
@REM	)
@REM
@REM but:
@REM
@REM	SETLOCAL EnableDelayedExpansion
@REM 	FOR ... %%G IN (...) DO (
@REM 		SET Var=%%G  <-- Var gets value of %%G correctly
@REM 		ECHO !Var!   <-- Work!
@REM	)
@REM
@SETLOCAL EnableDelayedExpansion
@SET URL='https://www.ais.mw.tum.de/lehre/grundlagen-und-vertiefungsfaecher/informationstechnik-ii/'
@SET "PREFIX=http://www.ais.mw.tum.de"
@SET COUNT=0
@SET FILE_NAME=''
@ECHO Webpage: %URL%
@ECHO Getting source code of the webpage...
@REM Using Windows PowerShell to download web content to local file 'tmp.txt'
@powershell -Command "(New-Object Net.WebClient).DownloadFile(%URL%, 'tmp.txt')"
@ECHO Done
@ECHO Searching for pdf-links on the webpage... 
@REM Search 'tmp.txt' for strings matching pattern ".*\.pdf" (that means: any strings containing pattern 
@REM *.pdf will be extracted) and redirect the them to extern file 'tmp2.txt'. Option -I means ignoring 
@REM sensitive case. The dot (.) in front of "pdf" is escaped with back-slash (\).
@FINDSTR /I ".*\.pdf" tmp.txt > tmp2.txt
@ECHO Done
@ECHO Start downloading files...
@REM Extract from 'tmp2.txt' the pdf-links, that are separated by double-quote (").
@REM 	FOR /F delims=" tokens=2 %%M IN (tmp2.txt) DO (..)
@REM Using the sign ^ to escape unusualy characters like =,"; and white-spaces.
@REM In the following code, we insert ^ after delims^=^" to escape the white-space.
@REM With tokens=2, we take the second substring separated by double-quote (").
@FOR /F delims^=^"^ tokens^=2 %%M IN (tmp2.txt) DO (
	@REM Use <EnableDelayedExpansion> and !Link! instead of %Link% for SET in FOR loop
	@REM Link is the full link of pdf file to download.
	@SET Link=%%M
	@REM Check if !Var! contains substring %PREFIX% 
	@ECHO !Var! | FINDSTR /C:%PREFIX% >nul
	@REM If errorlevel 1 (= error), then !Link! does not contain %PREFIX%.
	@IF errorlevel 1 (
		@REM Append %PREFIX% to head of !Link!
		@SET Link=%PREFIX%!Link!
	)
	@REM Append quotes (') to head and back of !Link! (file link) to make it string.
	@REM Otherwise, PowerShell won't download.
	@SET Link='!Link!'
	@REM The full pdf download link is determined in Link, %Link%, !Link!.
	@REM Now, extract the short file name from Var or %%M (that is the last substring in %%M).
	@REM Calculate the number of substrings in %%M, that are separated by slash (/).
	@REM The result is then stored in global variable COUNT.
	@CALL :CALC_NUMBER_OF_SUBSTRINGS %%M
	@REM Using !COUNT! instead of %COUNT% because of delay
	@REM Get the pdf file name (last substring in %%M).
	@REM The file name (last substring of %%M) is stored in FILE_NAME
	@CALL :GET_LAST_SUBSTRING %%M !COUNT!
	@REM Append quotes (') to head and back of !FULL_NAME! to make it string.
	@REM Otherwise, PowerShell won't download.
	@SET FILE_NAME='!FILE_NAME!'
	@REM Download the files
	@ECHO Downloading file !FILE_NAME!...
	@CALL :DOWNLOAD !Link! !FILE_NAME!
	@REM Reset %COUNT% to 0
	@SET COUNT=0
	@REM Give message
	@ECHO Done
)
@REM Erase temporary files.
@DEL /F tmp.txt tmp2.txt

@ECHO.All files have been downloaded. Finished!

@PAUSE

@GOTO :EOF


@REM This function downloads the pdf files using PowerShell function Net.Webclient.DownloadFile(String, String).
@REM The first input parameter (%1) is the full URL download link of file.
@REM The second input paramter (%2) is the file name to save on local mmachine.
:DOWNLOAD
	@powershell -Command "(New-Object Net.WebClient).DownloadFile(%1, %2)"
	@GOTO EOF 
	

@REM This function calculates the number of substrings separated by slash (/).
@REM For example, if the string is "/fileadmin/w00bdq/www/Lehre/IT/Informationstechnik_WS1011_Angabe.pdf",
@REM then the number of substrings is 6 and the last substring is "Informationstechnik_WS1011_Angabe.pdf".
@REM The input parameter %1 is the file path string.
@REM The result is stored in the global variable %COUNT%.
:CALC_NUMBER_OF_SUBSTRINGS
	@SET Str=%1
	:LOOPING
		@FOR /F "tokens=1* delims=/" %%A IN ("%Str%") DO (
			@SET /A COUNT+=1
			@REM %%B is the next of %%A
			@SET Str=%%B
			@GOTO LOOPING
		)
	@GOTO EOF

	
@REM This function provides the last of substrings that are separated by slash (/).
@REM The first input parameter (%1) is the whole string which the last substring is extracted from.
@REM The second input paramter (%2) is the index of the last substring in string %1.
:GET_LAST_SUBSTRING
	@FOR /F "tokens=%2 delims=/" %%A IN ("%1") DO (
		@SET FILE_NAME=%%A
	)

@REM End of file
:EOF
