# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin
OUTPUT_FILE = main

# Compile tags
G++ = g++ -Wall -O1 $(SOURCE_FOLDER)

run: build
	@mkdir bin/
	@clear
	@./bin/main

clean: 
	rm -rf *.* $(OUTPUT_FOLDER)/

build:
	$(G++)/*.cpp -o $(OUTPUT_FOLDER)/$(OUTPUT_FILE)
