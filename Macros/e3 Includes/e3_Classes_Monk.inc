|----------------------------------------------------------------------------|
| Monk Functions
|----------------------------------------------------------------------------|
Sub MNK_Setup
  /if (!${Defined[speedFocusSwapped]}) /declare speedFocusSwapped bool global FALSE
  /declare speedFocusSwapTimer timer outer
/return
|----------------------------------------------------------------------------|
Sub MNK_Background_Events
  /if (${Bool[${Me.ActiveDisc}]} && ${Me.ActiveDisc.Name.Equal[Speed Focus Discipline]}) {
    /if (!${speedFocusSwapTimer}) {
      /varset speedFocusSwapped true
      /swap SpeedFocus
      /varset speedFocusSwapTimer 30s
    }
  } else /if (${speedFocusSwapped}) {
    /swap main
    /varset speedFocusSwapped false
  }
/return
|----------------------------------------------------------------------------|
SUB MNK_MacroSettings
/if (${Debug}) /echo |- MNK_MacroSettings ==>
	/call WriteToIni "${advSettings_Ini},MNK Functions,MNK Function#1" "check_Burns" 1
	/call WriteToIni "${advSettings_Ini},MNK Functions,MNK Function#2" "check_Buffs" 1
/if (${Debug}) /echo <== MNK_MacroSettings -|
/RETURN
|----------------------------------------------------------------------------|
SUB MNK_CharacterSettings
/RETURN
|----------------------------------------------------------------------------|
Sub MNK_Aliases
/return