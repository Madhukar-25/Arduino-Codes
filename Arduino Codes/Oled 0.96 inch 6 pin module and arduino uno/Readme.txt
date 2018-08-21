Creating array:
1) See that before creating the array, the max size must be 128x64.
2) The image must be converted to bmp format before creating the array. You can use the following link :
     "https://image.online-convert.com/convert-to-bmp"   (see that change the size to 128x64 and select "Monochrome"
3) You can use LCD assistant to get the converted array.
4) See that the settings must be 
	byte orientaton: Vertical
	Size endiannes : Little
	Pixels/byte    : 8
5) Steps to use lcd assistant:
	a) Goto to file->Load image
	b) Adjust the settings as given above
	c) The size of the image will appear in size block
	d) Again goto file-> Save output and select a destination. (Save the file type as .txt)