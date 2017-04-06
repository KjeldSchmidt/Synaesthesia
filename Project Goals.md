Synaesthesia
============

Project Goals
-------------

Synaesthesia is a Sound Editor. It is _not_ a digital audio work station. Think Audacity, not FL Studio.

Synaesthesia is named such because it incorporates interface ideas from graphics applications such as photoshop, especially the system of adjustmend layers and masks.

Synaesthesia shall allow fine-grained control over non-destructive edits and adjustments. That means that most edits shall be reversible without unwinding a history (and losing later edits). In this way, it will be closer to effects in Premiere Pro than Audition. All effects and asjusments should also be fully fadeable (dynamic mix of wet and dry sound) and aplied to arbitrary subsections of a clip (without splitting the clip). Since no changes are ever truly 'permanent', everything should constantly save automatically, in the ideal case (like Sublime Text).

The very first version shall support the following:

Opening multiple .wav-Files, adjusting inidivdual volume, adjusting start time, saving a new .wav file.

Followed by:

Splitting clips, the 'amplify'-effect applied to clip subsections rather than all clips.

Followed by: Clip-Groups, which can be treated as a stand-in for individual clips (i.e., adjustments can be applied to this group directly, affecting all clips beneath them)


Larger goals:

Effects can be applied to master, groups oder individual clips. All effects can be applied anywhere and faded arbitrarily.  
Effects wanted include, very roughly in order of usefulness:
Amplification  
Single Band Compression  
Noise Reduction  
Equalizer  

Of course, many many more are desireable in some way or other.


Multiple common files formats would be useful (wav, flac, mp3, ogg..?)  

Hotkey based editing is king. Cutting a podcast should very rarely involve the mouse.

Things to keep in mind for future extensibility:
Sensible defaults are good, but keep them open to the user. Try to implement many, if not most, settings as text files that can be shared directly. This inlcudes keymaps, color shemes and preferences.


Steps:
x Split MainWindow into a Menu Bar on top, an assets/project bar on the right and a large main component 
x StyleSheet
- Import and play a wav
- Place a wav in the main component
- Show approximate waveform
- Place multiple wavs, show porportional length
- Enable changing a files starting position
- Implement zooming
- Save track mixdown
- Implement splitting clips