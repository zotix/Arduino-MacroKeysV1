#include <Array.au3>
#include <File.au3>
#include <MsgBoxConstants.au3>
#include <AutoItConstants.au3>

Local $hDLL = DllOpen("user32.dll")

Local $nInput = UBound($CmdLine)

; Check Input
If $nInput <= 1 Then
	$sFile = File(@WorkingDir)

ElseIf $nInput == 2 Then
	$sFile = File($CmdLine[1])
Else
	MsgBox($MB_SYSTEMMODAL, "", "Error Input!" &UBound($CmdLine))
	Exit
EndIf

ConsoleWrite($sFile)
SoundPlay ( $sFile , $SOUND_WAIT )

Func File($sFolder)
    ; List all the files and folders in the desktop directory using the default parameters and return the full path.
    Local $aFileList = _FileListToArrayRec($sFolder, "*.wav;*.mp3;*.aiff;*.m4a", $FLTAR_FILES, $FLTAR_NORECUR, $FLTAR_NOSORT, $FLTAR_FULLPATH)
    If @error = 1 Then
        MsgBox($MB_SYSTEMMODAL, "", "Path was invalid.")
        Exit
    EndIf
    If @error = 4 Then
        MsgBox($MB_SYSTEMMODAL, "", "No file(s) were found.")
        Exit
    EndIf
    ; Display the results returned by _FileListToArray.
;~     _ArrayDisplay($aFileList, "$aFileList")

;~ 	MsgBox($MB_SYSTEMMODAL, "",Random(0,$aFileList[0],1))
;~ 	While 1
	Return($aFileList[Random(1,$aFileList[0],1)])
;~ 	WEnd
EndFunc   ;==>Example