# 21sh
Simple shell implementation.
Done with edhomme at school 42, the project is in the stats it was when corrected in april 2018.
## Implemented features:
* builtins: echo, cd, setenv, unsetenv, env, exit
* separation of commands with ';'
* pipes ' | '
* redirection '<', '>', '<<' and '>>'
* file descriptor aggregations
* quotes, double quotes and backslashes
* line edition: 
	- move cursor normaly, by word, to the end or begining of line, and on multiple line to edit the line at a specific location
	- select (Shift + arrow keys), copy (Ctrl + Y) and paste (Ctrl + P)
	- move in history with UP and DOWN
	- simple completion
