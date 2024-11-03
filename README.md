# Libunit

A micro framework for unit tests.  
Developed as a 42 Berlin weekend rush project.  

## Usage

Directory `<routine_name>` containing test routine:  
	- `main` - calls all chosen launchers  
	- `<function_name>` subdirectory:  
		- Launcher: `<00_*>` - loads and runs tests for this function  
		- Tests: `<01_test_name>` - one test function per file in order of execution  
