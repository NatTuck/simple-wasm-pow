
OUTPUT := csha.js csha.wasm


$(OUTPUT): sha-256.cc sha-256.h wrap.cc
	emcc --bind -o csha.js -O3 -s WASM=1 *.cc
#		-s EXPORTED_FUNCTIONS='["_sha256"]' \
#		-s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
#		-s NO_EXIT_RUNTIME=1

clean:
	rm -f $(OUTPUT)
	rm -f ../csha.js ../csha.wasm

copy:
	cp $(OUTPUT) ../

.PHONY: clean copy

