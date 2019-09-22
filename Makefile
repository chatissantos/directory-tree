
# Link command:
dt: dt.o helpers/printDir.o helpers/printError.o helpers/printFileStat.o helpers/printHelp.o
	gcc dt.o helpers/printDir.o helpers/printError.o helpers/printFileStat.o helpers/printHelp.o -o dt

# Compilation commands:
%.o : %.c
	gcc -c $< -o $@

clean:
	rm -f *.o helpers/*.o
