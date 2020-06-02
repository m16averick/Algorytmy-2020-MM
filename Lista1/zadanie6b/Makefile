hello_world.exe: hello_world.obj
	link /DEBUG /OUT:hello_world.exe hello_world.obj

hello_world.obj: hello_world.cpp
	cl /std:c++17 /EHsc /c /Zi /W4 /WX /Zi /Fo:hello_world.obj hello_world.cpp
