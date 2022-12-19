project:
	gcc -std=c99 -Wall -Wpedantic -o dist/project.exe project.c
	./dist/project.exe
installemsdk: 
	cd .. && git clone https://github.com/emscripten-core/emsdk.git
	cd ../emsdk && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc Safe.c -s WASM=1 -o pge.html
	npm i http-server -g
