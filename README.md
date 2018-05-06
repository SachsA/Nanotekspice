Epitech, SECOND year Project. C++ Programming : Digital Electronics.

NanoTekSpice is a logic simulator that builds a graph (the nodes of which will be simulated digital electronic
components, inputs or outputs) from a configuration file, and injects values into that graph to get result.

To compile : make.

To recompile the project : make re.

To clean all : make fclean.

To use the nanotekspice : ./nanotekspice [YOUR_FILE].nts

--> Optionnaly you can set the value of every inputs in your file
Example:

./nanotekspice Tests/Files/5input_nor.nts a=1 b=0

After that you'll be in a basic shell, there you can do a lot of things :
->Assign a value to an input : b=1 for example.
->"simulate" : launch the simulation of all the inputs.
->"loop": runs simulate without displaying a prompt, until SIGINT is received (CTRL + c).
->"exit": exit the programm.
->"dump": calls dump of every component.
->"display": display the values of the outputs (ASCII order)

In the folder : "Tests/Files/"
-> You'll find a lot of tests files.

Group that make the project : Alexandre Sachs. Corentin Thomazeau. (Both in Epitech Bordeaux)
