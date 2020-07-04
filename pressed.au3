#include <Misc.au3>
#include <MsgBoxConstants.au3>
#include <AutoItConstants.au3>

Local $hDLL = DllOpen("user32.dll")

While 1
;~     If _IsPressed("10", $hDLL) Then
;~         ConsoleWrite("_IsPressed - Shift Key was pressed." & @CRLF)
;~         ; Wait until key is released.
;~         While _IsPressed("10", $hDLL)
;~             Sleep(250)
;~         WEnd
;~         ConsoleWrite("_IsPressed - Shift Key was released." & @CRLF)

;~     Else
	If _IsPressed("1B", $hDLL) Then
        ;MsgBox($MB_SYSTEMMODAL, "_IsPressed", "The Esc Key was pressed, therefore we will close the application.")
        ExitLoop
    EndIf

;~ 	If ( _IsPressed("11", $hDLL) ) Then
;~ 		If ( _IsPressed("12", $hDLL) ) Then
;~ 			MsgBox($MB_SYSTEMMODAL, "_IsPressed", "Key1")
;~ 		EndIf
;~ 	EndIf

	If ( _IsPressed("10", $hDLL) And _IsPressed("11", $hDLL) And _IsPressed("12", $hDLL) And _IsPressed("31", $hDLL) ) Then
		ConsoleWrite("_IsPressed - Key1" & @CRLF)
		Run("sound.exe 01")
;~ 		SoundPlay ( "applause2.mp3" , $SOUND_NOWAIT )
	EndIf
	If ( _IsPressed("10", $hDLL) And _IsPressed("11", $hDLL) And _IsPressed("12", $hDLL) And _IsPressed("32", $hDLL) ) Then
		ConsoleWrite("_IsPressed - Key2" & @CRLF)
		Run("sound.exe 02")
;~ 		SoundPlay ( "426233__robinhood76__07075-small-girl-shouting-yes-yes-yes.wav" , $SOUND_NOWAIT )
	EndIf
	If ( _IsPressed("10", $hDLL) And _IsPressed("11", $hDLL) And _IsPressed("12", $hDLL) And _IsPressed("33", $hDLL) ) Then
		ConsoleWrite("_IsPressed - Key3" & @CRLF)
		Run("sound.exe 03")
	EndIf
	If ( _IsPressed("10", $hDLL) And _IsPressed("11", $hDLL) And _IsPressed("12", $hDLL) And _IsPressed("34", $hDLL) ) Then
		ConsoleWrite("_IsPressed - Key4" & @CRLF)
		Run("sound.exe 04")
	EndIf
    Sleep(50)
WEnd

DllClose($hDLL)