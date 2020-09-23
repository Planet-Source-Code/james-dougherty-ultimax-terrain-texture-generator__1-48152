UltimaX Terrain Texture Generator
©2003 Ariel Productions

The reason I made this is because my CLOD terrain engine was taking about 8 second
to create all of the data. After I used my profiler, it showed that most of the 
time it was creating the maps. So I created this to pre-create the maps. Works 
like a charm for my engine since the main maps needed is the height map and rough 
map. The terrain engine takes about 2 seconds to load now, so this was a major
improvement. Hope it helps you as much as it did me. 

~ NOTE ~
The lower altitude map and higher altitude map must be the same size as the height
map. I didn't add detail map support since usually they need scaled by the 
terrain engine.

The 'UltimaX Terrain Texture Generator' will create the following maps:
HeightMap_C.bmp         (For debug purposes)
RoughMap_C.(bmp or tga) (Used for CLOD terrain engines)
ShadeMap_C.(bmp or tga)
BlendMap_C.(bmp or tga)
ShadedBlendMap_C.(bmp or tga)

T O   U S E
-----------
Rename UltimaXTTG.RENAMEdll to UltimaXTTG.dll or compile another one
Place it in the folder with the visual basic project
Open the program (UltimaXTTG.exe)
Load a height map, lower altitude map, and a higher altitude map
Click 'Render Maps'
Wait a few seconds :)

C O M M O N   E R R O R
-----------------------
If you run it from the IDE and get a 'DLL Not Found' error, close the whole
Visual Basic project then reopen it. The reason it's not finding it is because
the workspace file is not created. When you close Visual Basic, it'll create 
the .vbw file. Then when you reopen it you wont get the error.

--AND--

Make sure the the UltimaXTTG.dll is in the same folder :) 